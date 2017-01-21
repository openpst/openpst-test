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

bool Packet::getResponseExpected()
{
	return responseExpected;
}

void setResponseExpected(bool v)
{
	responseExpected = v;
}

Packet* Packet::getResponse() {
	return response;
}

template <class T> T Packet::swap(T i)
{
	// don't flip a byte or anything greater than uint64_t
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

template <class T> T Packet::read(int offset)
{
	if (offset > data.size() || offset + sizeof(T) > data.size()) {
		throw std::out_of_range("Attempted to read outside of the packet data buffer");
	}

	return reinterpret_cast<T>(*(&data[offset]));
}


template <class T> void Packet::write(T value, int offset)
{
	if (data.size() < offset + sizeof(T)) {
		data.reserve(data.size() + (data.size() - offset) + sizeof(T));
	}

	std::copy(&value, ((&value) + sizeof(T)), data[offset]);
}


void Packet::write(uint8_t* src, size_t amount, int offset)
{

}