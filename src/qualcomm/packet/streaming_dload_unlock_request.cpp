/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_unlock_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unlock_request.h"

using namespace OpenPST::QC;

StreamingDloadUnlockRequest::StreamingDloadUnlockRequest() : StreamingDloadPacket()
{
	addField("code", kPacketFieldTypePrimitive, sizeof(uint64_t));

	setCommand(kStreamingDloadUnlock);
}

StreamingDloadUnlockRequest::~StreamingDloadUnlockRequest()
{

}

uint64_t StreamingDloadUnlockRequest::getCode()
{
    return read<uint64_t>(getFieldOffset("code"));
}
                
void StreamingDloadUnlockRequest::setCode(uint64_t code)
{
    write<uint64_t>("code", code);
}

void StreamingDloadUnlockRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadUnlockRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadUnlockResponse* resp = new StreamingDloadUnlockResponse();
		response = resp;
	}
}
