/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_read_link_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_read_link_request.h"

using namespace OpenPST::QC;

QcdmEfsReadLinkRequest::QcdmEfsReadLinkRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

QcdmEfsReadLinkRequest::~QcdmEfsReadLinkRequest()
{

}

std::vector<uint8_t> QcdmEfsReadLinkRequest::getPath()
{
	return readV(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsReadLinkRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void QcdmEfsReadLinkRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

