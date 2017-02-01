/**
* LICENSE PLACEHOLDER
*
* @file dm_nv_read_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_nv_read_response.h"

using namespace OpenPST::QC;

DmNvReadResponse::DmNvReadResponse(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("nv_item", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("data", kPacketFieldTypeArray, DIAG_NV_ITEM_SIZE);

}

DmNvReadResponse::~DmNvReadResponse()
{

}

uint16_t DmNvReadResponse::getNvItem()
{
    return read<uint16_t>(getFieldOffset("nv_item"));
}
                
void DmNvReadResponse::setNvItem(uint16_t nvItem)
{
    write<uint16_t>("nv_item", nvItem);
}
std::vector<uint8_t> DmNvReadResponse::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
std::string DmNvReadResponse::getData()
{
	return getString(128, getFieldOffset("data"));
}
                
void DmNvReadResponse::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}
void DmNvReadResponse::setData(const std::string& data)
{
    write("data", data);
}

void DmNvReadResponse::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}
