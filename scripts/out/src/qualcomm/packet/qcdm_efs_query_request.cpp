/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_query_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_query_request.h"

using namespace OpenPST::QC;

QcdmEfsQueryRequest::QcdmEfsQueryRequest() : DmEfsPacket()
{

}

QcdmEfsQueryRequest::~QcdmEfsQueryRequest()
{

}


void QcdmEfsQueryRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

