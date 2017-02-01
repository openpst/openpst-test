/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_open_multi_image_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_multi_image_response.h"

using namespace OpenPST::QC;

StreamingDloadOpenMultiImageResponse::StreamingDloadOpenMultiImageResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadOpenedMultiImage);
}

StreamingDloadOpenMultiImageResponse::~StreamingDloadOpenMultiImageResponse()
{

}

uint8_t StreamingDloadOpenMultiImageResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void StreamingDloadOpenMultiImageResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void StreamingDloadOpenMultiImageResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
