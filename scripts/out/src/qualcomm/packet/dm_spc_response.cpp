#include "/.h"

DmSpcResponse::DmSpcResponse() : DmPacket()
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));
}

DmSpcResponse::~DmSpcResponse()
{

}

uint8_t DmSpcResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void DmSpcResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}
