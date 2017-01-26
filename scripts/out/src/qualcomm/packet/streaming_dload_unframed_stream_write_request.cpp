/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_unframed_stream_write_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unframed_stream_write_request.h"

StreamingDloadUnframedStreamWriteRequest::StreamingDloadUnframedStreamWriteRequest() : StreamingDloadPacket()
{
	addField("alignment_padding", kPacketFieldTypePrimitive, sizeof(uint8_t[]));
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("length", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypePrimitive, sizeof(variable));

	setCommand(kStreamingDloadUnframedStreamWrite);
}

StreamingDloadUnframedStreamWriteRequest::~StreamingDloadUnframedStreamWriteRequest()
{

}

std::vector<uint8_t> StreamingDloadUnframedStreamWriteRequest::getAlignmentPadding()
{
	return read(getFieldSize("alignment_padding"), getFieldOffset("alignment_padding"));
}
                
void StreamingDloadUnframedStreamWriteRequest::setAlignmentPadding(uint8_t* data, size_t size);
{
    write("alignment_padding", data, size);
}
uint32_t StreamingDloadUnframedStreamWriteRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadUnframedStreamWriteRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint32_t StreamingDloadUnframedStreamWriteRequest::getLength()
{
    return read<uint32_t>(getFieldOffset("length"));
}
                
void StreamingDloadUnframedStreamWriteRequest::setLength(uint32_t length)
{
    write<uint32_t>("length", length);
}
std::vector<uint8_t> StreamingDloadUnframedStreamWriteRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void StreamingDloadUnframedStreamWriteRequest::setData(std::ifstream& file, size_t size);
{
    write("data", file, size);
}
void StreamingDloadUnframedStreamWriteRequest::setData(uint8_t* data, size_t size);
{
    write("data", data, size);
}
void StreamingDloadUnframedStreamWriteRequest::setData(const std::string& data);
{
    write("data", data);
}

void StreamingDloadUnframedStreamWriteRequest::unpack(std::vector<uint8_t>& data)
{
	
}