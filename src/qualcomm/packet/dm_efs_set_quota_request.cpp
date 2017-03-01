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
* @file dm_efs_set_quota_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_set_quota_request.h"

using namespace OpenPST::Qualcomm;

DmEfsSetQuotaRequest::DmEfsSetQuotaRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("gid", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("amount", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsSetQuota);
}

DmEfsSetQuotaRequest::~DmEfsSetQuotaRequest()
{

}

uint32_t DmEfsSetQuotaRequest::getGid()
{
    return read<uint32_t>(getFieldOffset("gid"));
}                
void DmEfsSetQuotaRequest::setGid(uint32_t gid)
{
    write<uint32_t>("gid", gid);
}uint32_t DmEfsSetQuotaRequest::getAmount()
{
    return read<uint32_t>(getFieldOffset("amount"));
}                
void DmEfsSetQuotaRequest::setAmount(uint32_t amount)
{
    write<uint32_t>("amount", amount);
}std::vector<uint8_t> DmEfsSetQuotaRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}                
void DmEfsSetQuotaRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}
void DmEfsSetQuotaRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsSetQuotaResponse* resp = new DmEfsSetQuotaResponse();
		response = resp;
	}
}

void DmEfsSetQuotaRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setGid(read<uint32_t>(data, getFieldOffset("gid")));
	setAmount(read<uint32_t>(data, getFieldOffset("amount")));
	//variable
}
