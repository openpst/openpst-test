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

using namespace OpenPST::QC;

QcdmEfsRenameRequest::QcdmEfsRenameRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);
	addField("new_path", kPacketFieldTypeVariant, 0);

}

QcdmEfsRenameRequest::~QcdmEfsRenameRequest()
{

}

std::vector<uint8_t> QcdmEfsRenameRequest::getPath()
{
	return readV(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsRenameRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}
std::vector<uint8_t> QcdmEfsRenameRequest::getNewPath()
{
	return readV(getFieldSize("new_path"), getFieldOffset("new_path"));
}
                
void QcdmEfsRenameRequest::setNewPath(uint8_t* data, size_t size)
{
    write("new_path", data, size);
}

void QcdmEfsRenameRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

