/**
* LICENSE PLACEHOLDER
*
* @file sahara_hello_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_hello_response.h"

using namespace OpenPST::QC;

SaharaHelloResponse::SaharaHelloResponse() : SaharaPacket()
{
	addField("version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("min_version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_command_packet_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("status", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("reserved", kPacketFieldTypeArray, 24);
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandHelloResponse);
}

SaharaHelloResponse::~SaharaHelloResponse()
{

}

uint32_t SaharaHelloResponse::getVersion()
{
    return read<uint32_t>(getFieldOffset("version"));
}
                
void SaharaHelloResponse::setVersion(uint32_t version)
{
    write<uint32_t>("version", version);
}
uint32_t SaharaHelloResponse::getMinVersion()
{
    return read<uint32_t>(getFieldOffset("min_version"));
}
                
void SaharaHelloResponse::setMinVersion(uint32_t minVersion)
{
    write<uint32_t>("min_version", minVersion);
}
uint32_t SaharaHelloResponse::getMaxCommandPacketSize()
{
    return read<uint32_t>(getFieldOffset("max_command_packet_size"));
}
                
void SaharaHelloResponse::setMaxCommandPacketSize(uint32_t maxCommandPacketSize)
{
    write<uint32_t>("max_command_packet_size", maxCommandPacketSize);
}
uint32_t SaharaHelloResponse::getStatus()
{
    return read<uint32_t>(getFieldOffset("status"));
}
                
void SaharaHelloResponse::setStatus(uint32_t status)
{
    write<uint32_t>("status", status);
}
std::vector<uint8_t> SaharaHelloResponse::getReserved()
{
	return read(getFieldSize("reserved"), getFieldOffset("reserved"));
}
                
void SaharaHelloResponse::setReserved(uint8_t* data, size_t size)
{
    write("reserved", data, size);
}
uint32_t SaharaHelloResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void SaharaHelloResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}

void SaharaHelloResponse::unpack(std::vector<uint8_t>& data)
{
}
