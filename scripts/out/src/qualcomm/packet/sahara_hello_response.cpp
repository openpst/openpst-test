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
* @file sahara_hello_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_hello_response.h"

using namespace OpenPST::Qualcomm;

SaharaHelloResponse::SaharaHelloResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("min_version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("status", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("reserved", kPacketFieldTypeArray, (sizeof(uint32_t) * 6));

	setCommand(kSaharaCommandHelloResponse);
}

SaharaHelloResponse::~SaharaHelloResponse()
{

}

uint32_t SaharaHelloResponse::getVersion()
{
    return read<uint32_t>(getFieldOffset("version"));
}
                
void SaharaHelloResponse::setVersion(uint32_t version)
{
    write<uint32_t>("version", version);
}
uint32_t SaharaHelloResponse::getMinVersion()
{
    return read<uint32_t>(getFieldOffset("min_version"));
}
                
void SaharaHelloResponse::setMinVersion(uint32_t minVersion)
{
    write<uint32_t>("min_version", minVersion);
}
uint32_t SaharaHelloResponse::getStatus()
{
    return read<uint32_t>(getFieldOffset("status"));
}
                
void SaharaHelloResponse::setStatus(uint32_t status)
{
    write<uint32_t>("status", status);
}
uint32_t SaharaHelloResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void SaharaHelloResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
std::vector<uint8_t> SaharaHelloResponse::getReserved()
{
	return read(getFieldSize("reserved"), getFieldOffset("reserved"));
}
                
void SaharaHelloResponse::setReserved(uint8_t* data, size_t size)
{
    write("reserved", data, size);
}

void SaharaHelloResponse::unpack(std::vector<uint8_t>& data)
{
}
