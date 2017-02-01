/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_read_dir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_read_dir_request.h"

using namespace OpenPST::QC;

DmEfsReadDirRequest::DmEfsReadDirRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("sequence_number", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsReadDirRequest::~DmEfsReadDirRequest()
{

}

uint32_t DmEfsReadDirRequest::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                
void DmEfsReadDirRequest::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}
uint32_t DmEfsReadDirRequest::getSequenceNumber()
{
    return read<uint32_t>(getFieldOffset("sequence_number"));
}
                
void DmEfsReadDirRequest::setSequenceNumber(uint32_t sequenceNumber)
{
    write<uint32_t>("sequence_number", sequenceNumber);
}

void DmEfsReadDirRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
