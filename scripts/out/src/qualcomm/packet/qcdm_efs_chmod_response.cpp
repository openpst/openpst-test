/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_chmod_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_chmod_response.h"

QcdmEfsChmodResponse::QcdmEfsChmodResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsChmodResponse::~QcdmEfsChmodResponse()
{

}

uint32_t QcdmEfsChmodResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsChmodResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsChmodResponse::unpack(std::vector<uint8_t>& data)
{
	
}