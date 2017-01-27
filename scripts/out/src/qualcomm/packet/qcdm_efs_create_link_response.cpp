/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_create_link_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_create_link_response.h"

using namespace OpenPST::QC;

QcdmEfsCreateLinkResponse::QcdmEfsCreateLinkResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsCreateLinkResponse::~QcdmEfsCreateLinkResponse()
{

}

uint32_t QcdmEfsCreateLinkResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsCreateLinkResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsCreateLinkResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

