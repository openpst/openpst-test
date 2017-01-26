#include "/.h"

SaharaCommandReadyResponse::SaharaCommandReadyResponse() : SaharaPacket()
{
	addField("image_tx_status", kPacketFieldTypePrimitive, sizeof(uint32_t));
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
