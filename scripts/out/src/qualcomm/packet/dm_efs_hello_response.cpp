/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_hello_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_hello_response.h"

using namespace OpenPST::QC;

DmEfsHelloResponse::DmEfsHelloResponse() : DmEfsPacket()
{
	addField("target_packet_window_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("target_packet_window_byte_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("host_packet_window_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("host_packet_window_byte_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("dir_iterator_window_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("dir_iterator_window_byte_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsHelloResponse::~DmEfsHelloResponse()
{

}

uint32_t DmEfsHelloResponse::getTargetPacketWindowSize()
{
    return read<uint32_t>(getFieldOffset("target_packet_window_size"));
}
                
void DmEfsHelloResponse::setTargetPacketWindowSize(uint32_t targetPacketWindowSize)
{
    write<uint32_t>("target_packet_window_size", targetPacketWindowSize);
}
uint32_t DmEfsHelloResponse::getTargetPacketWindowByteSize()
{
    return read<uint32_t>(getFieldOffset("target_packet_window_byte_size"));
}
                
void DmEfsHelloResponse::setTargetPacketWindowByteSize(uint32_t targetPacketWindowByteSize)
{
    write<uint32_t>("target_packet_window_byte_size", targetPacketWindowByteSize);
}
uint32_t DmEfsHelloResponse::getHostPacketWindowSize()
{
    return read<uint32_t>(getFieldOffset("host_packet_window_size"));
}
                
void DmEfsHelloResponse::setHostPacketWindowSize(uint32_t hostPacketWindowSize)
{
    write<uint32_t>("host_packet_window_size", hostPacketWindowSize);
}
uint32_t DmEfsHelloResponse::getHostPacketWindowByteSize()
{
    return read<uint32_t>(getFieldOffset("host_packet_window_byte_size"));
}
                
void DmEfsHelloResponse::setHostPacketWindowByteSize(uint32_t hostPacketWindowByteSize)
{
    write<uint32_t>("host_packet_window_byte_size", hostPacketWindowByteSize);
}
uint32_t DmEfsHelloResponse::getDirIteratorWindowSize()
{
    return read<uint32_t>(getFieldOffset("dir_iterator_window_size"));
}
                
void DmEfsHelloResponse::setDirIteratorWindowSize(uint32_t dirIteratorWindowSize)
{
    write<uint32_t>("dir_iterator_window_size", dirIteratorWindowSize);
}
uint32_t DmEfsHelloResponse::getDirIteratorWindowByteSize()
{
    return read<uint32_t>(getFieldOffset("dir_iterator_window_byte_size"));
}
                
void DmEfsHelloResponse::setDirIteratorWindowByteSize(uint32_t dirIteratorWindowByteSize)
{
    write<uint32_t>("dir_iterator_window_byte_size", dirIteratorWindowByteSize);
}
uint32_t DmEfsHelloResponse::getVersion()
{
    return read<uint32_t>(getFieldOffset("version"));
}
                
void DmEfsHelloResponse::setVersion(uint32_t version)
{
    write<uint32_t>("version", version);
}
uint32_t DmEfsHelloResponse::getMaxVersion()
{
    return read<uint32_t>(getFieldOffset("max_version"));
}
                
void DmEfsHelloResponse::setMaxVersion(uint32_t maxVersion)
{
    write<uint32_t>("max_version", maxVersion);
}
uint32_t DmEfsHelloResponse::getFeatureBits()
{
    return read<uint32_t>(getFieldOffset("feature_bits"));
}
                
void DmEfsHelloResponse::setFeatureBits(uint32_t featureBits)
{
    write<uint32_t>("feature_bits", featureBits);
}

void DmEfsHelloResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
