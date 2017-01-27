/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_open_file_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_open_file_response.h"

using namespace OpenPST::QC;

QcdmEfsOpenFileResponse::QcdmEfsOpenFileResponse() : DmEfsPacket()
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsOpenFileResponse::~QcdmEfsOpenFileResponse()
{

}

uint32_t QcdmEfsOpenFileResponse::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void QcdmEfsOpenFileResponse::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}
uint32_t QcdmEfsOpenFileResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsOpenFileResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsOpenFileResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}

