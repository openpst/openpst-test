/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_partition_table_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_partition_table_request.h"

using namespace OpenPST::QC;

StreamingDloadPartitionTableRequest::StreamingDloadPartitionTableRequest() : StreamingDloadPacket()
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

void StreamingDloadPartitionTableRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadPartitionTableRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadPartitionTableResponse* resp = new StreamingDloadPartitionTableResponse();
		response = resp;
	}
}
