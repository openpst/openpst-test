/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_close_file_reponse.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/qcdm_efs_close_file_reponse.h"

QcdmEfsCloseFileReponse::QcdmEfsCloseFileReponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

QcdmEfsCloseFileReponse::~QcdmEfsCloseFileReponse()
{

}

uint32_t QcdmEfsCloseFileReponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void QcdmEfsCloseFileReponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void QcdmEfsCloseFileReponse::unpack(std::vector<uint8_t>& data)
{
	
}