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
		throw SerialPacketWriterError("Device not open");
	}

	packet->prepare();

#ifdef SERIAL_PACKET_WRITER_DEBUG_TX
	std::cout << "[SerialPacketWriter] Attempting to write " << packet->size() << " bytes" << std::endl;
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
		std::cout << __PRETTY_FUNCTION__ << std::endl << "Attempting to read " << response->getMaxDataSize() << " bytes" << std::endl;
#endif
		port.read(rbuffer, response->getMaxDataSize());
	
#ifdef SERIAL_PACKET_WRITER_DEBUG
		std::cout << __PRETTY_FUNCTION__ << std::endl << "Read " << rbuffer.size() << " bytes" << std::endl;

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
		throw SerialPacketWriterError("Device not open");
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