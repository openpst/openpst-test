/**
* LICENSE PLACEHOLDER
*
* @file dm_nv_read_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_nv_read_request.h"

DmNvReadRequest::DmNvReadRequest() : DmPacket()
{
	addField("nv_item", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("data", kPacketFieldTypePrimitive, sizeof(uint8_t[]));

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
                
void DmNvReadRequest::setData(uint8_t* data, size_t size);
{
    write("data", data, size);
}

void DmNvReadRequest::unpack(std::vector<uint8_t>& data)
{
	
}