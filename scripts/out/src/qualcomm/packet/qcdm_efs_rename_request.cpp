/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_rename_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_rename_request.h"

QcdmEfsRenameRequest::QcdmEfsRenameRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypePrimitive, sizeof(variable));
	addField("new_path", kPacketFieldTypePrimitive, sizeof(variable));

}

QcdmEfsRenameRequest::~QcdmEfsRenameRequest()
{

}

std::vector<uint8_t> QcdmEfsRenameRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsRenameRequest::setPath(uint8_t* data, size_t size);
{
    write("path", data, size);
}
std::vector<uint8_t> QcdmEfsRenameRequest::getNewPath()
{
	return read(getFieldSize("new_path"), getFieldOffset("new_path"));
}
                
void QcdmEfsRenameRequest::setNewPath(uint8_t* data, size_t size);
{
    write("new_path", data, size);
}

void QcdmEfsRenameRequest::unpack(std::vector<uint8_t>& data)
{
	
}