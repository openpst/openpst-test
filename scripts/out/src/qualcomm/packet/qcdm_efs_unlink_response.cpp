/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_unlink_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_unlink_response.h"

using namespace OpenPST::QC;

QcdmEfsUnlinkResponse::QcdmEfsUnlinkResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsUnlinkResponse::~QcdmEfsUnlinkResponse()
{

}

uint32_t QcdmEfsUnlinkResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsUnlinkResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsUnlinkResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

