/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_stream_write_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_stream_write_request.h"

using namespace OpenPST::QC;

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
void StreamingDloadStreamWriteRequest::setData(uint8_t* data, size_t size);
{
    write("data", data, size);
}
void StreamingDloadStreamWriteRequest::setData(const std::string& data)
{
    write("data", data);
}

void StreamingDloadStreamWriteRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadStreamWriteRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadStreamWriteResponse* resp = new StreamingDloadStreamWriteResponse();
		response = resp;
	}
}
