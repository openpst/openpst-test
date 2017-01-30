/**
* LICENSE PLACEHOLDER
*
* @file sahara_memory_debug64_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_debug64_request.h"

using namespace OpenPST::QC;

SaharaMemoryDebug64Request::SaharaMemoryDebug64Request() : SaharaPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandMemoryDebug64Request);
}

SaharaMemoryDebug64Request::~SaharaMemoryDebug64Request()
{

}

uint32_t SaharaMemoryDebug64Request::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void SaharaMemoryDebug64Request::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint32_t SaharaMemoryDebug64Request::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaMemoryDebug64Request::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaMemoryDebug64Request::unpack(std::vector<uint8_t>& data)
{
}
