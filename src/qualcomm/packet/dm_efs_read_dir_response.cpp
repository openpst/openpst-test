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
* @file dm_efs_read_dir_response.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_read_dir_response.h"

using namespace OpenPST::Qualcomm;

DmEfsReadDirResponse::DmEfsReadDirResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("sequence_number", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("entry_type", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("atime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mtime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("ctime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("name", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsReadDir);

	setResponseExpected(false);
}

DmEfsReadDirResponse::~DmEfsReadDirResponse()
{

}

uint32_t DmEfsReadDirResponse::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                

void DmEfsReadDirResponse::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}

uint32_t DmEfsReadDirResponse::getSequenceNumber()
{
    return read<uint32_t>(getFieldOffset("sequence_number"));
}
                

void DmEfsReadDirResponse::setSequenceNumber(uint32_t sequenceNumber)
{
    write<uint32_t>("sequence_number", sequenceNumber);
}

uint32_t DmEfsReadDirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                

void DmEfsReadDirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

uint32_t DmEfsReadDirResponse::getEntryType()
{
    return read<uint32_t>(getFieldOffset("entry_type"));
}
                

void DmEfsReadDirResponse::setEntryType(uint32_t entryType)
{
    write<uint32_t>("entry_type", entryType);
}

uint32_t DmEfsReadDirResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                

void DmEfsReadDirResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}

uint32_t DmEfsReadDirResponse::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                

void DmEfsReadDirResponse::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

uint32_t DmEfsReadDirResponse::getAtime()
{
    return read<uint32_t>(getFieldOffset("atime"));
}
                

void DmEfsReadDirResponse::setAtime(uint32_t atime)
{
    write<uint32_t>("atime", atime);
}

uint32_t DmEfsReadDirResponse::getMtime()
{
    return read<uint32_t>(getFieldOffset("mtime"));
}
                

void DmEfsReadDirResponse::setMtime(uint32_t mtime)
{
    write<uint32_t>("mtime", mtime);
}

uint32_t DmEfsReadDirResponse::getCtime()
{
    return read<uint32_t>(getFieldOffset("ctime"));
}
                

void DmEfsReadDirResponse::setCtime(uint32_t ctime)
{
    write<uint32_t>("ctime", ctime);
}

std::vector<uint8_t> DmEfsReadDirResponse::getName()
{
	return read(getFieldSize("name"), getFieldOffset("name"));
}
                

void DmEfsReadDirResponse::setName(uint8_t* data, size_t size)
{
    write("name", data, size);
}

void DmEfsReadDirResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setDp(read<uint32_t>(data, getFieldOffset("dp")));
	setSequenceNumber(read<uint32_t>(data, getFieldOffset("sequence_number")));
	setError(read<uint32_t>(data, getFieldOffset("error")));
	setEntryType(read<uint32_t>(data, getFieldOffset("entry_type")));
	setMode(read<uint32_t>(data, getFieldOffset("mode")));
	setSize(read<uint32_t>(data, getFieldOffset("size")));
	setAtime(read<uint32_t>(data, getFieldOffset("atime")));
	setMtime(read<uint32_t>(data, getFieldOffset("mtime")));
	setCtime(read<uint32_t>(data, getFieldOffset("ctime")));
	//variable
}
