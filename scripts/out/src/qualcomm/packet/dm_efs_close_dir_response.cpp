/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_close_dir_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_close_dir_response.h"

using namespace OpenPST::QC;

DmEfsCloseDirResponse::DmEfsCloseDirResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsCloseDirResponse::~DmEfsCloseDirResponse()
{

}

uint32_t DmEfsCloseDirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsCloseDirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsCloseDirResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
