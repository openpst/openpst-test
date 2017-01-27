/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_open_multi_image_with_payload_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_multi_image_with_payload_request.h"

StreamingDloadOpenMultiImageWithPayloadRequest::StreamingDloadOpenMultiImageWithPayloadRequest() : StreamingDloadPacket()
{
	addField("type", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("payload", kPacketFieldTypePrimitive, sizeof(variable));

	setCommand(kStreamingDloadOpenMultiImage);
}

StreamingDloadOpenMultiImageWithPayloadRequest::~StreamingDloadOpenMultiImageWithPayloadRequest()
{

}

uint8_t StreamingDloadOpenMultiImageWithPayloadRequest::getType()
{
    return read<uint8_t>(getFieldOffset("type"));
}
                
void StreamingDloadOpenMultiImageWithPayloadRequest::setType(uint8_t type)
{
    write<uint8_t>("type", type);
}
std::vector<uint8_t> StreamingDloadOpenMultiImageWithPayloadRequest::getPayload()
{
	return read(getFieldSize("payload"), getFieldOffset("payload"));
}
                
void StreamingDloadOpenMultiImageWithPayloadRequest::setPayload(std::ifstream& file, size_t size);
{
    write("payload", file, size);
}
void StreamingDloadOpenMultiImageWithPayloadRequest::setPayload(uint8_t* data, size_t size);
{
    write("payload", data, size);
}
void StreamingDloadOpenMultiImageWithPayloadRequest::setPayload(const std::string& payload);
{
    write("payload", payload);
}

void StreamingDloadOpenMultiImageWithPayloadRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

void StreamingDloadOpenMultiImageWithPayloadRequest::prepareResponse()
{
	if (response != nullptr) {
		response = new StreamingDloadOpenMultiImageResponse();
	}
}
