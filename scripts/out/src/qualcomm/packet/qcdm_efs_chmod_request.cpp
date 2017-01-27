/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_chmod_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_chmod_request.h"

using namespace OpenPST::QC;

QcdmEfsChmodRequest::QcdmEfsChmodRequest() : DmEfsPacket()
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypeVariant, 0);

}

QcdmEfsChmodRequest::~QcdmEfsChmodRequest()
{

}

uint32_t QcdmEfsChmodRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void QcdmEfsChmodRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
std::vector<uint8_t> QcdmEfsChmodRequest::getPath()
{
	return readV(getFieldSize("path"), getFieldOffset("path"));
}
                
void QcdmEfsChmodRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void QcdmEfsChmodRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

