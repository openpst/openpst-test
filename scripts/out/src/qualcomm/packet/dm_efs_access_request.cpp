/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_access_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_access_request.h"

using namespace OpenPST::QC;

DmEfsAccessRequest::DmEfsAccessRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("permission_mask", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsAccessRequest::~DmEfsAccessRequest()
{

}

uint32_t DmEfsAccessRequest::getPermissionMask()
{
    return read<uint32_t>(getFieldOffset("permission_mask"));
}
                
void DmEfsAccessRequest::setPermissionMask(uint32_t permissionMask)
{
    write<uint32_t>("permission_mask", permissionMask);
}
std::vector<uint8_t> DmEfsAccessRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsAccessRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsAccessRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
