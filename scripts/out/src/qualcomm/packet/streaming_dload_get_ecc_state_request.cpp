/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_get_ecc_state_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_get_ecc_state_request.h"

using namespace OpenPST::QC;

StreamingDloadGetEccStateRequest::StreamingDloadGetEccStateRequest() : StreamingDloadPacket()
{

	setCommand(kStreamingDloadGetEccState);
}

StreamingDloadGetEccStateRequest::~StreamingDloadGetEccStateRequest()
{

}


void StreamingDloadGetEccStateRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

void StreamingDloadGetEccStateRequest::prepareResponse()
{
	if (response != nullptr) {
		StreamingDloadGetEccStateResponse* r = new StreamingDloadGetEccStateResponse();
		this->response = r;
	}
}