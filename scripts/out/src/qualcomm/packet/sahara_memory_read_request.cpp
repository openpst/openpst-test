#include "/.h"

SaharaMemoryReadRequest::SaharaMemoryReadRequest() : SaharaPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
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
