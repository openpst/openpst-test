/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_close_dir_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_close_dir_response.h"

using namespace OpenPST::QC;

QcdmEfsCloseDirResponse::QcdmEfsCloseDirResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsCloseDirResponse::~QcdmEfsCloseDirResponse()
{

}

uint32_t QcdmEfsCloseDirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsCloseDirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsCloseDirResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

