/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_nop_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_nop_response.h"

using namespace OpenPST::QC;

StreamingDloadNopResponse::StreamingDloadNopResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("identifier", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadNopResponse);
}

StreamingDloadNopResponse::~StreamingDloadNopResponse()
{

}

uint32_t StreamingDloadNopResponse::getIdentifier()
{
    return read<uint32_t>(getFieldOffset("identifier"));
}
                
void StreamingDloadNopResponse::setIdentifier(uint32_t identifier)
{
    write<uint32_t>("identifier", identifier);
}

void StreamingDloadNopResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
