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
* @file dm_efs_md5_sum_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_md5_sum_response.h"

using namespace OpenPST::Qualcomm;

DmEfsMd5SumResponse::DmEfsMd5SumResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("hash", kPacketFieldTypeArray, 16);

	setSubsysCommand(kDiagEfsMd5Sum);
}

DmEfsMd5SumResponse::~DmEfsMd5SumResponse()
{

}

uint16_t DmEfsMd5SumResponse::getSequence()
{
    return read<uint16_t>(getFieldOffset("sequence"));
}
                
void DmEfsMd5SumResponse::setSequence(uint16_t sequence)
{
    write<uint16_t>("sequence", sequence);
}
uint32_t DmEfsMd5SumResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsMd5SumResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
std::vector<uint8_t> DmEfsMd5SumResponse::getHash()
{
	return read(getFieldSize("hash"), getFieldOffset("hash"));
}
                
void DmEfsMd5SumResponse::setHash(uint8_t* data, size_t size)
{
    write("hash", data, size);
}

void DmEfsMd5SumResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
}
