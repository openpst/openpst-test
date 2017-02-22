#include "transport/serial.h"
#include "transport/async_serial.h"
#include "transport/messaged_serial.h"
#include "transport/messaged_async_serial.h"

#include "server/tcp_serial_server.h"
//#include "transport/tcp_serial_client.h"

#include "transport/packet_writer.h"

#include "qualcomm/streaming_dload.h"
#include "qualcomm/packet/streaming_dload_hello_request.h"
#include "qualcomm/packet/streaming_dload_security_mode_request.h"
#include "qualcomm/packet/streaming_dload_open_multi_image_request.h"
#include "qualcomm/packet/streaming_dload_read_request.h"


#include "qualcomm/hdlc_encoder.h"
#include "qualcomm/packet/dm_spc_request.h"
#include "qualcomm/packet/dm_spc_response.h"

#include <iostream>
#include <fstream>
#include <time.h> 

using namespace OpenPST::Transport;
using namespace OpenPST::Qualcomm;
using namespace OpenPST::QC;


void hello(TransportInterface& interface, PacketWriter& writer, int argc, char* argv[]) {
	StreamingDloadHelloRequest request;
	
	writer.write(&request);
	
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
	}
}

void security_mode(TransportInterface& interface, PacketWriter& writer, int argc, char* argv[]) {
	StreamingDloadSecurityModeRequest request;
	
	request.setMode(kStreamingDloadSecurityModeUntrusted);

	writer.write(&request);
	
	auto response = reinterpret_cast<StreamingDloadSecurityModeResponse*>(request.getResponse());
}

void open_multi(TransportInterface& interface, PacketWriter& writer, int argc, char* argv[]) {
	StreamingDloadOpenMultiImageRequest request;
	
	request.setType(kStreamingDloadOpenModeMultiEmmcUser);

	writer.write(&request);
	
	auto response = reinterpret_cast<StreamingDloadOpenMultiImageResponse*>(request.getResponse());
}

void read_emmc(TransportInterface& interface, PacketWriter& writer, int argc, char* argv[]) {
	
	uint32_t startAddress = 0x00000000;
	uint32_t endAddress   = startAddress + (1024 * 1024 * 100);
	uint32_t currentAddress = startAddress;
	size_t readSize = 1024;

	std::string outFile("/home/ghassani/Desktop/read_emmc.out");
	
	std::ofstream file(outFile.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);

	if (!file.is_open()) {
		throw std::invalid_argument("Error opening file for writing");
	}

	std::cout << "Opened " << outFile << " for writing" << std::endl;

	size_t total = 0;
	time_t stime;
	time_t etime;

	time(&stime);

	try {
		while(currentAddress < endAddress) {
			StreamingDloadReadRequest request;
			request.setAddress(currentAddress);
			request.setLength(readSize);

			writer.write(&request);

			auto response = reinterpret_cast<StreamingDloadReadResponse*>(request.getResponse());

			auto data = response->getData();

			file.write(reinterpret_cast<char*>(&data[0]), data.size());

			currentAddress += readSize;
			total 		   += readSize;
		}
	} catch(...) {
		std::cout << "Error reading at address 0x" << std::hex << currentAddress << std::endl;
		std::cout << "Read " << total << " bytes from 0x" << std::hex << startAddress << std::endl;
		time(&etime);
		std::cout << "Time: " << difftime(etime, stime) << std::endl;
		file.close();
		throw;
	}

	file.close();
	
	std::cout << "Read " << total << " bytes from 0x" << std::hex << startAddress << std::endl;

	time(&etime);

	std::cout << "Time: " << difftime(etime, stime) << std::endl;
}

void diag_test(TransportInterface& interface, PacketWriter& writer, int argc, char* argv[]) {
	DmSpcRequest request;

	writer.write(&request);
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
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
	std::cout << "Time: " << difftime(etime, stime) << std::endl;
}
