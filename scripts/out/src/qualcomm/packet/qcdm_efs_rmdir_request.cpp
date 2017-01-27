/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_rmdir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_rmdir_request.h"

using namespace OpenPST::QC;

QcdmEfsRmdirRequest::QcdmEfsRmdirRequest() : DmEfsPacket()
{
	addField("path", kPacketFieldTypeVariant, 0);

}

QcdmEfsRmdirRequest::~QcdmEfsRmdirRequest()
{

}

std::vector<uint8_t> QcdmEfsRmdirRequest::getPath()
{
	return readV(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsRmdirRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void QcdmEfsRmdirRequest::unpack(std::vector<uint8_t>& data)
{
}

