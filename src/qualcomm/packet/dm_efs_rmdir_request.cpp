/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_rmdir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_rmdir_request.h"

using namespace OpenPST::QC;

DmEfsRmdirRequest::DmEfsRmdirRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

DmEfsRmdirRequest::~DmEfsRmdirRequest()
{

}

std::vector<uint8_t> DmEfsRmdirRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsRmdirRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsRmdirRequest::unpack(std::vector<uint8_t>& data)
{
}
