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
* @file streaming_dload_stream_write_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_stream_write_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadStreamWriteRequest::StreamingDloadStreamWriteRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);

	setCommand(kStreamingDloadStreamWrite);
}

StreamingDloadStreamWriteRequest::~StreamingDloadStreamWriteRequest()
{

}

uint32_t StreamingDloadStreamWriteRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadStreamWriteRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
std::vector<uint8_t> StreamingDloadStreamWriteRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void StreamingDloadStreamWriteRequest::setData(std::ifstream& file, size_t size)
{
    write("data", file, size);
}
void StreamingDloadStreamWriteRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}
void StreamingDloadStreamWriteRequest::setData(const std::string& data)
{
    write("data", data);
}

void StreamingDloadStreamWriteRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadStreamWriteResponse* resp = new StreamingDloadStreamWriteResponse();
		response = resp;
	}
}

void StreamingDloadStreamWriteRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	StreamingDloadPacket::unpack(data, transport);
	setAddress(read<uint32_t>(data, getFieldOffset("address")));
	//variable
}
