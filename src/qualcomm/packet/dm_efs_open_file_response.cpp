/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_open_file_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_open_file_response.h"

using namespace OpenPST::QC;

DmEfsOpenFileResponse::DmEfsOpenFileResponse() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsOpenFileResponse::~DmEfsOpenFileResponse()
{

}

uint32_t DmEfsOpenFileResponse::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void DmEfsOpenFileResponse::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}
uint32_t DmEfsOpenFileResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsOpenFileResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsOpenFileResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
