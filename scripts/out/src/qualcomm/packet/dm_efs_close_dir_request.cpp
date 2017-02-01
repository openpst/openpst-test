/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_close_dir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_close_dir_request.h"

using namespace OpenPST::QC;

DmEfsCloseDirRequest::DmEfsCloseDirRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsCloseDirRequest::~DmEfsCloseDirRequest()
{

}

uint32_t DmEfsCloseDirRequest::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                
void DmEfsCloseDirRequest::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}

void DmEfsCloseDirRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
