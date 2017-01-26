/**
* LICENSE PLACEHOLDER
*
* @file sahara_memory_debug_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_debug_request.h"

SaharaMemoryDebugRequest::SaharaMemoryDebugRequest() : SaharaPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandMemoryDebug);
}

SaharaMemoryDebugRequest::~SaharaMemoryDebugRequest()
{

}

uint32_t SaharaMemoryDebugRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void SaharaMemoryDebugRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint32_t SaharaMemoryDebugRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaMemoryDebugRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaMemoryDebugRequest::unpack(std::vector<uint8_t>& data)
{
	
}