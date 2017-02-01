/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_rename_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_rename_response.h"

using namespace OpenPST::QC;

DmEfsRenameResponse::DmEfsRenameResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsRenameResponse::~DmEfsRenameResponse()
{

}

uint32_t DmEfsRenameResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsRenameResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsRenameResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
