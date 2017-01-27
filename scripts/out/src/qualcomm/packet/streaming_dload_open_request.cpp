/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_open_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_request.h"

StreamingDloadOpenRequest::StreamingDloadOpenRequest() : StreamingDloadPacket()
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadOpen);
}

StreamingDloadOpenRequest::~StreamingDloadOpenRequest()
{

}

uint8_t StreamingDloadOpenRequest::getMode()
{
    return read<uint8_t>(getFieldOffset("mode"));
}
                
void StreamingDloadOpenRequest::setMode(uint8_t mode)
{
    write<uint8_t>("mode", mode);
}

void StreamingDloadOpenRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

void StreamingDloadOpenRequest::prepareResponse()
{
	if (response != nullptr) {
		response = new StreamingDloadOpenResponse();
	}
}
