#include <iostream>
#include "serial/serial_queue.h"
#include "serial/test_request_packet.h"

using OpenPST::Serial::SerialQueue;
using OpenPST::Serial::TestRequestPacket;

int main(int argc, char* argv[])
{
	SerialQueue sq;

	sq.add(new TestRequestPacket());
	sq.add(new TestRequestPacket());
	sq.add(new TestRequestPacket());

	return 0;
}