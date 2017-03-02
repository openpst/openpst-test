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
* @file dm_efs_statfs_v2_response.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_statfs_v2_response.h"

using namespace OpenPST::Qualcomm;

DmEfsStatfsV2Response::DmEfsStatfsV2Response(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("fs_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("fs_type", kPacketFieldTypeArray, 8);
	addField("block_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("total_blocks", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("available_blocks", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("free_blocks", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_file_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("file_count", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_files", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_write_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_path_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("case_sensitive", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("case_preserving", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("file_size_units", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_open_files", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("name_rule", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("name_encoding", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsStatVFS_V2);

	setResponseExpected(false);
}

DmEfsStatfsV2Response::~DmEfsStatfsV2Response()
{

}

uint16_t DmEfsStatfsV2Response::getSequence()
{
    return read<uint16_t>(getFieldOffset("sequence"));
}
                

void DmEfsStatfsV2Response::setSequence(uint16_t sequence)
{
    write<uint16_t>("sequence", sequence);
}

uint32_t DmEfsStatfsV2Response::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                

void DmEfsStatfsV2Response::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

uint32_t DmEfsStatfsV2Response::getFsId()
{
    return read<uint32_t>(getFieldOffset("fs_id"));
}
                

void DmEfsStatfsV2Response::setFsId(uint32_t fsId)
{
    write<uint32_t>("fs_id", fsId);
}

std::vector<uint8_t> DmEfsStatfsV2Response::getFsType()
{
	return read(getFieldSize("fs_type"), getFieldOffset("fs_type"));
}
                

void DmEfsStatfsV2Response::setFsType(uint8_t* data, size_t size)
{
    write("fs_type", data, size);
}

uint32_t DmEfsStatfsV2Response::getBlockSize()
{
    return read<uint32_t>(getFieldOffset("block_size"));
}
                

void DmEfsStatfsV2Response::setBlockSize(uint32_t blockSize)
{
    write<uint32_t>("block_size", blockSize);
}

uint32_t DmEfsStatfsV2Response::getTotalBlocks()
{
    return read<uint32_t>(getFieldOffset("total_blocks"));
}
                

void DmEfsStatfsV2Response::setTotalBlocks(uint32_t totalBlocks)
{
    write<uint32_t>("total_blocks", totalBlocks);
}

uint32_t DmEfsStatfsV2Response::getAvailableBlocks()
{
    return read<uint32_t>(getFieldOffset("available_blocks"));
}
                

void DmEfsStatfsV2Response::setAvailableBlocks(uint32_t availableBlocks)
{
    write<uint32_t>("available_blocks", availableBlocks);
}

uint32_t DmEfsStatfsV2Response::getFreeBlocks()
{
    return read<uint32_t>(getFieldOffset("free_blocks"));
}
                

void DmEfsStatfsV2Response::setFreeBlocks(uint32_t freeBlocks)
{
    write<uint32_t>("free_blocks", freeBlocks);
}

uint32_t DmEfsStatfsV2Response::getMaxFileSize()
{
    return read<uint32_t>(getFieldOffset("max_file_size"));
}
                

void DmEfsStatfsV2Response::setMaxFileSize(uint32_t maxFileSize)
{
    write<uint32_t>("max_file_size", maxFileSize);
}

uint32_t DmEfsStatfsV2Response::getFileCount()
{
    return read<uint32_t>(getFieldOffset("file_count"));
}
                

void DmEfsStatfsV2Response::setFileCount(uint32_t fileCount)
{
    write<uint32_t>("file_count", fileCount);
}

uint32_t DmEfsStatfsV2Response::getMaxFiles()
{
    return read<uint32_t>(getFieldOffset("max_files"));
}
                

void DmEfsStatfsV2Response::setMaxFiles(uint32_t maxFiles)
{
    write<uint32_t>("max_files", maxFiles);
}

uint32_t DmEfsStatfsV2Response::getMaxWriteSize()
{
    return read<uint32_t>(getFieldOffset("max_write_size"));
}
                

void DmEfsStatfsV2Response::setMaxWriteSize(uint32_t maxWriteSize)
{
    write<uint32_t>("max_write_size", maxWriteSize);
}

uint32_t DmEfsStatfsV2Response::getMaxPathSize()
{
    return read<uint32_t>(getFieldOffset("max_path_size"));
}
                

void DmEfsStatfsV2Response::setMaxPathSize(uint32_t maxPathSize)
{
    write<uint32_t>("max_path_size", maxPathSize);
}

uint32_t DmEfsStatfsV2Response::getCaseSensitive()
{
    return read<uint32_t>(getFieldOffset("case_sensitive"));
}
                

void DmEfsStatfsV2Response::setCaseSensitive(uint32_t caseSensitive)
{
    write<uint32_t>("case_sensitive", caseSensitive);
}

uint32_t DmEfsStatfsV2Response::getCasePreserving()
{
    return read<uint32_t>(getFieldOffset("case_preserving"));
}
                

void DmEfsStatfsV2Response::setCasePreserving(uint32_t casePreserving)
{
    write<uint32_t>("case_preserving", casePreserving);
}

uint32_t DmEfsStatfsV2Response::getFileSizeUnits()
{
    return read<uint32_t>(getFieldOffset("file_size_units"));
}
                

void DmEfsStatfsV2Response::setFileSizeUnits(uint32_t fileSizeUnits)
{
    write<uint32_t>("file_size_units", fileSizeUnits);
}

uint32_t DmEfsStatfsV2Response::getMaxOpenFiles()
{
    return read<uint32_t>(getFieldOffset("max_open_files"));
}
                

void DmEfsStatfsV2Response::setMaxOpenFiles(uint32_t maxOpenFiles)
{
    write<uint32_t>("max_open_files", maxOpenFiles);
}

uint32_t DmEfsStatfsV2Response::getNameRule()
{
    return read<uint32_t>(getFieldOffset("name_rule"));
}
                

void DmEfsStatfsV2Response::setNameRule(uint32_t nameRule)
{
    write<uint32_t>("name_rule", nameRule);
}

uint32_t DmEfsStatfsV2Response::getNameEncoding()
{
    return read<uint32_t>(getFieldOffset("name_encoding"));
}
                

void DmEfsStatfsV2Response::setNameEncoding(uint32_t nameEncoding)
{
    write<uint32_t>("name_encoding", nameEncoding);
}

void DmEfsStatfsV2Response::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	DmEfsPacket::unpack(data, transport);
	setSequence(read<uint16_t>(data, getFieldOffset("sequence")));
	setError(read<uint32_t>(data, getFieldOffset("error")));
	setFsId(read<uint32_t>(data, getFieldOffset("fs_id")));
	//uint8_t[]
	setBlockSize(read<uint32_t>(data, getFieldOffset("block_size")));
	setTotalBlocks(read<uint32_t>(data, getFieldOffset("total_blocks")));
	setAvailableBlocks(read<uint32_t>(data, getFieldOffset("available_blocks")));
	setFreeBlocks(read<uint32_t>(data, getFieldOffset("free_blocks")));
	setMaxFileSize(read<uint32_t>(data, getFieldOffset("max_file_size")));
	setFileCount(read<uint32_t>(data, getFieldOffset("file_count")));
	setMaxFiles(read<uint32_t>(data, getFieldOffset("max_files")));
	setMaxWriteSize(read<uint32_t>(data, getFieldOffset("max_write_size")));
	setMaxPathSize(read<uint32_t>(data, getFieldOffset("max_path_size")));
	setCaseSensitive(read<uint32_t>(data, getFieldOffset("case_sensitive")));
	setCasePreserving(read<uint32_t>(data, getFieldOffset("case_preserving")));
	setFileSizeUnits(read<uint32_t>(data, getFieldOffset("file_size_units")));
	setMaxOpenFiles(read<uint32_t>(data, getFieldOffset("max_open_files")));
	setNameRule(read<uint32_t>(data, getFieldOffset("name_rule")));
	setNameEncoding(read<uint32_t>(data, getFieldOffset("name_encoding")));
}
