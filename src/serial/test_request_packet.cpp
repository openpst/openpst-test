#include "serial/test_request_packet.h"

using namespace OpenPST::Serial;

TestRequestPacket::TestRequestPacket() : RequestPacket()
{

}

TestRequestPacket::~TestRequestPacket()
{

}

std::vector<uint8_t> TestRequestPacket::pack() 
{
	std::vector<uint8_t> ret;

	return ret;
}