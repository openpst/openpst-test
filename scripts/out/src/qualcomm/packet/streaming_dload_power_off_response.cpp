/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_power_off_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_power_off_response.h"

using namespace OpenPST::QC;

StreamingDloadPowerOffResponse::StreamingDloadPowerOffResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadPoweringDown);
}

StreamingDloadPowerOffResponse::~StreamingDloadPowerOffResponse()
{

}

uint32_t StreamingDloadPowerOffResponse::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadPowerOffResponse::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}

void StreamingDloadPowerOffResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
