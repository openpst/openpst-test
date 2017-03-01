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
* @file dm_efs_shred_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_shred_response.h"

using namespace OpenPST::Qualcomm;

DmEfsShredResponse::DmEfsShredResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("results", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsShred);
}

DmEfsShredResponse::~DmEfsShredResponse()
{

}

uint16_t DmEfsShredResponse::getSequence()
{
    return read<uint16_t>(getFieldOffset("sequence"));
}
                
void DmEfsShredResponse::setSequence(uint16_t sequence)
{
    write<uint16_t>("sequence", sequence);
}
uint16_t DmEfsShredResponse::getResults()
{
    return read<uint16_t>(getFieldOffset("results"));
}
                
void DmEfsShredResponse::setResults(uint16_t results)
{
    write<uint16_t>("results", results);
}
uint32_t DmEfsShredResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsShredResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsShredResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
}
