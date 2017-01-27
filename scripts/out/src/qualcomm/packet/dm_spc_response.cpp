/**
* LICENSE PLACEHOLDER
*
* @file dm_spc_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_spc_response.h"

using namespace OpenPST::QC;

DmSpcResponse::DmSpcResponse() : DmPacket()
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

}

DmSpcResponse::~DmSpcResponse()
{

}

uint8_t DmSpcResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void DmSpcResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void DmSpcResponse::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}

