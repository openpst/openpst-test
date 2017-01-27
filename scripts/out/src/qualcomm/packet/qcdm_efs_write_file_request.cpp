/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_write_file_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_write_file_request.h"

using namespace OpenPST::QC;

QcdmEfsWriteFileRequest::QcdmEfsWriteFileRequest() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);

}

QcdmEfsWriteFileRequest::~QcdmEfsWriteFileRequest()
{

}

uint32_t QcdmEfsWriteFileRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void QcdmEfsWriteFileRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}
uint32_t QcdmEfsWriteFileRequest::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                
void QcdmEfsWriteFileRequest::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}
std::vector<uint8_t> QcdmEfsWriteFileRequest::getData()
{
	return readV(getFieldSize("data"), getFieldOffset("data"));
}
                
void QcdmEfsWriteFileRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void QcdmEfsWriteFileRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

