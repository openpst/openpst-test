/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_mkdir_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_mkdir_response.h"

using namespace OpenPST::QC;

QcdmEfsMkdirResponse::QcdmEfsMkdirResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsMkdirResponse::~QcdmEfsMkdirResponse()
{

}

uint32_t QcdmEfsMkdirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsMkdirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsMkdirResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
