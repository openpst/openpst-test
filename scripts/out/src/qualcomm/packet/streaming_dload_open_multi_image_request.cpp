/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_open_multi_image_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_multi_image_request.h"

using namespace OpenPST::QC;

StreamingDloadOpenMultiImageRequest::StreamingDloadOpenMultiImageRequest() : StreamingDloadPacket()
{
	addField("type", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadOpenMultiImage);
}

StreamingDloadOpenMultiImageRequest::~StreamingDloadOpenMultiImageRequest()
{

}

uint8_t StreamingDloadOpenMultiImageRequest::getType()
{
    return read<uint8_t>(getFieldOffset("type"));
}
                
void StreamingDloadOpenMultiImageRequest::setType(uint8_t type)
{
    write<uint8_t>("type", type);
}

void StreamingDloadOpenMultiImageRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

void StreamingDloadOpenMultiImageRequest::prepareResponse()
{
	if (response != nullptr) {
		StreamingDloadOpenMultiImageResponse* r = new StreamingDloadOpenMultiImageResponse();
		this->response = r;
	}
}
