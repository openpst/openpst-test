#include "/.h"

DmPhoneModeRequest::DmPhoneModeRequest() : DmPacket()
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("padding", kPacketFieldTypePrimitive, sizeof(uint8_t));
}

DmPhoneModeRequest::~DmPhoneModeRequest()
{

}

uint8_t DmPhoneModeRequest::getMode()
{
    return read<uint8_t>(getFieldOffset("mode"));
}
                
void DmPhoneModeRequest::setMode(uint8_t mode)
{
    write<uint8_t>("mode", mode);
}
uint8_t DmPhoneModeRequest::getPadding()
{
    return read<uint8_t>(getFieldOffset("padding"));
}
                
void DmPhoneModeRequest::setPadding(uint8_t padding)
{
    write<uint8_t>("padding", padding);
}
