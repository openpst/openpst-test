/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_security_mode_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_security_mode_response.h"

StreamingDloadSecurityModeResponse::StreamingDloadSecurityModeResponse() : StreamingDloadPacket()
{

	setCommand(kStreamingDloadSecurityModeReceived);
}

StreamingDloadSecurityModeResponse::~StreamingDloadSecurityModeResponse()
{

}


void StreamingDloadSecurityModeResponse::unpack(std::vector<uint8_t>& data)
{
	
}