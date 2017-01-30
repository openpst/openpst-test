/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_query_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_query_response.h"

using namespace OpenPST::QC;

DmEfsQueryResponse::DmEfsQueryResponse() : DmEfsPacket()
{
	addField("max_file_name_length", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_pathname_length", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_symlink_depth", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_file_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_directories", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_mounts", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsQueryResponse::~DmEfsQueryResponse()
{

}

uint32_t DmEfsQueryResponse::getMaxFileNameLength()
{
    return read<uint32_t>(getFieldOffset("max_file_name_length"));
}
                
void DmEfsQueryResponse::setMaxFileNameLength(uint32_t maxFileNameLength)
{
    write<uint32_t>("max_file_name_length", maxFileNameLength);
}
uint32_t DmEfsQueryResponse::getMaxPathnameLength()
{
    return read<uint32_t>(getFieldOffset("max_pathname_length"));
}
                
void DmEfsQueryResponse::setMaxPathnameLength(uint32_t maxPathnameLength)
{
    write<uint32_t>("max_pathname_length", maxPathnameLength);
}
uint32_t DmEfsQueryResponse::getMaxSymlinkDepth()
{
    return read<uint32_t>(getFieldOffset("max_symlink_depth"));
}
                
void DmEfsQueryResponse::setMaxSymlinkDepth(uint32_t maxSymlinkDepth)
{
    write<uint32_t>("max_symlink_depth", maxSymlinkDepth);
}
uint32_t DmEfsQueryResponse::getMaxFileSize()
{
    return read<uint32_t>(getFieldOffset("max_file_size"));
}
                
void DmEfsQueryResponse::setMaxFileSize(uint32_t maxFileSize)
{
    write<uint32_t>("max_file_size", maxFileSize);
}
uint32_t DmEfsQueryResponse::getMaxDirectories()
{
    return read<uint32_t>(getFieldOffset("max_directories"));
}
                
void DmEfsQueryResponse::setMaxDirectories(uint32_t maxDirectories)
{
    write<uint32_t>("max_directories", maxDirectories);
}
uint32_t DmEfsQueryResponse::getMaxMounts()
{
    return read<uint32_t>(getFieldOffset("max_mounts"));
}
                
void DmEfsQueryResponse::setMaxMounts(uint32_t maxMounts)
{
    write<uint32_t>("max_mounts", maxMounts);
}

void DmEfsQueryResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
