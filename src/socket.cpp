#include <iostream>
#include "transport/socket_client.h"

using OpenPST::Transport::SocketClient;
using OpenPST::Transport::SocketClientError;

int main(int argc, char* argv[])
{
	try {
		SocketClient socket;
		socket.connect("localhost", 5037);
		
		usleep(1000000 * 60);

		socket.disconnect();

	} catch (SocketClientError& e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "Unhandled" << std::endl;
	}
	return 0;
}
