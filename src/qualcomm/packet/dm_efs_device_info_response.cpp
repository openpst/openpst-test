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
* @file dm_efs_device_info_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_device_info_response.h"

using namespace OpenPST::Qualcomm;

DmEfsDeviceInfoResponse::DmEfsDeviceInfoResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("total_blocks", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("pages_per_block", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("page_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("total_page_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("maker_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("device_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("device_type", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("name", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsDevInfo);
}

DmEfsDeviceInfoResponse::~DmEfsDeviceInfoResponse()
{

}

uint32_t DmEfsDeviceInfoResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsDeviceInfoResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
uint32_t DmEfsDeviceInfoResponse::getTotalBlocks()
{
    return read<uint32_t>(getFieldOffset("total_blocks"));
}
                
void DmEfsDeviceInfoResponse::setTotalBlocks(uint32_t totalBlocks)
{
    write<uint32_t>("total_blocks", totalBlocks);
}
uint32_t DmEfsDeviceInfoResponse::getPagesPerBlock()
{
    return read<uint32_t>(getFieldOffset("pages_per_block"));
}
                
void DmEfsDeviceInfoResponse::setPagesPerBlock(uint32_t pagesPerBlock)
{
    write<uint32_t>("pages_per_block", pagesPerBlock);
}
uint32_t DmEfsDeviceInfoResponse::getPageSize()
{
    return read<uint32_t>(getFieldOffset("page_size"));
}
                
void DmEfsDeviceInfoResponse::setPageSize(uint32_t pageSize)
{
    write<uint32_t>("page_size", pageSize);
}
uint32_t DmEfsDeviceInfoResponse::getTotalPageSize()
{
    return read<uint32_t>(getFieldOffset("total_page_size"));
}
                
void DmEfsDeviceInfoResponse::setTotalPageSize(uint32_t totalPageSize)
{
    write<uint32_t>("total_page_size", totalPageSize);
}
uint32_t DmEfsDeviceInfoResponse::getMakerId()
{
    return read<uint32_t>(getFieldOffset("maker_id"));
}
                
void DmEfsDeviceInfoResponse::setMakerId(uint32_t makerId)
{
    write<uint32_t>("maker_id", makerId);
}
uint32_t DmEfsDeviceInfoResponse::getDeviceId()
{
    return read<uint32_t>(getFieldOffset("device_id"));
}
                
void DmEfsDeviceInfoResponse::setDeviceId(uint32_t deviceId)
{
    write<uint32_t>("device_id", deviceId);
}
uint8_t DmEfsDeviceInfoResponse::getDeviceType()
{
    return read<uint8_t>(getFieldOffset("device_type"));
}
                
void DmEfsDeviceInfoResponse::setDeviceType(uint8_t deviceType)
{
    write<uint8_t>("device_type", deviceType);
}
std::vector<uint8_t> DmEfsDeviceInfoResponse::getName()
{
	return read(getFieldSize("name"), getFieldOffset("name"));
}
                
void DmEfsDeviceInfoResponse::setName(uint8_t* data, size_t size)
{
    write("name", data, size);
}


void DmEfsDeviceInfoResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setError(read<uint32_t>(data, getFieldOffset("error")));
	setTotalBlocks(read<uint32_t>(data, getFieldOffset("total_blocks")));
	setPagesPerBlock(read<uint32_t>(data, getFieldOffset("pages_per_block")));
	setPageSize(read<uint32_t>(data, getFieldOffset("page_size")));
	setTotalPageSize(read<uint32_t>(data, getFieldOffset("total_page_size")));
	setMakerId(read<uint32_t>(data, getFieldOffset("maker_id")));
	setDeviceId(read<uint32_t>(data, getFieldOffset("device_id")));
	setDeviceType(read<uint8_t>(data, getFieldOffset("device_type")));
	//variable
}
