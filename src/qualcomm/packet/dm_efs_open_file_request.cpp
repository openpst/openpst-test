/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_open_file_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_open_file_request.h"

using namespace OpenPST::QC;

DmEfsOpenFileRequest::DmEfsOpenFileRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("flags", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("file_path", kPacketFieldTypeVariant, 0);

}

DmEfsOpenFileRequest::~DmEfsOpenFileRequest()
{

}

uint32_t DmEfsOpenFileRequest::getFlags()
{
    return read<uint32_t>(getFieldOffset("flags"));
}
                
void DmEfsOpenFileRequest::setFlags(uint32_t flags)
{
    write<uint32_t>("flags", flags);
}
uint32_t DmEfsOpenFileRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void DmEfsOpenFileRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
std::vector<uint8_t> DmEfsOpenFileRequest::getFilePath()
{
	return read(getFieldSize("file_path"), getFieldOffset("file_path"));
}
                
void DmEfsOpenFileRequest::setFilePath(uint8_t* data, size_t size)
{
    write("file_path", data, size);
}

void DmEfsOpenFileRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
