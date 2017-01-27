/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_create_link_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_create_link_request.h"

using namespace OpenPST::QC;

QcdmEfsCreateLinkRequest::QcdmEfsCreateLinkRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);
	addField("new_path", kPacketFieldTypeVariant, 0);

}

QcdmEfsCreateLinkRequest::~QcdmEfsCreateLinkRequest()
{

}

std::vector<uint8_t> QcdmEfsCreateLinkRequest::getPath()
{
	return readV(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsCreateLinkRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}
std::vector<uint8_t> QcdmEfsCreateLinkRequest::getNewPath()
{
	return readV(getFieldSize("new_path"), getFieldOffset("new_path"));
}
                
void QcdmEfsCreateLinkRequest::setNewPath(uint8_t* data, size_t size)
{
    write("new_path", data, size);
}

void QcdmEfsCreateLinkRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

