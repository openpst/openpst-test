/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_close_file_reponse.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_close_file_reponse.h"

using namespace OpenPST::QC;

DmEfsCloseFileReponse::DmEfsCloseFileReponse() : DmEfsPacket()
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsCloseFileReponse::~DmEfsCloseFileReponse()
{

}

uint32_t DmEfsCloseFileReponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsCloseFileReponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsCloseFileReponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
