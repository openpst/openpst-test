/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_rmdir_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_rmdir_response.h"

using namespace OpenPST::QC;

DmEfsRmdirResponse::DmEfsRmdirResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsRmdirResponse::~DmEfsRmdirResponse()
{

}

uint32_t DmEfsRmdirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsRmdirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsRmdirResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
