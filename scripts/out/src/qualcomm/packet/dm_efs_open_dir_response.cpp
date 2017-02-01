/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_open_dir_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_open_dir_response.h"

using namespace OpenPST::QC;

DmEfsOpenDirResponse::DmEfsOpenDirResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsOpenDirResponse::~DmEfsOpenDirResponse()
{

}

uint32_t DmEfsOpenDirResponse::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                
void DmEfsOpenDirResponse::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}
uint32_t DmEfsOpenDirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsOpenDirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsOpenDirResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
