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
* @file dm_efs_ftruncate_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_ftruncate_request.h"

using namespace OpenPST::Qualcomm;

DmEfsFtruncateRequest::DmEfsFtruncateRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("length", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsFtruncate);
}

DmEfsFtruncateRequest::~DmEfsFtruncateRequest()
{

}

uint16_t DmEfsFtruncateRequest::getSequence()
{
    return read<uint16_t>(getFieldOffset("sequence"));
}
                
void DmEfsFtruncateRequest::setSequence(uint16_t sequence)
{
    write<uint16_t>("sequence", sequence);
}
uint32_t DmEfsFtruncateRequest::getLength()
{
    return read<uint32_t>(getFieldOffset("length"));
}
                
void DmEfsFtruncateRequest::setLength(uint32_t length)
{
    write<uint32_t>("length", length);
}
uint32_t DmEfsFtruncateRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void DmEfsFtruncateRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}

void DmEfsFtruncateRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
void DmEfsFtruncateRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsFtruncateResponse* resp = new DmEfsFtruncateResponse();
		response = resp;
	}
}
