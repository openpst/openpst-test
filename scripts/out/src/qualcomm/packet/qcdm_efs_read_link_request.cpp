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

QcdmEfsReadLinkRequest::QcdmEfsReadLinkRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypePrimitive, sizeof(variable));

}

QcdmEfsReadLinkRequest::~QcdmEfsReadLinkRequest()
{

}

std::vector<uint8_t> QcdmEfsReadLinkRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsReadLinkRequest::setPath(uint8_t* data, size_t size);
{
    write("path", data, size);
}

void QcdmEfsReadLinkRequest::unpack(std::vector<uint8_t>& data)
{
	
}