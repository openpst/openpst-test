#include "/.h"

StreamingDloadStreamWriteRequest::StreamingDloadStreamWriteRequest() : StreamingDloadPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);
}

StreamingDloadStreamWriteRequest::~StreamingDloadStreamWriteRequest()
{

}

uint32_t StreamingDloadStreamWriteRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadStreamWriteRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
std::vector<uint8_t> StreamingDloadStreamWriteRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void StreamingDloadStreamWriteRequest::setData(uint8_t* data, size_t size);
{
    write("data", data, size);
}
