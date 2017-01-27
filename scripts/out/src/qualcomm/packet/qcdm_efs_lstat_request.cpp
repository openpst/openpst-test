/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_lstat_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_lstat_request.h"

QcdmEfsLstatRequest::QcdmEfsLstatRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypePrimitive, sizeof(variable));

}

QcdmEfsLstatRequest::~QcdmEfsLstatRequest()
{

}

std::vector<uint8_t> QcdmEfsLstatRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsLstatRequest::setPath(uint8_t* data, size_t size);
{
    write("path", data, size);
}

void QcdmEfsLstatRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

