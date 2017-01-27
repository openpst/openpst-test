/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_access_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_access_response.h"

QcdmEfsAccessResponse::QcdmEfsAccessResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsAccessResponse::~QcdmEfsAccessResponse()
{

}

uint32_t QcdmEfsAccessResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsAccessResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsAccessResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

