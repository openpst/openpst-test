/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_reset_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_reset_response.h"

StreamingDloadResetResponse::StreamingDloadResetResponse() : StreamingDloadPacket()
{

	setCommand(kStreamingDloadResetAck);
}

StreamingDloadResetResponse::~StreamingDloadResetResponse()
{

}


void StreamingDloadResetResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

