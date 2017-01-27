/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_stat_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_stat_response.h"

using namespace OpenPST::QC;

QcdmEfsStatResponse::QcdmEfsStatResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("link_count", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("atime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mtime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("ctime", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsStatResponse::~QcdmEfsStatResponse()
{

}

uint32_t QcdmEfsStatResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsStatResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
uint32_t QcdmEfsStatResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void QcdmEfsStatResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
uint32_t QcdmEfsStatResponse::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void QcdmEfsStatResponse::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}
uint32_t QcdmEfsStatResponse::getLinkCount()
{
    return read<uint32_t>(getFieldOffset("link_count"));
}
                
void QcdmEfsStatResponse::setLinkCount(uint32_t linkCount)
{
    write<uint32_t>("link_count", linkCount);
}
uint32_t QcdmEfsStatResponse::getAtime()
{
    return read<uint32_t>(getFieldOffset("atime"));
}
                
void QcdmEfsStatResponse::setAtime(uint32_t atime)
{
    write<uint32_t>("atime", atime);
}
uint32_t QcdmEfsStatResponse::getMtime()
{
    return read<uint32_t>(getFieldOffset("mtime"));
}
                
void QcdmEfsStatResponse::setMtime(uint32_t mtime)
{
    write<uint32_t>("mtime", mtime);
}
uint32_t QcdmEfsStatResponse::getCtime()
{
    return read<uint32_t>(getFieldOffset("ctime"));
}
                
void QcdmEfsStatResponse::setCtime(uint32_t ctime)
{
    write<uint32_t>("ctime", ctime);
}

void QcdmEfsStatResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

