#include "/.h"

StreamingDloadNopRequest::StreamingDloadNopRequest() : StreamingDloadPacket()
{
	addField("identifier", kPacketFieldTypePrimitive, sizeof(uint32_t));
}

StreamingDloadNopRequest::~StreamingDloadNopRequest()
{

}

uint32_t StreamingDloadNopRequest::getIdentifier()
{
    return read<uint32_t>(getFieldOffset("identifier"));
}
                
void StreamingDloadNopRequest::setIdentifier(uint32_t identifier)
{
    write<uint32_t>("identifier", identifier);
}
