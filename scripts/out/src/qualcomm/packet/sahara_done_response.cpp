/**
* LICENSE PLACEHOLDER
*
* @file sahara_done_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_done_response.h"

SaharaDoneResponse::SaharaDoneResponse() : SaharaPacket()
{

	setCommand(kSaharaCommandDoneResponse);
}

SaharaDoneResponse::~SaharaDoneResponse()
{

}


void SaharaDoneResponse::unpack(std::vector<uint8_t>& data)
{
	
}