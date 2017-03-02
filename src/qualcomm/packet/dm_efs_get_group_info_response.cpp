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
* @file dm_efs_get_group_info_response.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_get_group_info_response.h"

using namespace OpenPST::Qualcomm;

DmEfsGetGroupInfoResponse::DmEfsGetGroupInfoResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("quota_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("reservation_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("space_used", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsGetGroupInfo);

	setResponseExpected(false);
}

DmEfsGetGroupInfoResponse::~DmEfsGetGroupInfoResponse()
{

}

uint32_t DmEfsGetGroupInfoResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                

void DmEfsGetGroupInfoResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

uint32_t DmEfsGetGroupInfoResponse::getQuotaSize()
{
    return read<uint32_t>(getFieldOffset("quota_size"));
}
                

void DmEfsGetGroupInfoResponse::setQuotaSize(uint32_t quotaSize)
{
    write<uint32_t>("quota_size", quotaSize);
}

uint32_t DmEfsGetGroupInfoResponse::getReservationSize()
{
    return read<uint32_t>(getFieldOffset("reservation_size"));
}
                

void DmEfsGetGroupInfoResponse::setReservationSize(uint32_t reservationSize)
{
    write<uint32_t>("reservation_size", reservationSize);
}

uint32_t DmEfsGetGroupInfoResponse::getSpaceUsed()
{
    return read<uint32_t>(getFieldOffset("space_used"));
}
                

void DmEfsGetGroupInfoResponse::setSpaceUsed(uint32_t spaceUsed)
{
    write<uint32_t>("space_used", spaceUsed);
}

void DmEfsGetGroupInfoResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	DmEfsPacket::unpack(data, transport);
	setError(read<uint32_t>(data, getFieldOffset("error")));
	setQuotaSize(read<uint32_t>(data, getFieldOffset("quota_size")));
	setReservationSize(read<uint32_t>(data, getFieldOffset("reservation_size")));
	setSpaceUsed(read<uint32_t>(data, getFieldOffset("space_used")));
}
