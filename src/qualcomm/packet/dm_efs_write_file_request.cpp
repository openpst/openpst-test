/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_write_file_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_write_file_request.h"

using namespace OpenPST::QC;

DmEfsWriteFileRequest::DmEfsWriteFileRequest() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);

}

DmEfsWriteFileRequest::~DmEfsWriteFileRequest()
{

}

uint32_t DmEfsWriteFileRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void DmEfsWriteFileRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}
uint32_t DmEfsWriteFileRequest::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                
void DmEfsWriteFileRequest::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}
std::vector<uint8_t> DmEfsWriteFileRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void DmEfsWriteFileRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void DmEfsWriteFileRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
