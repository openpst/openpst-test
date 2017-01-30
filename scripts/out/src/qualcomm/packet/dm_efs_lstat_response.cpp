/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_lstat_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_lstat_response.h"

using namespace OpenPST::QC;

DmEfsLstatResponse::DmEfsLstatResponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("atime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mtime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("ctime", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsLstatResponse::~DmEfsLstatResponse()
{

}

uint32_t DmEfsLstatResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsLstatResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
uint32_t DmEfsLstatResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void DmEfsLstatResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
uint32_t DmEfsLstatResponse::getAtime()
{
    return read<uint32_t>(getFieldOffset("atime"));
}
                
void DmEfsLstatResponse::setAtime(uint32_t atime)
{
    write<uint32_t>("atime", atime);
}
uint32_t DmEfsLstatResponse::getMtime()
{
    return read<uint32_t>(getFieldOffset("mtime"));
}
                
void DmEfsLstatResponse::setMtime(uint32_t mtime)
{
    write<uint32_t>("mtime", mtime);
}
uint32_t DmEfsLstatResponse::getCtime()
{
    return read<uint32_t>(getFieldOffset("ctime"));
}
                
void DmEfsLstatResponse::setCtime(uint32_t ctime)
{
    write<uint32_t>("ctime", ctime);
}

void DmEfsLstatResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
