#include "qualcomm/packet/sahara_hello_response.h"

using namespace OpenPST::QC;

SaharaHelloResponse::SaharaHelloResponse() : SaharaPacket()
{
    addField("version", kPacketFieldTypePrimitive, sizeof(uint32_t));
    addField("min_version", kPacketFieldTypePrimitive, sizeof(uint32_t));
    addField("max_command_packet_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
    addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
    addField("reserved", kPacketFieldTypeArray, sizeof(uint32_t) * 6);

    setCommand(kSaharaCommandHelloResponse);
}

/**
* @brief Destructor
*/
SaharaHelloResponse::~SaharaHelloResponse()
{

}

/**
* @brief Set session version
* @param uint32_t version
* @return void
*/
void SaharaHelloResponse::setVersion(uint32_t version)
{
    write<uint32_t>("version", version);
}

uint32_t SaharaHelloResponse::getVersion()
{
    return read<uint32_t>(getFieldOffset("version"));
}

void SaharaHelloResponse::setMinVersion(uint32_t minVersion)
{
    write<uint32_t>("min_version", minVersion);
}

uint32_t SaharaHelloResponse::getMinVersion()
{
    return read<uint32_t>(getFieldOffset("min_version"));
}

void SaharaHelloResponse::setMaxCommandPacketSize(uint32_t maxCommandPacketSize)
{
    write<uint32_t>("max_command_packet_size", maxCommandPacketSize);
}

uint32_t SaharaHelloResponse::getMaxCommandPacketSize()
{
    return read<uint32_t>(getFieldOffset("max_command_packet_size"));
}

void SaharaHelloResponse::unpack(std::vector<uint8_t>& data)  {
                    
}