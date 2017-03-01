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
* @file streaming_dload_unframed_stream_write_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unframed_stream_write_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadUnframedStreamWriteResponse::StreamingDloadUnframedStreamWriteResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadUnframedStreamWriteResponse);
}

StreamingDloadUnframedStreamWriteResponse::~StreamingDloadUnframedStreamWriteResponse()
{

}

uint32_t StreamingDloadUnframedStreamWriteResponse::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}                
void StreamingDloadUnframedStreamWriteResponse::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}

void StreamingDloadUnframedStreamWriteResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	StreamingDloadPacket::unpack(data, transport);
	setAddress(read<uint32_t>(data, getFieldOffset("address")));
}
