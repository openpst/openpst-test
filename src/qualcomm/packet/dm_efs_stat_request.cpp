/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_stat_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_stat_request.h"

using namespace OpenPST::QC;

DmEfsStatRequest::DmEfsStatRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsStatRequest::~DmEfsStatRequest()
{

}

std::vector<uint8_t> DmEfsStatRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsStatRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsStatRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
