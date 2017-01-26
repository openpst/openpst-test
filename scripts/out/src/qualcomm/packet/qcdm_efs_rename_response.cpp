/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_rename_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_rename_response.h"

QcdmEfsRenameResponse::QcdmEfsRenameResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsRenameResponse::~QcdmEfsRenameResponse()
{

}

uint32_t QcdmEfsRenameResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsRenameResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsRenameResponse::unpack(std::vector<uint8_t>& data)
{
	
}