/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_query_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_query_response.h"

QcdmEfsQueryResponse::QcdmEfsQueryResponse() : DmEfsPacket()
{
	addField("max_file_name_length", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_pathname_length", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_symlink_depth", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_file_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_directories", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_mounts", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsQueryResponse::~QcdmEfsQueryResponse()
{

}

uint32_t QcdmEfsQueryResponse::getMaxFileNameLength()
{
    return read<uint32_t>(getFieldOffset("max_file_name_length"));
}
                
void QcdmEfsQueryResponse::setMaxFileNameLength(uint32_t maxFileNameLength)
{
    write<uint32_t>("max_file_name_length", maxFileNameLength);
}
uint32_t QcdmEfsQueryResponse::getMaxPathnameLength()
{
    return read<uint32_t>(getFieldOffset("max_pathname_length"));
}
                
void QcdmEfsQueryResponse::setMaxPathnameLength(uint32_t maxPathnameLength)
{
    write<uint32_t>("max_pathname_length", maxPathnameLength);
}
uint32_t QcdmEfsQueryResponse::getMaxSymlinkDepth()
{
    return read<uint32_t>(getFieldOffset("max_symlink_depth"));
}
                
void QcdmEfsQueryResponse::setMaxSymlinkDepth(uint32_t maxSymlinkDepth)
{
    write<uint32_t>("max_symlink_depth", maxSymlinkDepth);
}
uint32_t QcdmEfsQueryResponse::getMaxFileSize()
{
    return read<uint32_t>(getFieldOffset("max_file_size"));
}
                
void QcdmEfsQueryResponse::setMaxFileSize(uint32_t maxFileSize)
{
    write<uint32_t>("max_file_size", maxFileSize);
}
uint32_t QcdmEfsQueryResponse::getMaxDirectories()
{
    return read<uint32_t>(getFieldOffset("max_directories"));
}
                
void QcdmEfsQueryResponse::setMaxDirectories(uint32_t maxDirectories)
{
    write<uint32_t>("max_directories", maxDirectories);
}
uint32_t QcdmEfsQueryResponse::getMaxMounts()
{
    return read<uint32_t>(getFieldOffset("max_mounts"));
}
                
void QcdmEfsQueryResponse::setMaxMounts(uint32_t maxMounts)
{
    write<uint32_t>("max_mounts", maxMounts);
}

void QcdmEfsQueryResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

