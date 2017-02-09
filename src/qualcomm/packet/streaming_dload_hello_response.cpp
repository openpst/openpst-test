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
* @file streaming_dload_hello_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_hello_response.h"

using namespace OpenPST::QC;

StreamingDloadHelloResponse::StreamingDloadHelloResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("magic", kPacketFieldTypeArray, STREAMING_DLOAD_MAGIC_SIZE);
	addField("version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("compatible_version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("preferred_block_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("base_flash_address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("flash_id_length", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("flash_id", kPacketFieldTypeVariant, 0);
	addField("window_size", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("number_of_sectors", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("sector_sizes", kPacketFieldTypeVariant, 0);
	addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadHelloResponse);
}

StreamingDloadHelloResponse::~StreamingDloadHelloResponse()
{

}

std::string StreamingDloadHelloResponse::getMagic()
{
	return getString(32, getFieldOffset("magic"));
}
                
void StreamingDloadHelloResponse::setMagic(uint8_t* data, size_t size)
{
    write("magic", data, size);
}
uint8_t StreamingDloadHelloResponse::getVersion()
{
    return read<uint8_t>(getFieldOffset("version"));
}
                
void StreamingDloadHelloResponse::setVersion(uint8_t version)
{
    write<uint8_t>("version", version);
}
uint8_t StreamingDloadHelloResponse::getCompatibleVersion()
{
    return read<uint8_t>(getFieldOffset("compatible_version"));
}
                
void StreamingDloadHelloResponse::setCompatibleVersion(uint8_t compatibleVersion)
{
    write<uint8_t>("compatible_version", compatibleVersion);
}
uint32_t StreamingDloadHelloResponse::getPreferredBlockSize()
{
    return read<uint32_t>(getFieldOffset("preferred_block_size"));
}
                
void StreamingDloadHelloResponse::setPreferredBlockSize(uint32_t preferredBlockSize)
{
    write<uint32_t>("preferred_block_size", preferredBlockSize);
}
uint32_t StreamingDloadHelloResponse::getBaseFlashAddress()
{
    return read<uint32_t>(getFieldOffset("base_flash_address"));
}
                
void StreamingDloadHelloResponse::setBaseFlashAddress(uint32_t baseFlashAddress)
{
    write<uint32_t>("base_flash_address", baseFlashAddress);
}
uint8_t StreamingDloadHelloResponse::getFlashIdLength()
{
    return read<uint8_t>(getFieldOffset("flash_id_length"));
}
                
void StreamingDloadHelloResponse::setFlashIdLength(uint8_t flashIdLength)
{
    write<uint8_t>("flash_id_length", flashIdLength);
}
std::string StreamingDloadHelloResponse::getFlashId()
{
	return getString(0, getFieldOffset("flash_id"));
}
                
void StreamingDloadHelloResponse::setFlashId(uint8_t* data, size_t size)
{
    write("flash_id", data, size);
}
uint16_t StreamingDloadHelloResponse::getWindowSize()
{
    return read<uint16_t>(getFieldOffset("window_size"));
}
                
void StreamingDloadHelloResponse::setWindowSize(uint16_t windowSize)
{
    write<uint16_t>("window_size", windowSize);
}
uint16_t StreamingDloadHelloResponse::getNumberOfSectors()
{
    return read<uint16_t>(getFieldOffset("number_of_sectors"));
}
                
void StreamingDloadHelloResponse::setNumberOfSectors(uint16_t numberOfSectors)
{
    write<uint16_t>("number_of_sectors", numberOfSectors);
}
std::vector<uint8_t> StreamingDloadHelloResponse::getSectorSizes()
{
	return read(getFieldSize("sector_sizes"), getFieldOffset("sector_sizes"));
}
                
void StreamingDloadHelloResponse::setSectorSizes(uint8_t* data, size_t size)
{
    write("sector_sizes", data, size);
}
uint8_t StreamingDloadHelloResponse::getFeatureBits()
{
    return read<uint8_t>(getFieldOffset("feature_bits"));
}
                
void StreamingDloadHelloResponse::setFeatureBits(uint8_t featureBits)
{
    write<uint8_t>("feature_bits", featureBits);
}

void StreamingDloadHelloResponse::unpack(std::vector<uint8_t>& data)
{
    StreamingDloadPacket::unpack(data);
    
    size_t ssize = 0;
    off_t offset = 0;

    setCommand(read<uint8_t>(data, offset++));

    setMagic(reinterpret_cast<uint8_t*>(&data[offset]), STREAMING_DLOAD_MAGIC_SIZE);
    offset += STREAMING_DLOAD_MAGIC_SIZE;
    
    setVersion(read<uint8_t>(data, offset++));
    setCompatibleVersion(read<uint8_t>(data, offset++));
    
    setPreferredBlockSize(read<uint32_t>(data, offset));
    offset += sizeof(uint32_t);
    
    setBaseFlashAddress(read<uint32_t>(data, offset));
    offset += sizeof(uint32_t);

    setFlashIdLength(read<uint8_t>(data, offset++));

    setFlashId(reinterpret_cast<uint8_t*>(&data[offset]), getFlashIdLength());

    offset += getFlashIdLength();

    setWindowSize(read<uint16_t>(data, offset));
    offset += sizeof(uint16_t);

    setNumberOfSectors(read<uint16_t>(data, offset));
    offset += sizeof(uint16_t);

    ssize = getNumberOfSectors() * sizeof(uint32_t);

    setSectorSizes(reinterpret_cast<uint8_t*>(&data[offset]), ssize);

    offset += ssize;

    setFeatureBits(read<uint8_t>(data, offset));
}
