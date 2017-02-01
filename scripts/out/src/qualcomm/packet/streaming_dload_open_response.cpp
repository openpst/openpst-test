/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_open_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_response.h"

using namespace OpenPST::QC;

StreamingDloadOpenResponse::StreamingDloadOpenResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadOpened);
}

StreamingDloadOpenResponse::~StreamingDloadOpenResponse()
{

}


void StreamingDloadOpenResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
