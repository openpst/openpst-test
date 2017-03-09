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
* @file dm_nv_read_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_nv_read_request.h"

using namespace OpenPST::Qualcomm;

DmNvReadRequest::DmNvReadRequest(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("nv_item", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("data", kPacketFieldTypeArray, DIAG_NV_ITEM_SIZE);

	setCommand(kDiagNvRead);

	setResponseExpected(false);
}

DmNvReadRequest::~DmNvReadRequest()
{

}

uint16_t DmNvReadRequest::getNvItem()
{
    return read<uint16_t>(getFieldOffset("nv_item"));
}
                

void DmNvReadRequest::setNvItem(uint16_t nvItem)
{
    write<uint16_t>("nv_item", nvItem);
}

std::vector<uint8_t> DmNvReadRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                

void DmNvReadRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void DmNvReadRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmPacket::unpack(data, transport);
	setNvItem(read<uint16_t>(data, getFieldOffset("nv_item")));
	//uint8_t[]
}
