/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_access_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_access_request.h"

QcdmEfsAccessRequest::QcdmEfsAccessRequest() : DmEfsPacket()
{
	addField("permission_mask", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypePrimitive, sizeof(variable));

}

QcdmEfsAccessRequest::~QcdmEfsAccessRequest()
{

}

uint32_t QcdmEfsAccessRequest::getPermissionMask()
{
    return read<uint32_t>(getFieldOffset("permission_mask"));
}
                
void QcdmEfsAccessRequest::setPermissionMask(uint32_t permissionMask)
{
    write<uint32_t>("permission_mask", permissionMask);
}
std::vector<uint8_t> QcdmEfsAccessRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsAccessRequest::setPath(uint8_t* data, size_t size);
{
    write("path", data, size);
}

void QcdmEfsAccessRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

