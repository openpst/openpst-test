/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_mkdir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_mkdir_request.h"

using namespace OpenPST::QC;

DmEfsMkdirRequest::DmEfsMkdirRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsMkdirRequest::~DmEfsMkdirRequest()
{

}

uint32_t DmEfsMkdirRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void DmEfsMkdirRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
std::vector<uint8_t> DmEfsMkdirRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsMkdirRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsMkdirRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
