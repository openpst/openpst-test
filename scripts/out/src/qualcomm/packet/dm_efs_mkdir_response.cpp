/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_mkdir_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_mkdir_response.h"

using namespace OpenPST::QC;

DmEfsMkdirResponse::DmEfsMkdirResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsMkdirResponse::~DmEfsMkdirResponse()
{

}

uint32_t DmEfsMkdirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsMkdirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsMkdirResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
