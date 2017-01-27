/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_close_file_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_close_file_request.h"

using namespace OpenPST::QC;

QcdmEfsCloseFileRequest::QcdmEfsCloseFileRequest() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsCloseFileRequest::~QcdmEfsCloseFileRequest()
{

}

uint32_t QcdmEfsCloseFileRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void QcdmEfsCloseFileRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}

void QcdmEfsCloseFileRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

