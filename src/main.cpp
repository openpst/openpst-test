#include <iostream>
#include <type_traits>
#include "serial/packet.h"
#include "serial/serial_queue.h"
#include "serial/packet_test.h"
#include "util/hexdump.h"

using namespace OpenPST::Serial;

int main(int argc, char* argv[])
{
	SerialQueue sq;

	PacketTest packet;

	std::cout << "Packet defines the following fields:" std::endl;

	for (auto &f : packet.getFields()) {
		std::cout << "\t" << f.name << std::endl;
	}

	PacketFieldMeta* t = packet.getField("command");
	
	std::cout << "Packet ending data:" << std::endl;

	hexdump((uint8_t*)&packet.getData()[0], packet.getData().size());

	std::cout << packet.getMagic() << std::endl;

	hexdump((uint8_t*)&packet.data[0], packet.getData().size());

	packet.prepare();

	return 0;
}
