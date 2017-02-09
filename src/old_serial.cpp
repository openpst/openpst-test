#include <iostream>
#include <type_traits>
#include "serial/packet.h"
#include "serial/serial_packet_writer.h"
//#include "serial/mock_serial_packet_writer.h"
#include "serial/generic_serial.h"
//#include "serial/mock_serial.h"
//#include "qualcomm/packet/streaming_dload_hello_request.h"
//#include "qualcomm/packet/streaming_dload_hello_response.h"
//#include "qualcomm/packet/streaming_dload_security_mode_request.h"
//#include "qualcomm/packet/streaming_dload_security_mode_response.h"
//#include "qualcomm/packet/streaming_dload_open_multi_image_request.h"
//#include "qualcomm/packet/streaming_dload_open_multi_image_response.h"
#include "qualcomm/streaming_dload.h"
#include "util/hexdump.h"
#include <fstream>
#include <stdint.h>

using namespace OpenPST::Serial;
//using namespace OpenPST::QC;
using OpenPST::Serial::SerialError;
/*
void hello(SerialPacketWriter& writer) {
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

void set_security_mode(SerialPacketWriter& writer, bool trusted)
{
	StreamingDloadSecurityModeRequest request;
	
	request.setMode(trusted ? kStreamingDloadSecurityModeTrusted : kStreamingDloadSecurityModeUntrusted);

	writer.write(&request);

	std::cout << "Security mode set to " << (trusted ? "Trusted" : "Untrusted") << std::endl;
}

void open_multi(SerialPacketWriter& writer, uint8_t type)
{
	StreamingDloadOpenMultiImageRequest request;
	
	request.setType(type);

	writer.write(&request);

	std::cout << "Opened Multi Image 0x" << std::hex << type << std::endl;

}*/

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Device path missing" << std::endl;
		return 1;
	}

	try {
		GenericSerial port(argv[1], 1152000, 100);

		std::cout << "Baud: " << port.getBaudrate() << std::endl;
		std::cout << "ByteSize: " << port.getBytesize() << std::endl;
		std::cout << "Parity: " << port.getParity() << std::endl;
		std::cout << "Stop Bits: " << port.getStopbits() << std::endl;
		std::cout << "Flow: " << port.getFlowcontrol() << std::endl;
		/*std::cout << "[+] Connected to " << argv[1] << std::endl;

		SerialPacketWriter writer(port);
		
		hello(writer);
		set_security_mode(writer, true);
		open_multi(writer, kStreamingDloadOpenModeMultiGpp1);*/

	}catch (const SerialError& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
