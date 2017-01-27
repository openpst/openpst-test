/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_close_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_close_response.h"

StreamingDloadCloseResponse::StreamingDloadCloseResponse() : StreamingDloadPacket()
{

	setCommand(kStreamingDloadClosed);
}

StreamingDloadCloseResponse::~StreamingDloadCloseResponse()
{

}


void StreamingDloadCloseResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

