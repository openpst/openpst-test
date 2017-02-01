/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_erase_flash_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_erase_flash_response.h"

using namespace OpenPST::QC;

StreamingDloadEraseFlashResponse::StreamingDloadEraseFlashResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadFlashErased);
}

StreamingDloadEraseFlashResponse::~StreamingDloadEraseFlashResponse()
{

}


void StreamingDloadEraseFlashResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
