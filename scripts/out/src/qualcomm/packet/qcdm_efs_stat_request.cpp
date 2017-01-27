/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_stat_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_stat_request.h"

using namespace OpenPST::QC;

QcdmEfsStatRequest::QcdmEfsStatRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

QcdmEfsStatRequest::~QcdmEfsStatRequest()
{

}

std::vector<uint8_t> QcdmEfsStatRequest::getPath()
{
	return readV(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsStatRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void QcdmEfsStatRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

