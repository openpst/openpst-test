/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_fstat_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_fstat_request.h"

using namespace OpenPST::QC;

DmEfsFstatRequest::DmEfsFstatRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsFstatRequest::~DmEfsFstatRequest()
{

}

uint32_t DmEfsFstatRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void DmEfsFstatRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}

void DmEfsFstatRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
