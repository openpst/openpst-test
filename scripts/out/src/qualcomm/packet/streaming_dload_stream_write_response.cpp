/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_stream_write_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_stream_write_response.h"

StreamingDloadStreamWriteResponse::StreamingDloadStreamWriteResponse() : StreamingDloadPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadBlockWritten);
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

void StreamingDloadStreamWriteResponse::unpack(std::vector<uint8_t>& data)
{
	
}