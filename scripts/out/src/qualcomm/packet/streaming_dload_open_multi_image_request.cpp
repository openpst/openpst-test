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
* @file streaming_dload_open_multi_image_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_multi_image_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadOpenMultiImageRequest::StreamingDloadOpenMultiImageRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
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

void StreamingDloadOpenMultiImageRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	StreamingDloadPacket::unpack(data, transport);
}
void StreamingDloadOpenMultiImageRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadOpenMultiImageResponse* resp = new StreamingDloadOpenMultiImageResponse();
		response = resp;
	}
}
