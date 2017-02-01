/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_create_link_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_create_link_request.h"

using namespace OpenPST::QC;

DmEfsCreateLinkRequest::DmEfsCreateLinkRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("path", kPacketFieldTypeVariant, 0);
	addField("new_path", kPacketFieldTypeVariant, 0);

}

DmEfsCreateLinkRequest::~DmEfsCreateLinkRequest()
{

}

std::vector<uint8_t> DmEfsCreateLinkRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsCreateLinkRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}
std::vector<uint8_t> DmEfsCreateLinkRequest::getNewPath()
{
	return read(getFieldSize("new_path"), getFieldOffset("new_path"));
}
                
void DmEfsCreateLinkRequest::setNewPath(uint8_t* data, size_t size)
{
    write("new_path", data, size);
}

void DmEfsCreateLinkRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
