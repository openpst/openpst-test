/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_open_dir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_open_dir_request.h"

using namespace OpenPST::QC;

DmEfsOpenDirRequest::DmEfsOpenDirRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsOpenDirRequest::~DmEfsOpenDirRequest()
{

}

std::vector<uint8_t> DmEfsOpenDirRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsOpenDirRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsOpenDirRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
