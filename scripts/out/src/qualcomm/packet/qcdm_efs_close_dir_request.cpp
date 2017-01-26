/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_close_dir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_close_dir_request.h"

QcdmEfsCloseDirRequest::QcdmEfsCloseDirRequest() : DmEfsPacket()
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsCloseDirRequest::~QcdmEfsCloseDirRequest()
{

}

uint32_t QcdmEfsCloseDirRequest::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                
void QcdmEfsCloseDirRequest::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}

void QcdmEfsCloseDirRequest::unpack(std::vector<uint8_t>& data)
{
	
}