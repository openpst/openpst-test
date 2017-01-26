/**
* LICENSE PLACEHOLDER
*
* @file dm_guid_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_guid_response.h"

DmGuidResponse::DmGuidResponse() : DmPacket()
{
	addField("guid", kPacketFieldTypePrimitive, sizeof(uint8_t[]));

}

DmGuidResponse::~DmGuidResponse()
{

}

std::vector<uint8_t> DmGuidResponse::getGuid()
{
	return read(getFieldSize("guid"), getFieldOffset("guid"));
}
std::string DmGuidResponse::getGuid()
{
	return read(16, getFieldOffset("guid"));
}
                
void DmGuidResponse::setGuid(uint8_t* data, size_t size);
{
    write("guid", data, size);
}
void DmGuidResponse::setGuid(const std::string& guid);
{
    write("guid", guid);
}

void DmGuidResponse::unpack(std::vector<uint8_t>& data)
{
	
}