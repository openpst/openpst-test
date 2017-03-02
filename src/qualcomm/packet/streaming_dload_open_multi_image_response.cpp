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
* @file streaming_dload_open_multi_image_response.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_multi_image_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadOpenMultiImageResponse::StreamingDloadOpenMultiImageResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadOpenedMultiImage);

	setResponseExpected(false);
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

void StreamingDloadOpenMultiImageResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	StreamingDloadPacket::unpack(data, transport);
	setStatus(read<uint8_t>(data, getFieldOffset("status")));
}
