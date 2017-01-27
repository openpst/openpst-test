/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_unlink_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_unlink_request.h"

using namespace OpenPST::QC;

QcdmEfsUnlinkRequest::QcdmEfsUnlinkRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

QcdmEfsUnlinkRequest::~QcdmEfsUnlinkRequest()
{

}

std::vector<uint8_t> QcdmEfsUnlinkRequest::getPath()
{
	return readV(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsUnlinkRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void QcdmEfsUnlinkRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

