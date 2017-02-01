/**
* LICENSE PLACEHOLDER
*
* @file sahara_memory_read_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_read_request.h"

using namespace OpenPST::QC;

SaharaMemoryReadRequest::SaharaMemoryReadRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandMemoryRead);
}

SaharaMemoryReadRequest::~SaharaMemoryReadRequest()
{

}

uint32_t SaharaMemoryReadRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void SaharaMemoryReadRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint32_t SaharaMemoryReadRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaMemoryReadRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaMemoryReadRequest::unpack(std::vector<uint8_t>& data)
{
}
