/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_erase_flash_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_erase_flash_request.h"

StreamingDloadEraseFlashRequest::StreamingDloadEraseFlashRequest() : StreamingDloadPacket()
{

	setCommand(kStreamingDloadEraseFlash);
}

StreamingDloadEraseFlashRequest::~StreamingDloadEraseFlashRequest()
{

}


void StreamingDloadEraseFlashRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

void StreamingDloadEraseFlashRequest::prepareResponse()
{
	if (response != nullptr) {
		response = new StreamingDloadEraseFlashResponse();
	}
}
