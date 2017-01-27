/**
* LICENSE PLACEHOLDER
*
* @file dm_guid_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_guid_request.h"

using namespace OpenPST::QC;

DmGuidRequest::DmGuidRequest() : DmPacket()
{

}

DmGuidRequest::~DmGuidRequest()
{

}


void DmGuidRequest::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}

