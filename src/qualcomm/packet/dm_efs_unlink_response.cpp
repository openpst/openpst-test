/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_unlink_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_unlink_response.h"

using namespace OpenPST::QC;

DmEfsUnlinkResponse::DmEfsUnlinkResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsUnlinkResponse::~DmEfsUnlinkResponse()
{

}

uint32_t DmEfsUnlinkResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsUnlinkResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsUnlinkResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
