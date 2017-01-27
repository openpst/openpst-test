/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_partition_table_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_partition_table_response.h"

using namespace OpenPST::QC;

StreamingDloadPartitionTableResponse::StreamingDloadPartitionTableResponse() : StreamingDloadPacket()
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadPartitionTableReceived);
}

StreamingDloadPartitionTableResponse::~StreamingDloadPartitionTableResponse()
{

}

uint8_t StreamingDloadPartitionTableResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void StreamingDloadPartitionTableResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void StreamingDloadPartitionTableResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

