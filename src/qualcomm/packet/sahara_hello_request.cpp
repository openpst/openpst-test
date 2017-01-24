#include "qualcomm/packet/sahara_hello_request.h"

using namespace OpenPST::QC;

SaharaHelloRequest::SaharaHelloRequest() : SaharaPacket()
{
    addField("version", kPacketFieldTypePrimitive, sizeof(uint32_t));
    addField("min_version", kPacketFieldTypePrimitive, sizeof(uint32_t));
    addField("max_command_packet_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
    addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
    addField("reserved", kPacketFieldTypeArray, sizeof(uint32_t) * 6);
}

/**
* @brief Destructor
*/
SaharaHelloRequest::~SaharaHelloRequest()
{

}

/**
* @brief Set session version
* @param uint32_t version
* @return void
*/
void SaharaHelloRequest::setVersion(uint32_t version)
{
    write<uint32_t>("version", version);
}

uint32_t SaharaHelloRequest::getVersion()
{
    return read<uint32_t>(getFieldOffset("version"));
}

void SaharaHelloRequest::setMinVersion(uint32_t minVersion)
{
    write<uint32_t>("min_version", minVersion);
}

uint32_t SaharaHelloRequest::getMinVersion()
{
    return read<uint32_t>(getFieldOffset("min_version"));
}

void SaharaHelloRequest::setMaxCommandPacketSize(uint32_t maxCommandPacketSize)
{
    write<uint32_t>("max_command_packet_size", maxCommandPacketSize);
}

uint32_t SaharaHelloRequest::getMaxCommandPacketSize()
{
    return read<uint32_t>(getFieldOffset("max_command_packet_size"));
}


