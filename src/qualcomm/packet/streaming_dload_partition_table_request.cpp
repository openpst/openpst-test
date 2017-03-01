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
* @file streaming_dload_partition_table_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_partition_table_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadPartitionTableRequest::StreamingDloadPartitionTableRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("override_existing", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("data", kPacketFieldTypeArray, 512);

	setCommand(kStreamingDloadPartitionTable);
}

StreamingDloadPartitionTableRequest::~StreamingDloadPartitionTableRequest()
{

}

uint8_t StreamingDloadPartitionTableRequest::getOverrideExisting()
{
    return read<uint8_t>(getFieldOffset("override_existing"));
}
                
void StreamingDloadPartitionTableRequest::setOverrideExisting(uint8_t overrideExisting)
{
    write<uint8_t>("override_existing", overrideExisting);
}
std::vector<uint8_t> StreamingDloadPartitionTableRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void StreamingDloadPartitionTableRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void StreamingDloadPartitionTableRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	StreamingDloadPacket::unpack(data, transport);
}
void StreamingDloadPartitionTableRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadPartitionTableResponse* resp = new StreamingDloadPartitionTableResponse();
		response = resp;
	}
}
