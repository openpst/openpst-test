#include <iostream>
#include <type_traits>
#include "serial/packet.h"
#include "serial/serial_packet_writer.h"
//#include "serial/mock_serial_packet_writer.h"
#include "serial/generic_serial.h"
//#include "serial/mock_serial.h"
#include "qualcomm/packet/streaming_dload_hello_request.h"
#include "qualcomm/packet/streaming_dload_hello_response.h"
#include "util/hexdump.h"
#include <fstream>

using namespace OpenPST::Serial;
using namespace OpenPST::QC;
using OpenPST::Serial::SerialError;

int main(int argc, char* argv[])
{
	

	try {
		GenericSerial port("/dev/ttyUSB0");

		SerialPacketWriter writer(port);

		StreamingDloadHelloRequest request;

		writer.write(&request);
		


	}catch (const SerialError& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	/*
	SerialQueue sq;

	SaharaHelloRequest packet;
	
	packet.setTargetEndianess(kPacketEndianessBig);

	std::cout << "Packet ending data: " << packet.size() << std::endl;

	hexdump((uint8_t*)&packet.getData()[0], packet.size());

	std::cout << std::endl;

 	packet.prepare();

    std::cout << "Prepared Data: " << packet.size() << std::endl;
    hexdump((uint8_t*)&packet.getData()[0], packet.size());

	for (auto &f : packet.getFields()) {
		std::cout << "\t" << f.name << " size: " << f.size << std::endl;
	}

	std::cout << std::endl; 

	std::cout << packet.size() << " " << packet.getSize() << std::endl;*/
	return 0;
}
