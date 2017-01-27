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

QcdmEfsCreateLinkRequest::QcdmEfsCreateLinkRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypePrimitive, sizeof(variable));
	addField("new_path", kPacketFieldTypePrimitive, sizeof(variable));

}

QcdmEfsCreateLinkRequest::~QcdmEfsCreateLinkRequest()
{

}

std::vector<uint8_t> QcdmEfsCreateLinkRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsCreateLinkRequest::setPath(uint8_t* data, size_t size);
{
    write("path", data, size);
}
std::vector<uint8_t> QcdmEfsCreateLinkRequest::getNewPath()
{
	return read(getFieldSize("new_path"), getFieldOffset("new_path"));
}
                
void QcdmEfsCreateLinkRequest::setNewPath(uint8_t* data, size_t size);
{
    write("new_path", data, size);
}

void QcdmEfsCreateLinkRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

