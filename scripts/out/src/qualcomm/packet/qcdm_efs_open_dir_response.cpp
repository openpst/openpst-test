/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_open_dir_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_open_dir_response.h"

using namespace OpenPST::QC;

QcdmEfsOpenDirResponse::QcdmEfsOpenDirResponse() : DmEfsPacket()
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsOpenDirResponse::~QcdmEfsOpenDirResponse()
{

}

uint32_t QcdmEfsOpenDirResponse::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                
void QcdmEfsOpenDirResponse::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}
uint32_t QcdmEfsOpenDirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsOpenDirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsOpenDirResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

