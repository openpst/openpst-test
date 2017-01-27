/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_statfs_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_statfs_response.h"

using namespace OpenPST::QC;

QcdmEfsStatfsResponse::QcdmEfsStatfsResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("filesystem_id", kPacketFieldTypeArray, 8);
	addField("filesystem_type", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("block_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("total_blocks", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("available_blocks", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("free_blocks", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_file_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("file_count", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_file_count", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsStatfsResponse::~QcdmEfsStatfsResponse()
{

}

uint32_t QcdmEfsStatfsResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsStatfsResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
std::vector<uint8_t> QcdmEfsStatfsResponse::getFilesystemId()
{
	return read(getFieldSize("filesystem_id"), getFieldOffset("filesystem_id"));
}
                
void QcdmEfsStatfsResponse::setFilesystemId(uint8_t* data, size_t size)
{
    write("filesystem_id", data, size);
}
uint32_t QcdmEfsStatfsResponse::getFilesystemType()
{
    return read<uint32_t>(getFieldOffset("filesystem_type"));
}
                
void QcdmEfsStatfsResponse::setFilesystemType(uint32_t filesystemType)
{
    write<uint32_t>("filesystem_type", filesystemType);
}
uint32_t QcdmEfsStatfsResponse::getBlockSize()
{
    return read<uint32_t>(getFieldOffset("block_size"));
}
                
void QcdmEfsStatfsResponse::setBlockSize(uint32_t blockSize)
{
    write<uint32_t>("block_size", blockSize);
}
uint32_t QcdmEfsStatfsResponse::getTotalBlocks()
{
    return read<uint32_t>(getFieldOffset("total_blocks"));
}
                
void QcdmEfsStatfsResponse::setTotalBlocks(uint32_t totalBlocks)
{
    write<uint32_t>("total_blocks", totalBlocks);
}
uint32_t QcdmEfsStatfsResponse::getAvailableBlocks()
{
    return read<uint32_t>(getFieldOffset("available_blocks"));
}
                
void QcdmEfsStatfsResponse::setAvailableBlocks(uint32_t availableBlocks)
{
    write<uint32_t>("available_blocks", availableBlocks);
}
uint32_t QcdmEfsStatfsResponse::getFreeBlocks()
{
    return read<uint32_t>(getFieldOffset("free_blocks"));
}
                
void QcdmEfsStatfsResponse::setFreeBlocks(uint32_t freeBlocks)
{
    write<uint32_t>("free_blocks", freeBlocks);
}
uint32_t QcdmEfsStatfsResponse::getMaxFileSize()
{
    return read<uint32_t>(getFieldOffset("max_file_size"));
}
                
void QcdmEfsStatfsResponse::setMaxFileSize(uint32_t maxFileSize)
{
    write<uint32_t>("max_file_size", maxFileSize);
}
uint32_t QcdmEfsStatfsResponse::getFileCount()
{
    return read<uint32_t>(getFieldOffset("file_count"));
}
                
void QcdmEfsStatfsResponse::setFileCount(uint32_t fileCount)
{
    write<uint32_t>("file_count", fileCount);
}
uint32_t QcdmEfsStatfsResponse::getMaxFileCount()
{
    return read<uint32_t>(getFieldOffset("max_file_count"));
}
                
void QcdmEfsStatfsResponse::setMaxFileCount(uint32_t maxFileCount)
{
    write<uint32_t>("max_file_count", maxFileCount);
}

void QcdmEfsStatfsResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

