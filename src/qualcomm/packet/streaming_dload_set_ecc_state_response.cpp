/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_set_ecc_state_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_set_ecc_state_response.h"

using namespace OpenPST::QC;

StreamingDloadSetEccStateResponse::StreamingDloadSetEccStateResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadSetEccResponse);
}

StreamingDloadSetEccStateResponse::~StreamingDloadSetEccStateResponse()
{

}


void StreamingDloadSetEccStateResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
