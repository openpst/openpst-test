/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_lstat_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_lstat_request.h"

using namespace OpenPST::QC;

QcdmEfsLstatRequest::QcdmEfsLstatRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

QcdmEfsLstatRequest::~QcdmEfsLstatRequest()
{

}

std::vector<uint8_t> QcdmEfsLstatRequest::getPath()
{
	return readV(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsLstatRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void QcdmEfsLstatRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

