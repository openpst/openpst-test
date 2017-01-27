/**
* LICENSE PLACEHOLDER
*
* @file dm_password_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_password_response.h"

using namespace OpenPST::QC;

DmPasswordResponse::DmPasswordResponse() : DmPacket()
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

}

DmPasswordResponse::~DmPasswordResponse()
{

}

uint8_t DmPasswordResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void DmPasswordResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void DmPasswordResponse::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}

