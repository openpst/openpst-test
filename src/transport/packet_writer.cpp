/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file 
* @package 
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "transport/packet_writer.h"
#ifdef PACKET_WRITER_DEBUG
#include "util/hexdump.h"
#endif

using namespace OpenPST::Transport;

PacketWriter::PacketWriter(TransportInterface& transport) : 
transport(transport)
{

}


PacketWriter::~PacketWriter()
{
	
}

TransportInterface& PacketWriter::getTransport()
{
	return transport;
}

void PacketWriter::write(Packet* packet)
{
	if (!transport.isOpen()) {
		throw PacketWriterError("Transport not open");
	}

	packet->prepare();

#ifdef PACKET_WRITER_DEBUG_TX
	std::cout << "[PacketWriter] Attempting to write " << packet->size() << " bytes" << std::endl;
	hexdump((uint8_t*)&packet->getData()[0], packet->size());
#endif

	transport.write(packet->getData());

	if (packet->isResponseExpected()) {
		
		packet->prepareResponse();

		std::vector<uint8_t> rbuffer;

		Packet* response = packet->getResponse();

		if (response == nullptr) {
			throw PacketWriterError("Response packet has not been allocated");
		}
		
#ifdef PACKET_WRITER_DEBUG
		std::cout << __PRETTY_FUNCTION__ << std::endl << "Attempting to read " << response->getMaxDataSize() << " bytes" << std::endl;
#endif
		transport.read(rbuffer, response->getMaxDataSize());
	
#ifdef PACKET_WRITER_DEBUG
		std::cout << __PRETTY_FUNCTION__ << std::endl << "Read " << rbuffer.size() << " bytes" << std::endl;

		hexdump((uint8_t*)&rbuffer[0], rbuffer.size());

		if (transport.available()) {
			std::cout << transport.available() << " bytes of data is still waiting to be read!" << std::endl;
		}
#endif
		response->unpack(rbuffer, &transport);
	}
}

void PacketWriter::read(Packet* packet)
{

	if (!transport.isOpen()) {
		throw PacketWriterError("Device not open");
	}

	std::vector<uint8_t> rbuffer;

	transport.read(rbuffer, packet->getMaxDataSize());

	packet->unpack(rbuffer, &transport);

	if (packet->isResponseExpected()) {

		packet->prepareResponse();

		Packet* response = packet->getResponse();
		
		if (response == nullptr) {
			throw PacketWriterError("Response packet has not been allocated");
		}

		response->prepare();

		transport.write(response->getData());
	}
}