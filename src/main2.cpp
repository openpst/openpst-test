#include "transport/serial.h"
#include "transport/serial_packet_writer.h"
#include "qualcomm/packet/streaming_dload_hello_request.h"
#include "qualcomm/packet/streaming_dload_hello_response.h"
#include <iostream>

using OpenPST::Transport::Serial;
using OpenPST::Transport::SerialPacketWriter;
using OpenPST::Transport::SerialError;
using OpenPST::Transport::PacketError;
using OpenPST::QC::StreamingDloadHelloRequest;
using OpenPST::QC::StreamingDloadHelloResponse;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Provide device as argument" << std::endl;
		return 1;
	}

	try {
		Serial port("", 1152000, 10);
		SerialPacketWriter writer(port);

		port.setDevice(argv[1]);
		port.open();
std::cout << port.getBaudRate() << std::endl;

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

	} catch (SerialError& e) {
		std::cout << e.what() << std::endl;
	} catch (PacketError& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
