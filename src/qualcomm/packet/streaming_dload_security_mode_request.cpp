/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_security_mode_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_security_mode_request.h"

using namespace OpenPST::QC;

StreamingDloadSecurityModeRequest::StreamingDloadSecurityModeRequest() : StreamingDloadPacket()
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadSecurityMode);
}

StreamingDloadSecurityModeRequest::~StreamingDloadSecurityModeRequest()
{

}

uint8_t StreamingDloadSecurityModeRequest::getMode()
{
    return read<uint8_t>(getFieldOffset("mode"));
}
                
void StreamingDloadSecurityModeRequest::setMode(uint8_t mode)
{
    write<uint8_t>("mode", mode);
}

void StreamingDloadSecurityModeRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadSecurityModeRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadSecurityModeResponse* resp = new StreamingDloadSecurityModeResponse();
		response = resp;
	}
}
