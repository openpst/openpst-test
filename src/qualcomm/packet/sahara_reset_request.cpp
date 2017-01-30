/**
* LICENSE PLACEHOLDER
*
* @file sahara_reset_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_reset_request.h"

using namespace OpenPST::QC;

SaharaResetRequest::SaharaResetRequest() : SaharaPacket()
{

	setCommand(kSaharaCommandReset);
}

SaharaResetRequest::~SaharaResetRequest()
{

}


void SaharaResetRequest::unpack(std::vector<uint8_t>& data)
{
}
void SaharaResetRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaResetResponse* resp = new SaharaResetResponse();
		response = resp;
	}
}
