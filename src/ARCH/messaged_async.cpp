#include "transport/serial.h"
#include "transport/messaged_async_serial.h"
#include <iostream>
#include <sstream>
#include <vector>

using OpenPST::Transport::MessagedAsyncSerial;
using OpenPST::Transport::SerialError;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Provide device as argument" << std::endl;
		return 1;
	}

	try {
		MessagedAsyncSerial port(argv[1], "\r\n", 115200, 1000);

		if (port.isOpen()) {
			std::cout << "Opened " << port.getDevice() << std::endl;
		}

		std::cout << "Start entering AT Commands" << std::endl;
		
		std::string cmd;
		std::vector<uint8_t> rxbuff;
		std::vector<uint8_t> txbuff;
		for(;;) {
			std::getline(std::cin, cmd);
			txbuff.insert(txbuff.begin(), cmd.begin(), cmd.end());
			txbuff.push_back('\r');
			txbuff.push_back('\n');

    		port.write(txbuff);
        	
    		//port.read(rxbuff, 1024);
        	cmd.clear();
        	txbuff.clear();
        	rxbuff.clear();
		}

	} catch (SerialError& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	return 0;
}