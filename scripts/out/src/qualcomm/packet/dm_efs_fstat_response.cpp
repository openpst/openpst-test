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
* @file dm_efs_fstat_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_fstat_response.h"

using namespace OpenPST::Qualcomm;

DmEfsFstatResponse::DmEfsFstatResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("link_count", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("atime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mtime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("ctime", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsFstat);
}

DmEfsFstatResponse::~DmEfsFstatResponse()
{

}

uint32_t DmEfsFstatResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsFstatResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
uint32_t DmEfsFstatResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void DmEfsFstatResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
uint32_t DmEfsFstatResponse::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void DmEfsFstatResponse::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}
uint32_t DmEfsFstatResponse::getLinkCount()
{
    return read<uint32_t>(getFieldOffset("link_count"));
}
                
void DmEfsFstatResponse::setLinkCount(uint32_t linkCount)
{
    write<uint32_t>("link_count", linkCount);
}
uint32_t DmEfsFstatResponse::getAtime()
{
    return read<uint32_t>(getFieldOffset("atime"));
}
                
void DmEfsFstatResponse::setAtime(uint32_t atime)
{
    write<uint32_t>("atime", atime);
}
uint32_t DmEfsFstatResponse::getMtime()
{
    return read<uint32_t>(getFieldOffset("mtime"));
}
                
void DmEfsFstatResponse::setMtime(uint32_t mtime)
{
    write<uint32_t>("mtime", mtime);
}
uint32_t DmEfsFstatResponse::getCtime()
{
    return read<uint32_t>(getFieldOffset("ctime"));
}
                
void DmEfsFstatResponse::setCtime(uint32_t ctime)
{
    write<uint32_t>("ctime", ctime);
}

void DmEfsFstatResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
}
