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
* @file streaming_dload_nop_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_nop_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadNopRequest::StreamingDloadNopRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("identifier", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadNop);
}

StreamingDloadNopRequest::~StreamingDloadNopRequest()
{

}

uint32_t StreamingDloadNopRequest::getIdentifier()
{
    return read<uint32_t>(getFieldOffset("identifier"));
}
                
void StreamingDloadNopRequest::setIdentifier(uint32_t identifier)
{
    write<uint32_t>("identifier", identifier);
}

void StreamingDloadNopRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadNopResponse* resp = new StreamingDloadNopResponse();
		response = resp;
	}
}

void StreamingDloadNopRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	StreamingDloadPacket::unpack(data, transport);
	setIdentifier(read<uint32_t>(data, getFieldOffset("identifier")));
}
