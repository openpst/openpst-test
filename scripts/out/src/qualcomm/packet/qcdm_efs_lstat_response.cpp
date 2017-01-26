/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_lstat_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_lstat_response.h"

QcdmEfsLstatResponse::QcdmEfsLstatResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("atime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mtime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("ctime", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsLstatResponse::~QcdmEfsLstatResponse()
{

}

uint32_t QcdmEfsLstatResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsLstatResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
uint32_t QcdmEfsLstatResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void QcdmEfsLstatResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
uint32_t QcdmEfsLstatResponse::getAtime()
{
    return read<uint32_t>(getFieldOffset("atime"));
}
                
void QcdmEfsLstatResponse::setAtime(uint32_t atime)
{
    write<uint32_t>("atime", atime);
}
uint32_t QcdmEfsLstatResponse::getMtime()
{
    return read<uint32_t>(getFieldOffset("mtime"));
}
                
void QcdmEfsLstatResponse::setMtime(uint32_t mtime)
{
    write<uint32_t>("mtime", mtime);
}
uint32_t QcdmEfsLstatResponse::getCtime()
{
    return read<uint32_t>(getFieldOffset("ctime"));
}
                
void QcdmEfsLstatResponse::setCtime(uint32_t ctime)
{
    write<uint32_t>("ctime", ctime);
}

void QcdmEfsLstatResponse::unpack(std::vector<uint8_t>& data)
{
	
}