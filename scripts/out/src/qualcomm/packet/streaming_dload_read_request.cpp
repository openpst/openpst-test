#include "/.h"

StreamingDloadReadRequest::StreamingDloadReadRequest() : StreamingDloadPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("length", kPacketFieldTypePrimitive, sizeof(uint16_t));
}

StreamingDloadReadRequest::~StreamingDloadReadRequest()
{

}

uint32_t StreamingDloadReadRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadReadRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint16_t StreamingDloadReadRequest::getLength()
{
    return read<uint16_t>(getFieldOffset("length"));
}
                
void StreamingDloadReadRequest::setLength(uint16_t length)
{
    write<uint16_t>("length", length);
}
