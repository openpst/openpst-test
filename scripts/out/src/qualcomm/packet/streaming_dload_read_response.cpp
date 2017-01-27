/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_read_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_read_response.h"

StreamingDloadReadResponse::StreamingDloadReadResponse() : StreamingDloadPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypePrimitive, sizeof(variable));

	setCommand(kStreamingDloadReadData);
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
void StreamingDloadReadResponse::setData(const std::string& data);
{
    write("data", data);
}

void StreamingDloadReadResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

