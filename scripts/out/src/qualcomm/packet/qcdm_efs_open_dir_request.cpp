/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_open_dir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_open_dir_request.h"

QcdmEfsOpenDirRequest::QcdmEfsOpenDirRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypePrimitive, sizeof(variable));

}

QcdmEfsOpenDirRequest::~QcdmEfsOpenDirRequest()
{

}

std::vector<uint8_t> QcdmEfsOpenDirRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsOpenDirRequest::setPath(uint8_t* data, size_t size);
{
    write("path", data, size);
}

void QcdmEfsOpenDirRequest::unpack(std::vector<uint8_t>& data)
{
	
}