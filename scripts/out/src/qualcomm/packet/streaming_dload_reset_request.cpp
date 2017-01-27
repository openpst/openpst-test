/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_reset_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_reset_request.h"

StreamingDloadResetRequest::StreamingDloadResetRequest() : StreamingDloadPacket()
{

	setCommand(kStreamingDloadReset);
}

StreamingDloadResetRequest::~StreamingDloadResetRequest()
{

}


void StreamingDloadResetRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

void StreamingDloadResetRequest::prepareResponse()
{
	if (response != nullptr) {
		response = new StreamingDloadResetResponse();
	}
}
