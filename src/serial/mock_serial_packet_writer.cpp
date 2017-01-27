#include "serial/serial_packet_writer.h"

using namespace OpenPST::Serial;

MockSerialPacketWriter::MockSerialPacketWriter(MockSerial& port) : 
port(port)
{

}


MockSerialPacketWriter::~MockSerialPacketWriter()
{
	
}

MockSerial& MockSerialPacketWriter::getPort()
{
	return port;
}

void MockSerialPacketWriter::write(Packet* packet)
{

	if (!port.isOpen()) {
		try {
			port.open();

		} catch(...) {
			// throw
		}
	}


	packet->prepare();

	port.write(packet->getData());

	if (packet->isResponseExpected()) {
		
		packet->prepareResponse();

		std::vector<uint8_t> rbuffer;

		Packet* response = packet->getResponse();

		if (response == nullptr) {
			throw MockSerialPacketWriterError("Response packet has not been allocated");
		}

		port.read(rbuffer, response->getMaxDataSize());

		if (port.available()) {
			std::cerr << port.available() << " bytes of data is still waiting to be read!" << std::endl;
		}

		response->unpack(rbuffer);
	}
}

void MockSerialPacketWriter::read(Packet* packet)
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

	if (packet->isResponseExpected()) {

		packet->prepareResponse();

		Packet* response = packet->getResponse();

		if (response == nullptr) {
			throw MockSerialPacketWriterError("Response packet has not been allocated");
		}

		response->prepare();

		port.write(response->getData());
	}
}