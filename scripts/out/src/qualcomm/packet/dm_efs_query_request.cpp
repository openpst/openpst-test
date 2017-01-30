/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_query_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_query_request.h"

using namespace OpenPST::QC;

DmEfsQueryRequest::DmEfsQueryRequest() : DmEfsPacket()
{

}

DmEfsQueryRequest::~DmEfsQueryRequest()
{

}


void DmEfsQueryRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
