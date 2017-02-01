/**
* LICENSE PLACEHOLDER
*
* @file dm_version_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_version_request.h"

using namespace OpenPST::QC;

DmVersionRequest::DmVersionRequest(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("version", kPacketFieldTypePrimitive, sizeof(uint16_t));

}

DmVersionRequest::~DmVersionRequest()
{

}

uint16_t DmVersionRequest::getVersion()
{
    return read<uint16_t>(getFieldOffset("version"));
}
                
void DmVersionRequest::setVersion(uint16_t version)
{
    write<uint16_t>("version", version);
}

void DmVersionRequest::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}
