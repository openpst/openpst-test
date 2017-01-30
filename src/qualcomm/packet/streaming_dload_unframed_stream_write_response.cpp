/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_unframed_stream_write_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unframed_stream_write_response.h"

using namespace OpenPST::QC;

StreamingDloadUnframedStreamWriteResponse::StreamingDloadUnframedStreamWriteResponse() : StreamingDloadPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadUnframedStreamWriteResponse);
}

StreamingDloadUnframedStreamWriteResponse::~StreamingDloadUnframedStreamWriteResponse()
{

}

uint32_t StreamingDloadUnframedStreamWriteResponse::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadUnframedStreamWriteResponse::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}

void StreamingDloadUnframedStreamWriteResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
