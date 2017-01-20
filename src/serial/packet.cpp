#include "serial/packet.h"

using namespace OpenPST::Serial;

Packet::Packet(PacketEndianess endianT, PacketEndianess endianH) : 
	endianT(endianT), 
	endianH(endianH) 
{

}

Packet::~Packet(){
	if (response != nullptr) {
		delete response;
	}
}

void Packet::setTargetEndianess(PacketEndianess e) {
	endianT = e;
}

PacketEndianess Packet::getTargetEndianess() {
	return endianT;
}

void Packet::setHostEndianess(PacketEndianess e) {
	endianH = e;
}

PacketEndianess Packet::getHostEndianess() {
	return endianH;
}

bool Packet::isSent() {
	return sent;
}

void Packet::setSent(bool s) {
	sent = s;
}

Packet* Packet::getResponse() {
	return response;
}

template <class T> T Packet::swap(T i)
{
	// don't flip a byte
	// don't flip anything greater than uint64_t
	if (sizeof(T) > sizeof(uint64_t) || sizeof(T) == sizeof(uint8_t)) {
		return i;
	}

	T ret = i;

	std::reverse(
		reinterpret_cast<unsigned char*>(&ret), 
		reinterpret_cast<unsigned char*>(&ret) + sizeof(T)
	);
	return ret;
}