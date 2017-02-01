/**
* LICENSE PLACEHOLDER
*
* @file sahara_reset_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_reset_response.h"

using namespace OpenPST::QC;

SaharaResetResponse::SaharaResetResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{

	setCommand(kSaharaCommandResetResponse);
}

SaharaResetResponse::~SaharaResetResponse()
{

}


void SaharaResetResponse::unpack(std::vector<uint8_t>& data)
{
}
