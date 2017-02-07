/**
* LICENSE PLACEHOLDER
*
* @file sahara_done_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_done_request.h"

using namespace OpenPST::QC;

SaharaDoneRequest::SaharaDoneRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{

	setCommand(kSaharaCommandDone);
}

SaharaDoneRequest::~SaharaDoneRequest()
{

}


void SaharaDoneRequest::unpack(std::vector<uint8_t>& data)
{
}
void SaharaDoneRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaDoneResponse* resp = new SaharaDoneResponse();
		response = resp;
	}
}