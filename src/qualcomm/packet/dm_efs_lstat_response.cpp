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
* @file dm_efs_lstat_response.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_lstat_response.h"

using namespace OpenPST::Qualcomm;

DmEfsLstatResponse::DmEfsLstatResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("atime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mtime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("ctime", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsLstat);

	setResponseExpected(false);
}

DmEfsLstatResponse::~DmEfsLstatResponse()
{

}

uint32_t DmEfsLstatResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                

void DmEfsLstatResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

uint32_t DmEfsLstatResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                

void DmEfsLstatResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}

uint32_t DmEfsLstatResponse::getAtime()
{
    return read<uint32_t>(getFieldOffset("atime"));
}
                

void DmEfsLstatResponse::setAtime(uint32_t atime)
{
    write<uint32_t>("atime", atime);
}

uint32_t DmEfsLstatResponse::getMtime()
{
    return read<uint32_t>(getFieldOffset("mtime"));
}
                

void DmEfsLstatResponse::setMtime(uint32_t mtime)
{
    write<uint32_t>("mtime", mtime);
}

uint32_t DmEfsLstatResponse::getCtime()
{
    return read<uint32_t>(getFieldOffset("ctime"));
}
                

void DmEfsLstatResponse::setCtime(uint32_t ctime)
{
    write<uint32_t>("ctime", ctime);
}

void DmEfsLstatResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setError(read<uint32_t>(data, getFieldOffset("error")));
	setMode(read<uint32_t>(data, getFieldOffset("mode")));
	setAtime(read<uint32_t>(data, getFieldOffset("atime")));
	setMtime(read<uint32_t>(data, getFieldOffset("mtime")));
	setCtime(read<uint32_t>(data, getFieldOffset("ctime")));
}
