/**
* LICENSE PLACEHOLDER
*
* @file dm_phone_mode_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_phone_mode_response.h"

using namespace OpenPST::QC;

DmPhoneModeResponse::DmPhoneModeResponse() : DmPacket()
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

}

DmPhoneModeResponse::~DmPhoneModeResponse()
{

}

uint8_t DmPhoneModeResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void DmPhoneModeResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void DmPhoneModeResponse::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}

