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
* @file streaming_dload_unframed_stream_write_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/02/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unframed_stream_write_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadUnframedStreamWriteRequest::StreamingDloadUnframedStreamWriteRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("alignment_padding", kPacketFieldTypeArray, 3);
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("length", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);

	setCommand(kStreamingDloadUnframedStreamWrite);

	setResponseExpected(true);
}

StreamingDloadUnframedStreamWriteRequest::~StreamingDloadUnframedStreamWriteRequest()
{

}

std::vector<uint8_t> StreamingDloadUnframedStreamWriteRequest::getAlignmentPadding()
{
	return read(getFieldSize("alignment_padding"), getFieldOffset("alignment_padding"));
}
                

void StreamingDloadUnframedStreamWriteRequest::setAlignmentPadding(uint8_t* data, size_t size)
{
    write("alignment_padding", data, size);
}

uint32_t StreamingDloadUnframedStreamWriteRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                

void StreamingDloadUnframedStreamWriteRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}

uint32_t StreamingDloadUnframedStreamWriteRequest::getLength()
{
    return read<uint32_t>(getFieldOffset("length"));
}
                

void StreamingDloadUnframedStreamWriteRequest::setLength(uint32_t length)
{
    write<uint32_t>("length", length);
}

std::vector<uint8_t> StreamingDloadUnframedStreamWriteRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                

void StreamingDloadUnframedStreamWriteRequest::setData(std::ifstream& file, size_t size)
{
    write("data", file, size);
}

void StreamingDloadUnframedStreamWriteRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void StreamingDloadUnframedStreamWriteRequest::setData(const std::string& data)
{
    write("data", data);
}

void StreamingDloadUnframedStreamWriteRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadUnframedStreamWriteResponse* resp = new StreamingDloadUnframedStreamWriteResponse();
		response = resp;
	}
}

void StreamingDloadUnframedStreamWriteRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	StreamingDloadPacket::unpack(data, transport);
	//uint8_t[]
	setAddress(read<uint32_t>(data, getFieldOffset("address")));
	setLength(read<uint32_t>(data, getFieldOffset("length")));
	//variable
}
