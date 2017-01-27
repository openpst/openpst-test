/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_open_file_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_open_file_request.h"

using namespace OpenPST::QC;

QcdmEfsOpenFileRequest::QcdmEfsOpenFileRequest() : DmEfsPacket()
{
	addField("flags", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("file_path", kPacketFieldTypeVariant, 0);

}

QcdmEfsOpenFileRequest::~QcdmEfsOpenFileRequest()
{

}

uint32_t QcdmEfsOpenFileRequest::getFlags()
{
    return read<uint32_t>(getFieldOffset("flags"));
}
                
void QcdmEfsOpenFileRequest::setFlags(uint32_t flags)
{
    write<uint32_t>("flags", flags);
}
uint32_t QcdmEfsOpenFileRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void QcdmEfsOpenFileRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
std::vector<uint8_t> QcdmEfsOpenFileRequest::getFilePath()
{
	return readV(getFieldSize("file_path"), getFieldOffset("file_path"));
}
                
void QcdmEfsOpenFileRequest::setFilePath(uint8_t* data, size_t size)
{
    write("file_path", data, size);
}

void QcdmEfsOpenFileRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

