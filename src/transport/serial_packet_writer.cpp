#include "transport/serial_packet_writer.h"
#ifdef SERIAL_PACKET_WRITER_DEBUG
#include "util/hexdump.h"
#endif

using namespace OpenPST::Transport;

SerialPacketWriter::SerialPacketWriter(Serial& port) : 
port(port)
{

}


SerialPacketWriter::~SerialPacketWriter()
{
	
}

Serial& SerialPacketWriter::getPort()
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

	packet->prepare();

#ifdef SERIAL_PACKET_WRITER_DEBUG
	std::cout << "Attempting to write " << packet->size() << " bytes" << std::endl;
	hexdump((uint8_t*)&packet->getData()[0], packet->size());
#endif

	port.write(packet->getData());

	if (packet->isResponseExpected()) {
		
		packet->prepareResponse();

		std::vector<uint8_t> rbuffer;

		Packet* response = packet->getResponse();

		if (response == nullptr) {
			throw SerialPacketWriterError("Response packet has not been allocated");
		}

#ifdef SERIAL_PACKET_WRITER_DEBUG
		std::cout << "Attempting to read " << response->getMaxDataSize() << " bytes" << std::endl;
#endif
		port.read(rbuffer, response->getMaxDataSize());
	
#ifdef SERIAL_PACKET_WRITER_DEBUG
		std::cout << "Read " << rbuffer.size() << " bytes" << std::endl;

		hexdump((uint8_t*)&rbuffer[0], rbuffer.size());

		//if (port.available()) {
		//	std::cerr << port.available() << " bytes of data is still waiting to be read!" << std::endl;
		//}
#endif
		response->unpack(rbuffer);
	}
}

void SerialPacketWriter::read(Packet* packet)
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
			throw SerialPacketWriterError("Response packet has not been allocated");
		}

		response->prepare();

		port.write(response->getData());
	}
}