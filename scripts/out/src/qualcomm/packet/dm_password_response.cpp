#include "/.h"

DmPasswordResponse::DmPasswordResponse() : DmPacket()
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));
}

DmPasswordResponse::~DmPasswordResponse()
{

}

uint8_t DmPasswordResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void DmPasswordResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}
