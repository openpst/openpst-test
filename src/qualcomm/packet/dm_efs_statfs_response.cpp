/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file dm_efs_statfs_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_statfs_response.h"

using namespace OpenPST::QC;

DmEfsStatfsResponse::DmEfsStatfsResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
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

	setSubsysCommand(kDiagEfsStatFS);
}

DmEfsStatfsResponse::~DmEfsStatfsResponse()
{

}

uint32_t DmEfsStatfsResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsStatfsResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
std::vector<uint8_t> DmEfsStatfsResponse::getFilesystemId()
{
	return read(getFieldSize("filesystem_id"), getFieldOffset("filesystem_id"));
}
                
void DmEfsStatfsResponse::setFilesystemId(uint8_t* data, size_t size)
{
    write("filesystem_id", data, size);
}
uint32_t DmEfsStatfsResponse::getFilesystemType()
{
    return read<uint32_t>(getFieldOffset("filesystem_type"));
}
                
void DmEfsStatfsResponse::setFilesystemType(uint32_t filesystemType)
{
    write<uint32_t>("filesystem_type", filesystemType);
}
uint32_t DmEfsStatfsResponse::getBlockSize()
{
    return read<uint32_t>(getFieldOffset("block_size"));
}
                
void DmEfsStatfsResponse::setBlockSize(uint32_t blockSize)
{
    write<uint32_t>("block_size", blockSize);
}
uint32_t DmEfsStatfsResponse::getTotalBlocks()
{
    return read<uint32_t>(getFieldOffset("total_blocks"));
}
                
void DmEfsStatfsResponse::setTotalBlocks(uint32_t totalBlocks)
{
    write<uint32_t>("total_blocks", totalBlocks);
}
uint32_t DmEfsStatfsResponse::getAvailableBlocks()
{
    return read<uint32_t>(getFieldOffset("available_blocks"));
}
                
void DmEfsStatfsResponse::setAvailableBlocks(uint32_t availableBlocks)
{
    write<uint32_t>("available_blocks", availableBlocks);
}
uint32_t DmEfsStatfsResponse::getFreeBlocks()
{
    return read<uint32_t>(getFieldOffset("free_blocks"));
}
                
void DmEfsStatfsResponse::setFreeBlocks(uint32_t freeBlocks)
{
    write<uint32_t>("free_blocks", freeBlocks);
}
uint32_t DmEfsStatfsResponse::getMaxFileSize()
{
    return read<uint32_t>(getFieldOffset("max_file_size"));
}
                
void DmEfsStatfsResponse::setMaxFileSize(uint32_t maxFileSize)
{
    write<uint32_t>("max_file_size", maxFileSize);
}
uint32_t DmEfsStatfsResponse::getFileCount()
{
    return read<uint32_t>(getFieldOffset("file_count"));
}
                
void DmEfsStatfsResponse::setFileCount(uint32_t fileCount)
{
    write<uint32_t>("file_count", fileCount);
}
uint32_t DmEfsStatfsResponse::getMaxFileCount()
{
    return read<uint32_t>(getFieldOffset("max_file_count"));
}
                
void DmEfsStatfsResponse::setMaxFileCount(uint32_t maxFileCount)
{
    write<uint32_t>("max_file_count", maxFileCount);
}

void DmEfsStatfsResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
