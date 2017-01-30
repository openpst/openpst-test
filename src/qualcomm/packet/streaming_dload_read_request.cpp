/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_read_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_read_request.h"

using namespace OpenPST::QC;

StreamingDloadReadRequest::StreamingDloadReadRequest() : StreamingDloadPacket()
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("length", kPacketFieldTypePrimitive, sizeof(uint16_t));

	setCommand(kStreamingDloadRead);
}

StreamingDloadReadRequest::~StreamingDloadReadRequest()
{

}

uint32_t StreamingDloadReadRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadReadRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint16_t StreamingDloadReadRequest::getLength()
{
    return read<uint16_t>(getFieldOffset("length"));
}
                
void StreamingDloadReadRequest::setLength(uint16_t length)
{
    write<uint16_t>("length", length);
}

void StreamingDloadReadRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadReadRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadReadResponse* resp = new StreamingDloadReadResponse();
		response = resp;
	}
}
