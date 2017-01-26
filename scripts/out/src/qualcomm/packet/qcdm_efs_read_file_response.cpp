/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_read_file_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_read_file_response.h"

QcdmEfsReadFileResponse::QcdmEfsReadFileResponse() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("bytes_read", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypePrimitive, sizeof(variable));

}

QcdmEfsReadFileResponse::~QcdmEfsReadFileResponse()
{

}

uint32_t QcdmEfsReadFileResponse::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void QcdmEfsReadFileResponse::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}
uint32_t QcdmEfsReadFileResponse::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                
void QcdmEfsReadFileResponse::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}
uint32_t QcdmEfsReadFileResponse::getBytesRead()
{
    return read<uint32_t>(getFieldOffset("bytes_read"));
}
                
void QcdmEfsReadFileResponse::setBytesRead(uint32_t bytesRead)
{
    write<uint32_t>("bytes_read", bytesRead);
}
uint32_t QcdmEfsReadFileResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsReadFileResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
std::vector<uint8_t> QcdmEfsReadFileResponse::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void QcdmEfsReadFileResponse::setData(uint8_t* data, size_t size);
{
    write("data", data, size);
}

void QcdmEfsReadFileResponse::unpack(std::vector<uint8_t>& data)
{
	
}