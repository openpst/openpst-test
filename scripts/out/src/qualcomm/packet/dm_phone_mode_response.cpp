#include "/.h"

DmPhoneModeResponse::DmPhoneModeResponse() : DmPacket()
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));
}

DmPhoneModeResponse::~DmPhoneModeResponse()
{

}

uint8_t DmPhoneModeResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void DmPhoneModeResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}
