/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_fstat_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_fstat_request.h"

QcdmEfsFstatRequest::QcdmEfsFstatRequest() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsFstatRequest::~QcdmEfsFstatRequest()
{

}

uint32_t QcdmEfsFstatRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void QcdmEfsFstatRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}

void QcdmEfsFstatRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

