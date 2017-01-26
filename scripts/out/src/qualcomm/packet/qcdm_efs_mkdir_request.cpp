/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_mkdir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_mkdir_request.h"

QcdmEfsMkdirRequest::QcdmEfsMkdirRequest() : DmEfsPacket()
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypePrimitive, sizeof(variable));

}

QcdmEfsMkdirRequest::~QcdmEfsMkdirRequest()
{

}

uint32_t QcdmEfsMkdirRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void QcdmEfsMkdirRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
std::vector<uint8_t> QcdmEfsMkdirRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsMkdirRequest::setPath(uint8_t* data, size_t size);
{
    write("path", data, size);
}

void QcdmEfsMkdirRequest::unpack(std::vector<uint8_t>& data)
{
	
}