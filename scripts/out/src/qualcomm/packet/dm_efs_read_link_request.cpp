/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_read_link_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_read_link_request.h"

using namespace OpenPST::QC;

DmEfsReadLinkRequest::DmEfsReadLinkRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsReadLinkRequest::~DmEfsReadLinkRequest()
{

}

std::vector<uint8_t> DmEfsReadLinkRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsReadLinkRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsReadLinkRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
