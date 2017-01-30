/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_read_file_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_read_file_request.h"

using namespace OpenPST::QC;

DmEfsReadFileRequest::DmEfsReadFileRequest() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsReadFileRequest::~DmEfsReadFileRequest()
{

}

uint32_t DmEfsReadFileRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void DmEfsReadFileRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}
uint32_t DmEfsReadFileRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void DmEfsReadFileRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}
uint32_t DmEfsReadFileRequest::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                
void DmEfsReadFileRequest::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}

void DmEfsReadFileRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
