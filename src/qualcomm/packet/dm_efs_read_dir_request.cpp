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
* @file dm_efs_read_dir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_read_dir_request.h"

using namespace OpenPST::Qualcomm;

DmEfsReadDirRequest::DmEfsReadDirRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("sequence_number", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsReadDir);
}

DmEfsReadDirRequest::~DmEfsReadDirRequest()
{

}

uint32_t DmEfsReadDirRequest::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}                
void DmEfsReadDirRequest::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}uint32_t DmEfsReadDirRequest::getSequenceNumber()
{
    return read<uint32_t>(getFieldOffset("sequence_number"));
}                
void DmEfsReadDirRequest::setSequenceNumber(uint32_t sequenceNumber)
{
    write<uint32_t>("sequence_number", sequenceNumber);
}
void DmEfsReadDirRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsReadDirResponse* resp = new DmEfsReadDirResponse();
		response = resp;
	}
}

void DmEfsReadDirRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setDp(read<uint32_t>(data, getFieldOffset("dp")));
	setSequenceNumber(read<uint32_t>(data, getFieldOffset("sequence_number")));
}
