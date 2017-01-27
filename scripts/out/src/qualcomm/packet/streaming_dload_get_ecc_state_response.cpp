/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_get_ecc_state_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_get_ecc_state_response.h"

using namespace OpenPST::QC;

StreamingDloadGetEccStateResponse::StreamingDloadGetEccStateResponse() : StreamingDloadPacket()
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadCurrentEccState);
}

StreamingDloadGetEccStateResponse::~StreamingDloadGetEccStateResponse()
{

}

uint8_t StreamingDloadGetEccStateResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void StreamingDloadGetEccStateResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void StreamingDloadGetEccStateResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}

