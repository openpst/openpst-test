/**
* LICENSE PLACEHOLDER
*
* @file sahara_memory_read64_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_read64_request.h"

SaharaMemoryRead64Request::SaharaMemoryRead64Request() : SaharaPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint64_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint64_t));

	setCommand(kSaharaCommandMemoryDebug64);
}

SaharaMemoryRead64Request::~SaharaMemoryRead64Request()
{

}

uint64_t SaharaMemoryRead64Request::getAddress()
{
    return read<uint64_t>(getFieldOffset("address"));
}
                
void SaharaMemoryRead64Request::setAddress(uint64_t address)
{
    write<uint64_t>("address", address);
}
uint64_t SaharaMemoryRead64Request::getSize()
{
    return read<uint64_t>(getFieldOffset("size"));
}
                
void SaharaMemoryRead64Request::setSize(uint64_t size)
{
    write<uint64_t>("size", size);
}

void SaharaMemoryRead64Request::unpack(std::vector<uint8_t>& data)
{
}

