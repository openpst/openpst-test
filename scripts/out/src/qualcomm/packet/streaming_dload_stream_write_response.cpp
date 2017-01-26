#include "/.h"

StreamingDloadStreamWriteResponse::StreamingDloadStreamWriteResponse() : StreamingDloadPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
}

StreamingDloadStreamWriteResponse::~StreamingDloadStreamWriteResponse()
{

}

uint32_t StreamingDloadStreamWriteResponse::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadStreamWriteResponse::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
