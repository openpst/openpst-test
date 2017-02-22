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
* @file sahara_memory_read64_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_read64_request.h"

using namespace OpenPST::Qualcomm;

SaharaMemoryRead64Request::SaharaMemoryRead64Request(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint64_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint64_t));

	setCommand(kSaharaCommandMemoryDebug64);
}

SaharaMemoryRead64Request::~SaharaMemoryRead64Request()
{

}

uint64_t SaharaMemoryRead64Request::getAddress()
{
    return read<uint64_t>(getFieldOffset("address"));
}
                
void SaharaMemoryRead64Request::setAddress(uint64_t address)
{
    write<uint64_t>("address", address);
}
uint64_t SaharaMemoryRead64Request::getSize()
{
    return read<uint64_t>(getFieldOffset("size"));
}
                
void SaharaMemoryRead64Request::setSize(uint64_t size)
{
    write<uint64_t>("size", size);
}

void SaharaMemoryRead64Request::unpack(std::vector<uint8_t>& data)
{
}
