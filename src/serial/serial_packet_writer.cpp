#include "serial/serial_packet_writer.h"

using namespace OpenPST::Serial;

SerialPacketWriter::SerialPacketWriter(const std::string& port, int baudRate, int timeout) : 
port(port, 115200, 1000)
{

}

SerialPacketWriter::~SerialPacketWriter()
{
	
}

GenericSerial& SerialPacketWriter::getPort()
{

}

void SerialPacketWriter::write(Packet* packet)
{

	if (!port.isOpen()) {
		try {
			port.open();
		} catch(...) {

		}
	}

	packet->validate();

	packet->prepare();

	port.write(packet->getData());

	if (packet->isResponseExpected()) {
		std::vector<uint8_t> response;

		read(response, 1024);
//		port.read(response, packet->getExpectedResponseSize());

		packet->unpack(response);
	}
}

void SerialPacketWriter::read(Packet* packet, size_t size)
{

	if (!port.isOpen()) {
		try {
			port.open();
		} catch(...) {

		}
	}

	std::vector<uint8_t> response;

	port.read(response, size);
//		port.read(response, packet->getExpectedResponseSize());

	packet->unpack(response);
}