#include "transport/serial.h"
//#include "transport/async_serial.h"
//#include "transport/messaged_serial.h"
//#include "transport/messaged_async_serial.h"
//#include "server/tcp_serial_server.h"
#include "qualcomm/sahara_client.h"
#include "qualcomm/streaming_dload_client.h"
//#include "qualcomm/hdlc_encoder.h"
#include <iostream>
#include <fstream>
#include <time.h> 

using namespace OpenPST::Transport;
using namespace OpenPST::Qualcomm;
//using namespace OpenPST::QC;
#include <unistd.h>

int main_sahara(int argc, char* argv[])
{
	if (argc < 3) {
		std::cout << "Usage: program [device] [file]" << std::endl;
		return 1;
	}


	std::ifstream file(argv[2], std::ios::in | std::ios::binary);

	if (!file.is_open()) {
		std::cout << "Could not open " << argv[2] << " for reading" << std::endl;
		return 1;
	}

	// settings
	bool getHostInfo = false;

	try {

		Serial port(argv[1]);

		if (port.isOpen()) {
			std::cout << "Opened " << port.getDevice() << " - Data Waiting: " << port.available() << std::endl;
		}

		SaharaClient sClient(port);
		SaharaState state;

		if(getHostInfo) {
			SaharaHello hello = sClient.readHello();

			hello.mode = kSaharaModeCommand;

			state = sClient.sendHello(hello);

			auto hostInfo = sClient.getHostInfo();

			state = sClient.switchModeAndHello(state.initialMode);

		} else {
			state = sClient.hello();
		}

		if (state.mode == kSaharaModeImageTxPending) {

			std::cout << "Device in kSaharaModeImageTxPending" << std::endl;

			SaharaImageRequestInfo imageInfo;

			if (state.lastImageRequest.imageId) {
				std::cout << "Using Stored Request" << std::endl;
				imageInfo = state.lastImageRequest;
			} else {
				std::cout << "Reading New Request" << std::endl;
				imageInfo = sClient.readNextImageOffset();
			}

			std::cout << "Device requesting image 0x" << std::hex << state.lastImageRequest.imageId;
			std::cout << ". Requesting " << std::dec <<  imageInfo.size << " bytes from offset " << imageInfo.offset << std::endl;

			SaharaImageRequestInfo nextImageInfo = sClient.sendImage(argv[2], imageInfo);

			if (nextImageInfo.imageId) {
				// handle next image
			}

			std::cout << "DONE!" << std::endl;
			
			sClient.done();

			port.close();

		} else if (state.mode == kSaharaModeMemoryDebug) {
			std::cout << "kSaharaModeMemoryDebug" << std::endl;
		} else if (state.mode == kSaharaModeCommand) {
			std::cout << "kSaharaModeCommand" << std::endl;
		}

		std::cout << "EXITING" << std::endl;

		port.close();

	} catch (SaharaClientError& e) {		
		std::cout << "SaharaClientError: " << e.what() << std::endl;		
	} catch (SerialError& e) {
		std::cout << "SerialError: " << e.what() << std::endl;
	} catch (PacketError& e) {
		std::cout << "PacketError: " << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cout << "std::exception: " << e.what() << std::endl;
	} 

	return 0;
}

int main_streaming_dload(int argc, char* argv[]) {

	//usleep(1000000 * 1);

	try {

		Serial port(argv[1]);

		if (port.isOpen()) {
			std::cout << "Opened " << port.getDevice() << " - Data Waiting: " << port.available() << std::endl;
		}
		
		StreamingDloadClient sdClient(port);

		StreamingDloadDeviceInfo sdHello = sdClient.hello();

		std::cout << "[!] Version: " 			 << (int)sdHello.version << std::endl;
		std::cout << "[!] Compatible Version: "  << (int)sdHello.compatibleVersion << std::endl;
		std::cout << "[!] Preferred Block Size " << sdHello.maxPreferredBlockSize << std::endl;
		std::cout << "[!] Base Flash Address "   << sdHello.baseFlashAddress << std::endl;
		std::cout << "[!] Flash ID " 			 << sdHello.flashId << std::endl;
		
		if (sdHello.featureBits & STREAMING_DLOAD_FEATURE_BIT_UNCOMPRESSED_DOWNLOAD) {
			std::cout << "[!] Device requires an uncompressed download" << std::endl;
		}

		if (sdHello.featureBits & STREAMING_DLOAD_FEATURE_BIT_NAND_BOOTABLE_IMAGE) {
			std::cout << "[!] Device features NAND Bootable Image" << std::endl;
		}

		if (sdHello.featureBits & STREAMING_DLOAD_FEATURE_BIT_NAND_BOOT_LOADER) {
			std::cout << "[!] Device features NAND Bootloader" << std::endl;
		}

		if (sdHello.featureBits & STREAMING_DLOAD_FEATURE_BIT_MULTI_IMAGE) {
			std::cout << "[!] Supports multi-image" << std::endl;
		}

		if (sdHello.featureBits & STREAMING_DLOAD_FEATURE_BIT_SECTOR_ADDRESSES) {
			std::cout << "[!] Device features sector addresses" << std::endl;
		}

	} catch (SaharaClientError& e) {		
		std::cout << "SaharaClientError: " << e.what() << std::endl;		
	} catch (SerialError& e) {
		std::cout << "SerialError: " << e.what() << std::endl;
	} catch (PacketError& e) {
		std::cout << "PacketError: " << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cout << "std::exception: " << e.what() << std::endl;
	} 
}

int main(int argc, char* argv[])
{
	//if (main_sahara(argc, argv)) {
	//	return 1;
	//}

	main_streaming_dload(argc, argv);

	/*if (argc < 2) {
		std::cout << "Provide device as argument" << std::endl;
		return 1;
	}

	std::string atDelim = "\r\n";
	std::string hdlcDelim;
	hdlcDelim.push_back(HDLC_CONTROL_CHAR);
	time_t stime;
	time_t etime;
	
	time(&stime);
		
	try {
		Serial port(argv[1]);
		//MessagedSerial port(argv[1], atDelim);
		//MessagedSerial port(argv[1], hdlcDelim);
		//MessagedAsynSerial port(argv[1], atDelim);
		//MessagedAsynSerial port(argv[1], hdlcDelim);


		PacketWriter writer(port);

		if (port.isOpen()) {
			std::cout << "Opened " << port.getDevice() << std::endl;
		}

		//hello(port, writer, argc, argv);
		//security_mode(port, writer, argc, argv);
		//open_multi(port, writer, argc, argv);
		//read_emmc(port, writer, argc, argv);
		diag_test(port, writer, argc, argv);

	} catch (SerialError& e) {
		std::cout << e.what() << std::endl;
	} catch (PacketError& e) {
		std::cout << e.what() << std::endl;
	}

	time(&etime);
	std::cout << "Time: " << difftime(etime, stime) << std::endl;*/
}
