/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file streaming_dload_open_multi_image_with_payload_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_multi_image_with_payload_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadOpenMultiImageWithPayloadRequest::StreamingDloadOpenMultiImageWithPayloadRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("type", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("payload", kPacketFieldTypeVariant, 0);

	setCommand(kStreamingDloadOpenMultiImage);

	setResponseExpected(true);
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
                

void StreamingDloadOpenMultiImageWithPayloadRequest::setPayload(std::ifstream& file, size_t size)
{
    write("payload", file, size);
}

void StreamingDloadOpenMultiImageWithPayloadRequest::setPayload(uint8_t* data, size_t size)
{
    write("payload", data, size);
}

void StreamingDloadOpenMultiImageWithPayloadRequest::setPayload(const std::string& payload)
{
    write("payload", payload);
}

void StreamingDloadOpenMultiImageWithPayloadRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadOpenMultiImageResponse* resp = new StreamingDloadOpenMultiImageResponse();
		response = resp;
	}
}

void StreamingDloadOpenMultiImageWithPayloadRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	StreamingDloadPacket::unpack(data, transport);
	setType(read<uint8_t>(data, getFieldOffset("type")));
	//variable
}
