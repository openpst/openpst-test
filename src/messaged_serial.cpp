#include "transport/serial.h"
#include "transport/messaged_serial.h"
#include "transport/serial_packet_writer.h"
#include "qualcomm/streaming_dload.h"
#include "qualcomm/packet/streaming_dload_hello_request.h"
#include "qualcomm/packet/streaming_dload_security_mode_request.h"
#include "qualcomm/packet/streaming_dload_open_multi_image_request.h"
#include "qualcomm/packet/streaming_dload_read_request.h"
#include "qualcomm/packet/dm_spc_request.h"
#include "qualcomm/packet/dm_spc_response.h"
#include "qualcomm/hdlc_encoder.h"
#include <iostream>
#include <fstream>
#include <time.h> 

using namespace OpenPST::Transport;
using namespace OpenPST::QC;


void hello(MessagedSerial& port, int argc, char* argv[]) {
	StreamingDloadHelloRequest request;
	
	std::vector<uint8_t> test;

	request.prepare();

	port.write(request.getData());

	request.prepareResponse();

	auto response = reinterpret_cast<StreamingDloadHelloResponse*>(request.getResponse());

	port.read(test, 0);

	response->unpack(test);
	
	/*writer.write(&request);
	
	auto response = reinterpret_cast<StreamingDloadHelloResponse*>(request.getResponse());
	
	std::cout << "[!] Version: " 			 << (int)response->getVersion() << std::endl;
	std::cout << "[!] Compatible Version: "  << (int)response->getCompatibleVersion() << std::endl;
	std::cout << "[!] Preferred Block Size " << response->getPreferredBlockSize() << std::endl;
	std::cout << "[!] Base Flash Address "   << response->getBaseFlashAddress() << std::endl;
	std::cout << "[!] Flash ID " 			 << response->getFlashId() << std::endl;
	std::cout << "[!] Number of Sectors " 	 << response->getNumberOfSectors() << std::endl;
	std::cout << "[!] Feature Bits 0x" 		 << std::hex << (int)response->getFeatureBits() << std::endl;
	
	if (response->getFeatureBits() & STREAMING_DLOAD_FEATURE_BIT_UNCOMPRESSED_DOWNLOAD) {
		std::cout << "[!] Device requires an uncompressed download" << std::endl;
	}

	if (response->getFeatureBits() & STREAMING_DLOAD_FEATURE_BIT_NAND_BOOTABLE_IMAGE) {
		std::cout << "[!] Device features NAND Bootable Image" << std::endl;
	}

	if (response->getFeatureBits() & STREAMING_DLOAD_FEATURE_BIT_NAND_BOOT_LOADER) {
		std::cout << "[!] Device features NAND Bootloader" << std::endl;
	}

	if (response->getFeatureBits() & STREAMING_DLOAD_FEATURE_BIT_MULTI_IMAGE) {
		std::cout << "[!] Supports multi-image" << std::endl;
	}

	if (response->getFeatureBits() & STREAMING_DLOAD_FEATURE_BIT_SECTOR_ADDRESSES) {
		std::cout << "[!] Device features sector addresses" << std::endl;
	}*/
}


int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Provide device as argument" << std::endl;
		return 1;
	}

	try {
		std::string delim;
		delim.push_back(HDLC_CONTROL_CHAR);

		MessagedSerial port(argv[1], delim);

		if (port.isOpen()) {
			std::cout << "Opened " << port.getDevice() << std::endl;
		}

		hello(port, argc, argv);

	} catch (SerialError& e) {
		std::cout << e.what() << std::endl;
	} catch (PacketError& e) {
		std::cout << e.what() << std::endl;
	}
}
