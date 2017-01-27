/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_hello_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_hello_response.h"

using namespace OpenPST::QC;

StreamingDloadHelloResponse::StreamingDloadHelloResponse() : StreamingDloadPacket()
{
	addField("magic", kPacketFieldTypeArray, STREAMING_DLOAD_MAGIC_SIZE);
	addField("version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("compatible_version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadHelloResponse);
}

StreamingDloadHelloResponse::~StreamingDloadHelloResponse()
{

}

std::vector<uint8_t> StreamingDloadHelloResponse::getMagic()
{
	return read(getFieldSize("magic"), getFieldOffset("magic"));
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
}

