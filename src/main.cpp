#include <iostream>
#include <type_traits>
#include "serial/packet.h"
#include "serial/serial_queue.h"
#include "qualcomm/packet/streaming_dload_hello_request.h"
#include "qualcomm/packet/sahara_hello_request.h"
#include "qualcomm/packet/sahara_hello_response.h"
#include "util/hexdump.h"
#include <fstream>

using namespace OpenPST::Serial;
using namespace OpenPST::QC;

int main(int argc, char* argv[])
{
	SerialQueue sq;

	SaharaHelloRequest packet;
	packet.setCommand(0x00000002);
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

	std::cout << packet.size() << " " << packet.getSize() << std::endl;
	return 0;
}
