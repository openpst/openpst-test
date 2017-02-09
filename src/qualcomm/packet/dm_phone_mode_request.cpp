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
* @file dm_phone_mode_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_phone_mode_request.h"

using namespace OpenPST::QC;

DmPhoneModeRequest::DmPhoneModeRequest(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("padding", kPacketFieldTypePrimitive, sizeof(uint8_t));

}

DmPhoneModeRequest::~DmPhoneModeRequest()
{

}

uint8_t DmPhoneModeRequest::getMode()
{
    return read<uint8_t>(getFieldOffset("mode"));
}
                
void DmPhoneModeRequest::setMode(uint8_t mode)
{
    write<uint8_t>("mode", mode);
}
uint8_t DmPhoneModeRequest::getPadding()
{
    return read<uint8_t>(getFieldOffset("padding"));
}
                
void DmPhoneModeRequest::setPadding(uint8_t padding)
{
    write<uint8_t>("padding", padding);
}

void DmPhoneModeRequest::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}
