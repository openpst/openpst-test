#include "/.h"

StreamingDloadNopResponse::StreamingDloadNopResponse() : StreamingDloadPacket()
{
	addField("identifier", kPacketFieldTypePrimitive, sizeof(uint32_t));
}

StreamingDloadNopResponse::~StreamingDloadNopResponse()
{

}

uint32_t StreamingDloadNopResponse::getIdentifier()
{
    return read<uint32_t>(getFieldOffset("identifier"));
}
                
void StreamingDloadNopResponse::setIdentifier(uint32_t identifier)
{
    write<uint32_t>("identifier", identifier);
}
