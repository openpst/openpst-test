/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_chmod_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_chmod_request.h"

using namespace OpenPST::QC;

DmEfsChmodRequest::DmEfsChmodRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsChmodRequest::~DmEfsChmodRequest()
{

}

uint32_t DmEfsChmodRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void DmEfsChmodRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
std::vector<uint8_t> DmEfsChmodRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsChmodRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsChmodRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
