#include "transport/serial.h"
#include <iostream>

using OpenPST::Transport::Serial;
using OpenPST::Transport::SerialError;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Provide device as argument" << std::endl;
		return 1;
	}
	
	Serial s("", 115200, 1000);

	try {
		s.setDevice(argv[1]);
		s.open();
	} catch (SerialError& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
