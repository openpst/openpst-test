/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_set_ecc_state_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_set_ecc_state_request.h"

StreamingDloadSetEccStateRequest::StreamingDloadSetEccStateRequest() : StreamingDloadPacket()
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadSetEcc);
}

StreamingDloadSetEccStateRequest::~StreamingDloadSetEccStateRequest()
{

}

uint8_t StreamingDloadSetEccStateRequest::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void StreamingDloadSetEccStateRequest::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void StreamingDloadSetEccStateRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

void StreamingDloadSetEccStateRequest::prepareResponse()
{
	if (response != nullptr) {
		response = new StreamingDloadSetEccStateResponse();
	}
}
