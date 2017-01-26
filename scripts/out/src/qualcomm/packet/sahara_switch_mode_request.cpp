#include "/.h"

SaharaSwitchModeRequest::SaharaSwitchModeRequest() : SaharaPacket()
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
}

SaharaSwitchModeRequest::~SaharaSwitchModeRequest()
{

}

uint32_t SaharaSwitchModeRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void SaharaSwitchModeRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
