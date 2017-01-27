#include "serial/serial_packet_writer.h"

using namespace OpenPST::Serial;

SerialPacketWriter::SerialPacketWriter(GenericSerial& port) : 
port(port)
{

}


SerialPacketWriter::~SerialPacketWriter()
{
	
}

GenericSerial& SerialPacketWriter::getPort()
{
	return port;
}

void SerialPacketWriter::write(Packet* packet)
{

	if (!port.isOpen()) {
		try {
			port.open();
		} catch(...) {
			// throw
		}
	}

	packet->validate();

	packet->prepare();

	port.write(packet->getData());

	if (packet->isResponseExpected()) {
		
		packet->prepareResponse();

		std::vector<uint8_t> rbuffer;

		Packet* response = packet->getResponse();

		if (response == nullptr) {
			throw std::runtime_error("Response packet has not been allocated");
		}

		port.read(rbuffer, response->getMaxDataSize());

		if (port.available()) {
			std::cerr << port.available() << " bytes of data is still waiting to be read!" << std::endl;
		}

		response->unpack(rbuffer);
	}
}

void SerialPacketWriter::read(Packet* packet, size_t size)
{

	if (!port.isOpen()) {
		try {
			port.open();
		} catch(...) {
			// throw
		}
	}

	std::vector<uint8_t> rbuffer;

	port.read(rbuffer, packet->getMaxDataSize());

	packet->unpack(rbuffer);
}