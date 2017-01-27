/**
* LICENSE PLACEHOLDER
*
* @file sahara_command_ready_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_command_ready_response.h"

using namespace OpenPST::QC;

SaharaCommandReadyResponse::SaharaCommandReadyResponse() : SaharaPacket()
{
	addField("image_tx_status", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandReady);
}

SaharaCommandReadyResponse::~SaharaCommandReadyResponse()
{

}

uint32_t SaharaCommandReadyResponse::getImageTxStatus()
{
    return read<uint32_t>(getFieldOffset("image_tx_status"));
}
                
void SaharaCommandReadyResponse::setImageTxStatus(uint32_t imageTxStatus)
{
    write<uint32_t>("image_tx_status", imageTxStatus);
}

void SaharaCommandReadyResponse::unpack(std::vector<uint8_t>& data)
{
}

