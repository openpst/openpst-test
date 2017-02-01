/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_rename_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_rename_request.h"

using namespace OpenPST::QC;

DmEfsRenameRequest::DmEfsRenameRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("path", kPacketFieldTypeVariant, 0);
	addField("new_path", kPacketFieldTypeVariant, 0);

}

DmEfsRenameRequest::~DmEfsRenameRequest()
{

}

std::vector<uint8_t> DmEfsRenameRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsRenameRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}
std::vector<uint8_t> DmEfsRenameRequest::getNewPath()
{
	return read(getFieldSize("new_path"), getFieldOffset("new_path"));
}
                
void DmEfsRenameRequest::setNewPath(uint8_t* data, size_t size)
{
    write("new_path", data, size);
}

void DmEfsRenameRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
