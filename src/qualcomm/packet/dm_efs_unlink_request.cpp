/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_unlink_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_unlink_request.h"

using namespace OpenPST::QC;

DmEfsUnlinkRequest::DmEfsUnlinkRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsUnlinkRequest::~DmEfsUnlinkRequest()
{

}

std::vector<uint8_t> DmEfsUnlinkRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsUnlinkRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsUnlinkRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
