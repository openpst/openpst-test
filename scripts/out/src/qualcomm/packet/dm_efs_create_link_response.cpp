/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_create_link_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_create_link_response.h"

using namespace OpenPST::QC;

DmEfsCreateLinkResponse::DmEfsCreateLinkResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsCreateLinkResponse::~DmEfsCreateLinkResponse()
{

}

uint32_t DmEfsCreateLinkResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsCreateLinkResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsCreateLinkResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
