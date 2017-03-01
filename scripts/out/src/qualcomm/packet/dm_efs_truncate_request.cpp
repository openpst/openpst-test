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
* @file dm_efs_truncate_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_truncate_request.h"

using namespace OpenPST::Qualcomm;

DmEfsTruncateRequest::DmEfsTruncateRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("length", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsTruncate);
}

DmEfsTruncateRequest::~DmEfsTruncateRequest()
{

}

uint16_t DmEfsTruncateRequest::getSequence()
{
    return read<uint16_t>(getFieldOffset("sequence"));
}
                
void DmEfsTruncateRequest::setSequence(uint16_t sequence)
{
    write<uint16_t>("sequence", sequence);
}
uint32_t DmEfsTruncateRequest::getLength()
{
    return read<uint32_t>(getFieldOffset("length"));
}
                
void DmEfsTruncateRequest::setLength(uint32_t length)
{
    write<uint32_t>("length", length);
}
std::vector<uint8_t> DmEfsTruncateRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsTruncateRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsTruncateRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
}
void DmEfsTruncateRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsTruncateResponse* resp = new DmEfsTruncateResponse();
		response = resp;
	}
}
