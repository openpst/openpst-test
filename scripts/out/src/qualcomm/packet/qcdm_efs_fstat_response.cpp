/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_fstat_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_fstat_response.h"

QcdmEfsFstatResponse::QcdmEfsFstatResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("link_count", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("atime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mtime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("ctime", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsFstatResponse::~QcdmEfsFstatResponse()
{

}

uint32_t QcdmEfsFstatResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsFstatResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
uint32_t QcdmEfsFstatResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void QcdmEfsFstatResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
uint32_t QcdmEfsFstatResponse::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void QcdmEfsFstatResponse::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}
uint32_t QcdmEfsFstatResponse::getLinkCount()
{
    return read<uint32_t>(getFieldOffset("link_count"));
}
                
void QcdmEfsFstatResponse::setLinkCount(uint32_t linkCount)
{
    write<uint32_t>("link_count", linkCount);
}
uint32_t QcdmEfsFstatResponse::getAtime()
{
    return read<uint32_t>(getFieldOffset("atime"));
}
                
void QcdmEfsFstatResponse::setAtime(uint32_t atime)
{
    write<uint32_t>("atime", atime);
}
uint32_t QcdmEfsFstatResponse::getMtime()
{
    return read<uint32_t>(getFieldOffset("mtime"));
}
                
void QcdmEfsFstatResponse::setMtime(uint32_t mtime)
{
    write<uint32_t>("mtime", mtime);
}
uint32_t QcdmEfsFstatResponse::getCtime()
{
    return read<uint32_t>(getFieldOffset("ctime"));
}
                
void QcdmEfsFstatResponse::setCtime(uint32_t ctime)
{
    write<uint32_t>("ctime", ctime);
}

void QcdmEfsFstatResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

