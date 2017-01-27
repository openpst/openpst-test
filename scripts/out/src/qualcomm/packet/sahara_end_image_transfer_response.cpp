/**
* LICENSE PLACEHOLDER
*
* @file sahara_end_image_transfer_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_end_image_transfer_response.h"

SaharaEndImageTransferResponse::SaharaEndImageTransferResponse() : SaharaPacket()
{
	addField("image_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("status", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandEndImageTransfer);
}

SaharaEndImageTransferResponse::~SaharaEndImageTransferResponse()
{

}

uint32_t SaharaEndImageTransferResponse::getImageId()
{
    return read<uint32_t>(getFieldOffset("image_id"));
}
                
void SaharaEndImageTransferResponse::setImageId(uint32_t imageId)
{
    write<uint32_t>("image_id", imageId);
}
uint32_t SaharaEndImageTransferResponse::getStatus()
{
    return read<uint32_t>(getFieldOffset("status"));
}
                
void SaharaEndImageTransferResponse::setStatus(uint32_t status)
{
    write<uint32_t>("status", status);
}

void SaharaEndImageTransferResponse::unpack(std::vector<uint8_t>& data)
{
}

