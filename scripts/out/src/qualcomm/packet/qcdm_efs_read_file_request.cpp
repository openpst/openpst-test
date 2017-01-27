/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_read_file_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_read_file_request.h"

QcdmEfsReadFileRequest::QcdmEfsReadFileRequest() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsReadFileRequest::~QcdmEfsReadFileRequest()
{

}

uint32_t QcdmEfsReadFileRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void QcdmEfsReadFileRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}
uint32_t QcdmEfsReadFileRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void QcdmEfsReadFileRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}
uint32_t QcdmEfsReadFileRequest::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                
void QcdmEfsReadFileRequest::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}

void QcdmEfsReadFileRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

