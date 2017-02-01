/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_chmod_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_chmod_response.h"

using namespace OpenPST::QC;

DmEfsChmodResponse::DmEfsChmodResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsChmodResponse::~DmEfsChmodResponse()
{

}

uint32_t DmEfsChmodResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsChmodResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsChmodResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
