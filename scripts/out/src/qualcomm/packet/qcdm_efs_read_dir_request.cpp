/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_read_dir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_read_dir_request.h"

QcdmEfsReadDirRequest::QcdmEfsReadDirRequest() : DmEfsPacket()
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("sequence_number", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsReadDirRequest::~QcdmEfsReadDirRequest()
{

}

uint32_t QcdmEfsReadDirRequest::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                
void QcdmEfsReadDirRequest::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}
uint32_t QcdmEfsReadDirRequest::getSequenceNumber()
{
    return read<uint32_t>(getFieldOffset("sequence_number"));
}
                
void QcdmEfsReadDirRequest::setSequenceNumber(uint32_t sequenceNumber)
{
    write<uint32_t>("sequence_number", sequenceNumber);
}

void QcdmEfsReadDirRequest::unpack(std::vector<uint8_t>& data)
{
	
}