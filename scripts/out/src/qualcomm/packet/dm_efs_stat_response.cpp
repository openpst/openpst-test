/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_stat_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_stat_response.h"

using namespace OpenPST::QC;

DmEfsStatResponse::DmEfsStatResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("link_count", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("atime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mtime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("ctime", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsStatResponse::~DmEfsStatResponse()
{

}

uint32_t DmEfsStatResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsStatResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
uint32_t DmEfsStatResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void DmEfsStatResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
uint32_t DmEfsStatResponse::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void DmEfsStatResponse::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}
uint32_t DmEfsStatResponse::getLinkCount()
{
    return read<uint32_t>(getFieldOffset("link_count"));
}
                
void DmEfsStatResponse::setLinkCount(uint32_t linkCount)
{
    write<uint32_t>("link_count", linkCount);
}
uint32_t DmEfsStatResponse::getAtime()
{
    return read<uint32_t>(getFieldOffset("atime"));
}
                
void DmEfsStatResponse::setAtime(uint32_t atime)
{
    write<uint32_t>("atime", atime);
}
uint32_t DmEfsStatResponse::getMtime()
{
    return read<uint32_t>(getFieldOffset("mtime"));
}
                
void DmEfsStatResponse::setMtime(uint32_t mtime)
{
    write<uint32_t>("mtime", mtime);
}
uint32_t DmEfsStatResponse::getCtime()
{
    return read<uint32_t>(getFieldOffset("ctime"));
}
                
void DmEfsStatResponse::setCtime(uint32_t ctime)
{
    write<uint32_t>("ctime", ctime);
}

void DmEfsStatResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
