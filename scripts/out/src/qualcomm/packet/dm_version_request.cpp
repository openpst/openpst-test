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
* @file dm_version_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_version_request.h"

using namespace OpenPST::QC;

DmVersionRequest::DmVersionRequest(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("version", kPacketFieldTypePrimitive, sizeof(uint16_t));

}

DmVersionRequest::~DmVersionRequest()
{

}

uint16_t DmVersionRequest::getVersion()
{
    return read<uint16_t>(getFieldOffset("version"));
}
                
void DmVersionRequest::setVersion(uint16_t version)
{
    write<uint16_t>("version", version);
}

void DmVersionRequest::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}
