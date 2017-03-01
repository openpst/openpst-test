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
* @file sahara_memory_debug_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_debug_request.h"

using namespace OpenPST::Qualcomm;

SaharaMemoryDebugRequest::SaharaMemoryDebugRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandMemoryDebug);
}

SaharaMemoryDebugRequest::~SaharaMemoryDebugRequest()
{

}

uint32_t SaharaMemoryDebugRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void SaharaMemoryDebugRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint32_t SaharaMemoryDebugRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaMemoryDebugRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaMemoryDebugRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
}
void SaharaMemoryDebugRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaMemoryReadRequest* resp = new SaharaMemoryReadRequest();
		response = resp;
	}
}
