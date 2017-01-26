#include "/.h"

StreamingDloadReadResponse::StreamingDloadReadResponse() : StreamingDloadPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);
}

StreamingDloadReadResponse::~StreamingDloadReadResponse()
{

}

uint32_t StreamingDloadReadResponse::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadReadResponse::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
std::vector<uint8_t> StreamingDloadReadResponse::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void StreamingDloadReadResponse::setData(uint8_t* data, size_t size);
{
    write("data", data, size);
}
