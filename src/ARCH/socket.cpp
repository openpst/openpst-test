#include <iostream>
#include "transport/tcp_serial_client.h"

using OpenPST::Transport::TcpSerialClient;
using OpenPST::Transport::TcpError;

int main(int argc, char* argv[])
{
	if (argc > 3) {
		std::cout << "program [hostname] [port]" << std::endl;
		return 1;
	}

	try {
		TcpSerialClient socket;
		
		socket.connect(argv[1], std::strtoul(argv[2], nullptr, 10));
		
		//usleep(1000000 * 60);

		socket.disconnect();

	} catch (TcpError& e) {
		std::cout << "TcpError: "  << e.what() << std::endl;
		return 0;
	} catch (std::exception& e) {
		std::cout << "STD: " << e.what() << std::endl;
		return 0;
	} catch (...) {
		std::cout << "Unhandled" << std::endl;
		return 0;
	}
	return 0;
}
