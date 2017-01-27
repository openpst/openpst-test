/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_read_dir_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_read_dir_response.h"

QcdmEfsReadDirResponse::QcdmEfsReadDirResponse() : DmEfsPacket()
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("sequence_number", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("entry_type", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("atime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mtime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("ctime", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("name", kPacketFieldTypePrimitive, sizeof(variable));

}

QcdmEfsReadDirResponse::~QcdmEfsReadDirResponse()
{

}

uint32_t QcdmEfsReadDirResponse::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                
void QcdmEfsReadDirResponse::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}
uint32_t QcdmEfsReadDirResponse::getSequenceNumber()
{
    return read<uint32_t>(getFieldOffset("sequence_number"));
}
                
void QcdmEfsReadDirResponse::setSequenceNumber(uint32_t sequenceNumber)
{
    write<uint32_t>("sequence_number", sequenceNumber);
}
uint32_t QcdmEfsReadDirResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsReadDirResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
uint32_t QcdmEfsReadDirResponse::getEntryType()
{
    return read<uint32_t>(getFieldOffset("entry_type"));
}
                
void QcdmEfsReadDirResponse::setEntryType(uint32_t entryType)
{
    write<uint32_t>("entry_type", entryType);
}
uint32_t QcdmEfsReadDirResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void QcdmEfsReadDirResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
uint32_t QcdmEfsReadDirResponse::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void QcdmEfsReadDirResponse::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}
uint32_t QcdmEfsReadDirResponse::getAtime()
{
    return read<uint32_t>(getFieldOffset("atime"));
}
                
void QcdmEfsReadDirResponse::setAtime(uint32_t atime)
{
    write<uint32_t>("atime", atime);
}
uint32_t QcdmEfsReadDirResponse::getMtime()
{
    return read<uint32_t>(getFieldOffset("mtime"));
}
                
void QcdmEfsReadDirResponse::setMtime(uint32_t mtime)
{
    write<uint32_t>("mtime", mtime);
}
uint32_t QcdmEfsReadDirResponse::getCtime()
{
    return read<uint32_t>(getFieldOffset("ctime"));
}
                
void QcdmEfsReadDirResponse::setCtime(uint32_t ctime)
{
    write<uint32_t>("ctime", ctime);
}
std::vector<uint8_t> QcdmEfsReadDirResponse::getName()
{
	return read(getFieldSize("name"), getFieldOffset("name"));
}
                
void QcdmEfsReadDirResponse::setName(uint8_t* data, size_t size);
{
    write("name", data, size);
}

void QcdmEfsReadDirResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

