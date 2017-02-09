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
* @file sahara_hello_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_hello_request.h"

using namespace OpenPST::QC;

SaharaHelloRequest::SaharaHelloRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("min_version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_command_packet_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("status", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("reserved", kPacketFieldTypeArray, 24);
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandHello);
}

SaharaHelloRequest::~SaharaHelloRequest()
{

}

uint32_t SaharaHelloRequest::getVersion()
{
    return read<uint32_t>(getFieldOffset("version"));
}
                
void SaharaHelloRequest::setVersion(uint32_t version)
{
    write<uint32_t>("version", version);
}
uint32_t SaharaHelloRequest::getMinVersion()
{
    return read<uint32_t>(getFieldOffset("min_version"));
}
                
void SaharaHelloRequest::setMinVersion(uint32_t minVersion)
{
    write<uint32_t>("min_version", minVersion);
}
uint32_t SaharaHelloRequest::getMaxCommandPacketSize()
{
    return read<uint32_t>(getFieldOffset("max_command_packet_size"));
}
                
void SaharaHelloRequest::setMaxCommandPacketSize(uint32_t maxCommandPacketSize)
{
    write<uint32_t>("max_command_packet_size", maxCommandPacketSize);
}
uint32_t SaharaHelloRequest::getStatus()
{
    return read<uint32_t>(getFieldOffset("status"));
}
                
void SaharaHelloRequest::setStatus(uint32_t status)
{
    write<uint32_t>("status", status);
}
std::vector<uint8_t> SaharaHelloRequest::getReserved()
{
	return read(getFieldSize("reserved"), getFieldOffset("reserved"));
}
                
void SaharaHelloRequest::setReserved(uint8_t* data, size_t size)
{
    write("reserved", data, size);
}
uint32_t SaharaHelloRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void SaharaHelloRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}

void SaharaHelloRequest::unpack(std::vector<uint8_t>& data)
{
}
void SaharaHelloRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaHelloResponse* resp = new SaharaHelloResponse();
		response = resp;
	}
}
