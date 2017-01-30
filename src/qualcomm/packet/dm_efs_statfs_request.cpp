/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_statfs_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_statfs_request.h"

using namespace OpenPST::QC;

DmEfsStatfsRequest::DmEfsStatfsRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsStatfsRequest::~DmEfsStatfsRequest()
{

}

std::vector<uint8_t> DmEfsStatfsRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsStatfsRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsStatfsRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
