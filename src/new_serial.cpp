#include "transport/serial.h"
#include "transport/serial_packet_writer.h"
#include "qualcomm/streaming_dload.h"
#include "qualcomm/packet/streaming_dload_hello_request.h"
#include "qualcomm/packet/streaming_dload_security_mode_request.h"
#include "qualcomm/packet/streaming_dload_open_multi_image_request.h"
#include "qualcomm/packet/streaming_dload_read_request.h"
#include "qualcomm/packet/dm_spc_request.h"
#include "qualcomm/packet/dm_spc_response.h"
#include <iostream>

using OpenPST::Transport::Serial;
using OpenPST::Transport::SerialPacketWriter;
using OpenPST::Transport::SerialError;
using OpenPST::Transport::PacketError;
using OpenPST::QC::StreamingDloadHelloRequest;
using OpenPST::QC::StreamingDloadHelloResponse;
using OpenPST::QC::StreamingDloadSecurityModeRequest;
using OpenPST::QC::StreamingDloadSecurityModeResponse;
using OpenPST::QC::StreamingDloadOpenMultiImageRequest;
using OpenPST::QC::StreamingDloadOpenMultiImageResponse;
using OpenPST::QC::DmSpcRequest;
using OpenPST::QC::DmSpcResponse;


void hello(Serial& port, SerialPacketWriter& writer, int argc, char* argv[]) {
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

void security_mode(Serial& port, SerialPacketWriter& writer, int argc, char* argv[]) {
	StreamingDloadSecurityModeRequest request;
	
	request.setMode(kStreamingDloadSecurityModeUntrusted);

	writer.write(&request);
	
	auto response = reinterpret_cast<StreamingDloadSecurityModeResponse*>(request.getResponse());
}

void open_multi(Serial& port, SerialPacketWriter& writer, int argc, char* argv[]) {
	StreamingDloadOpenMultiImageRequest request;
	
	request.setType(kStreamingDloadOpenModeMultiEmmcUser);

	writer.write(&request);
	
	auto response = reinterpret_cast<StreamingDloadOpenMultiImageResponse*>(request.getResponse());
}

void read_emmc(Serial& port, SerialPacketWriter& writer, int argc, char* argv[]) {
	
	uint32_t startAddress = 0x00000000;
	uint32_t endAddress   = startAddress + (1024 * 1024 * 5);
	uint32_t currentAddress = startAddress;
	size_t readSize = 1024;

	while(currentAddress < endAddress) {
		StreamingDloadReadRequest request;
		request.setAddress(currentAddress);
		request.setLength(readSize);

		writer.write(packet);

		currentAddress += readSize;
	}
	
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Provide device as argument" << std::endl;
		return 1;
	}

	try {
		Serial port(argv[1]);
		SerialPacketWriter writer(port);

		if (port.isOpen()) {
			std::cout << "Opened " << port.getDevice() << std::endl;
		}

		hello(port, writer, argc, argv);
		security_mode(port, writer, argc, argv);
		open_multi(port, writer, argc, argv);
		read_emmc(port, writer, argc, argv);

	} catch (SerialError& e) {
		std::cout << e.what() << std::endl;
	} catch (PacketError& e) {
		std::cout << e.what() << std::endl;
	}
}
