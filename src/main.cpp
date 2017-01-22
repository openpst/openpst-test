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

	for (auto &f : packet.getFields()) {
		std::cout << f.name << std::endl;
	}

	PacketFieldMeta* t = packet.getField("command");
	

	hexdump((uint8_t*)&packet.getData()[0], packet.getData().size());

	std::cout << packet.getMagic() << std::endl;
	
	hexdump((uint8_t*)&packet.getData()[0], packet.getData().size());

	packet.prepare();


/*
    std::cout << "isPrimitiveType(Foo): " << std::boolalpha
        << isPrimitiveType(data) << std::endl;
    std::cout << "isPrimitiveType(int): " << std::boolalpha
        << isPrimitiveType(data.x) << std::endl;
    std::cout << "isPrimitiveType(char): " << std::boolalpha
        << isPrimitiveType(data.y) << std::endl;
    std::cout << "isPrimitiveType(unsigned long long): " << std::boolalpha
        << isPrimitiveType(data.z) << std::endl;
*/
	return 0;
}



/*template <class T>
inline bool isPrimitiveType(const T& data) {
    return std::is_fundamental<T>::value;
}*/