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
* @file dm_guid_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_guid_response.h"

using namespace OpenPST::Qualcomm;

DmGuidResponse::DmGuidResponse(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("guid", kPacketFieldTypeArray, 16);

}

DmGuidResponse::~DmGuidResponse()
{

}

std::vector<uint8_t> DmGuidResponse::getGuid()
{
	return read(getFieldSize("guid"), getFieldOffset("guid"));
}
std::string DmGuidResponse::getGuid()
{
	return getString(16, getFieldOffset("guid"));
}
                
void DmGuidResponse::setGuid(uint8_t* data, size_t size)
{
    write("guid", data, size);
}
void DmGuidResponse::setGuid(const std::string& guid)
{
    write("guid", guid);
}

void DmGuidResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmPacket::unpack(data, transport);
}
