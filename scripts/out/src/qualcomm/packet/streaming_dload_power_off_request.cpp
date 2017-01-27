/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_power_off_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_power_off_request.h"

StreamingDloadPowerOffRequest::StreamingDloadPowerOffRequest() : StreamingDloadPacket()
{

	setCommand(kStreamingDloadPowerOff);
}

StreamingDloadPowerOffRequest::~StreamingDloadPowerOffRequest()
{

}


void StreamingDloadPowerOffRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

void StreamingDloadPowerOffRequest::prepareResponse()
{
	if (response != nullptr) {
		response = new StreamingDloadPowerOffResponse();
	}
}
