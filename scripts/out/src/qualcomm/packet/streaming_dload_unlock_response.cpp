/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_unlock_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unlock_response.h"

StreamingDloadUnlockResponse::StreamingDloadUnlockResponse() : StreamingDloadPacket()
{

	setCommand(kStreamingDloadUnlocked);
}

StreamingDloadUnlockResponse::~StreamingDloadUnlockResponse()
{

}


void StreamingDloadUnlockResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

