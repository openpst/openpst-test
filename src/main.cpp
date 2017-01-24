#include <iostream>
#include <type_traits>
#include "serial/packet.h"
#include "serial/serial_queue.h"
#include "serial/packet_test.h"
#include "util/hexdump.h"
#include <fstream>

using namespace OpenPST::Serial;

int main(int argc, char* argv[])
{
	SerialQueue sq;

	PacketTest packet;

	std::cout << "Packet defines the following fields:" << std::endl;

	for (auto &f : packet.getFields()) {
		std::cout << "\t" << f.name << " size: " << f.size << std::endl;
	}

	std::cout << std::endl;

	//PacketFieldMeta* t = packet.getField("command");
	std::ifstream fi("test/if_test.bin", std::ios::in | std::ios::binary);
	
	if (!fi.is_open()){
		std::cout << "Could not open file" << std:: endl;
	}

	//fi.exceptions ( std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit );

	packet.setDtest(fi, 122);
	
	std::cout << "Packet ending data: " << packet.size() << std::endl;

	hexdump((uint8_t*)&packet.getData()[0], packet.getData().size());

	/*std::cout << packet.getMagic() << std::endl;

	hexdump((uint8_t*)&packet.getData()[0], packet.getData().size());

	packet.prepare();*/


	for (auto &f : packet.getFields()) {
		std::cout << "\t" << f.name << " size: " << f.size << std::endl;
	}

	std::cout << std::endl; 

	return 0;
}
