/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_access_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_access_response.h"

using namespace OpenPST::QC;

DmEfsAccessResponse::DmEfsAccessResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsAccessResponse::~DmEfsAccessResponse()
{

}

uint32_t DmEfsAccessResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsAccessResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsAccessResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
