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
* @file dm_efs_read_file_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_read_file_response.h"

using namespace OpenPST::Qualcomm;

DmEfsReadFileResponse::DmEfsReadFileResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("bytes_read", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsRead);
}

DmEfsReadFileResponse::~DmEfsReadFileResponse()
{

}

uint32_t DmEfsReadFileResponse::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void DmEfsReadFileResponse::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}
uint32_t DmEfsReadFileResponse::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                
void DmEfsReadFileResponse::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}
uint32_t DmEfsReadFileResponse::getBytesRead()
{
    return read<uint32_t>(getFieldOffset("bytes_read"));
}
                
void DmEfsReadFileResponse::setBytesRead(uint32_t bytesRead)
{
    write<uint32_t>("bytes_read", bytesRead);
}
uint32_t DmEfsReadFileResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsReadFileResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
std::vector<uint8_t> DmEfsReadFileResponse::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void DmEfsReadFileResponse::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void DmEfsReadFileResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
}
