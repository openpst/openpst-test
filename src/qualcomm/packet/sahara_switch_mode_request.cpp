/**
* LICENSE PLACEHOLDER
*
* @file sahara_switch_mode_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_switch_mode_request.h"

using namespace OpenPST::QC;

SaharaSwitchModeRequest::SaharaSwitchModeRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandSwitchMode);
}

SaharaSwitchModeRequest::~SaharaSwitchModeRequest()
{

}

uint32_t SaharaSwitchModeRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void SaharaSwitchModeRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}

void SaharaSwitchModeRequest::unpack(std::vector<uint8_t>& data)
{
}
