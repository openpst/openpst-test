/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_write_file_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_write_file_response.h"

QcdmEfsWriteFileResponse::QcdmEfsWriteFileResponse() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("bytes_written", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsWriteFileResponse::~QcdmEfsWriteFileResponse()
{

}

uint32_t QcdmEfsWriteFileResponse::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void QcdmEfsWriteFileResponse::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}
uint32_t QcdmEfsWriteFileResponse::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                
void QcdmEfsWriteFileResponse::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}
uint32_t QcdmEfsWriteFileResponse::getBytesWritten()
{
    return read<uint32_t>(getFieldOffset("bytes_written"));
}
                
void QcdmEfsWriteFileResponse::setBytesWritten(uint32_t bytesWritten)
{
    write<uint32_t>("bytes_written", bytesWritten);
}
uint32_t QcdmEfsWriteFileResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsWriteFileResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsWriteFileResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

