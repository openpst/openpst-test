#include <iostream>
#include <type_traits>
#include "serial/packet.h"
#include "serial/serial_queue.h"
#include "qualcomm/packet/streaming_dload_hello_request.h"
#include "util/hexdump.h"
#include <fstream>

using namespace OpenPST::Serial;
using namespace OpenPST::QC;

int main(int argc, char* argv[])
{
	SerialQueue sq;

	StreamingDloadHelloRequest packet;
	
	std::cout << "Packet ending data: " << packet.size() << std::endl;

	hexdump((uint8_t*)&packet.getData()[0], packet.size());

	std::cout << std::endl; 

	std::cout << "Try read string" << std::endl;
	std::cout << packet.getMagic() << std::endl;

	packet.prepare();

    std::cout << "Encoded Data: " << packet.size() << std::endl;
    hexdump((uint8_t*)&packet.getData()[0], packet.size());

	for (auto &f : packet.getFields()) {
		std::cout << "\t" << f.name << " size: " << f.size << std::endl;
	}

	std::cout << std::endl; 

	return 0;
}
