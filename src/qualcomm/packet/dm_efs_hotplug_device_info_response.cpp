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
* @file dm_efs_hotplug_device_info_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_hotplug_device_info_response.h"

using namespace OpenPST::Qualcomm;

DmEfsHotplugDeviceInfoResponse::DmEfsHotplugDeviceInfoResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("manufacturer_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("oem_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("product_revision", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("product_name", kPacketFieldTypeArray, 16);
	addField("manufactured_date", kPacketFieldTypeArray, 16);

	setSubsysCommand(kDiagEfsHotplugDeviceInfo);
}

DmEfsHotplugDeviceInfoResponse::~DmEfsHotplugDeviceInfoResponse()
{

}

uint16_t DmEfsHotplugDeviceInfoResponse::getSequence()
{
    return read<uint16_t>(getFieldOffset("sequence"));
}                
void DmEfsHotplugDeviceInfoResponse::setSequence(uint16_t sequence)
{
    write<uint16_t>("sequence", sequence);
}uint32_t DmEfsHotplugDeviceInfoResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}                
void DmEfsHotplugDeviceInfoResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}uint32_t DmEfsHotplugDeviceInfoResponse::getManufacturerId()
{
    return read<uint32_t>(getFieldOffset("manufacturer_id"));
}                
void DmEfsHotplugDeviceInfoResponse::setManufacturerId(uint32_t manufacturerId)
{
    write<uint32_t>("manufacturer_id", manufacturerId);
}uint32_t DmEfsHotplugDeviceInfoResponse::getOemId()
{
    return read<uint32_t>(getFieldOffset("oem_id"));
}                
void DmEfsHotplugDeviceInfoResponse::setOemId(uint32_t oemId)
{
    write<uint32_t>("oem_id", oemId);
}uint32_t DmEfsHotplugDeviceInfoResponse::getProductRevision()
{
    return read<uint32_t>(getFieldOffset("product_revision"));
}                
void DmEfsHotplugDeviceInfoResponse::setProductRevision(uint32_t productRevision)
{
    write<uint32_t>("product_revision", productRevision);
}std::vector<uint8_t> DmEfsHotplugDeviceInfoResponse::getProductName()
{
	return read(getFieldSize("product_name"), getFieldOffset("product_name"));
}                
void DmEfsHotplugDeviceInfoResponse::setProductName(uint8_t* data, size_t size)
{
    write("product_name", data, size);
}std::vector<uint8_t> DmEfsHotplugDeviceInfoResponse::getManufacturedDate()
{
	return read(getFieldSize("manufactured_date"), getFieldOffset("manufactured_date"));
}                
void DmEfsHotplugDeviceInfoResponse::setManufacturedDate(uint8_t* data, size_t size)
{
    write("manufactured_date", data, size);
}

void DmEfsHotplugDeviceInfoResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setSequence(read<uint16_t>(data, getFieldOffset("sequence")));
	setError(read<uint32_t>(data, getFieldOffset("error")));
	setManufacturerId(read<uint32_t>(data, getFieldOffset("manufacturer_id")));
	setOemId(read<uint32_t>(data, getFieldOffset("oem_id")));
	setProductRevision(read<uint32_t>(data, getFieldOffset("product_revision")));
	//uint8_t[]
	//uint8_t[]
}
