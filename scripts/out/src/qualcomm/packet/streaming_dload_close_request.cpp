/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_close_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_close_request.h"

StreamingDloadCloseRequest::StreamingDloadCloseRequest() : StreamingDloadPacket()
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadClose);
}

StreamingDloadCloseRequest::~StreamingDloadCloseRequest()
{

}

uint8_t StreamingDloadCloseRequest::getMode()
{
    return read<uint8_t>(getFieldOffset("mode"));
}
                
void StreamingDloadCloseRequest::setMode(uint8_t mode)
{
    write<uint8_t>("mode", mode);
}

void StreamingDloadCloseRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

void StreamingDloadCloseRequest::prepareResponse()
{
	if (response != nullptr) {
		response = new StreamingDloadCloseResponse();
	}
}
