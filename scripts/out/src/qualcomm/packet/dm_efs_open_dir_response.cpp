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
* @file dm_efs_open_dir_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_open_dir_response.h"

using namespace OpenPST::Qualcomm;

DmEfsOpenDirResponse::DmEfsOpenDirResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsOpenDir);
}

DmEfsOpenDirResponse::~DmEfsOpenDirResponse()
{

}

uint32_t DmEfsOpenDirResponse::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                
void DmEfsOpenDirResponse::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}
uint32_t DmEfsOpenDirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsOpenDirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsOpenDirResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
}
