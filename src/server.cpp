#include <iostream>
#include "transport/serial.h"
#include "server/tcp_serial_server.h"

using OpenPST::Server::TcpSerialServer;
using OpenPST::Server::TcpSerialServerError;
using OpenPST::Transport::Serial;
using OpenPST::Transport::SerialError;

int main(int argc, char* argv[])
{
	if (argc > 2) {
		return 1;
	}

	try {
		Serial port(argv[1]);
		TcpSerialServer server(port);

		server.start("127.0.0.1", 613);

	} catch(TcpSerialServerError& e) {
		std::cout << "Server Error: " << e.what() << std::endl;
	} catch(SerialError& e) {
		std::cout << "Error opening serial device: " << e.what() << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
