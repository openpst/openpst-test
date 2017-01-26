#include "/.h"

DmVersionRequest::DmVersionRequest() : DmPacket()
{
	addField("version", kPacketFieldTypePrimitive, sizeof(uint16_t));
}

DmVersionRequest::~DmVersionRequest()
{

}

uint16_t DmVersionRequest::getVersion()
{
    return read<uint16_t>(getFieldOffset("version"));
}
                
void DmVersionRequest::setVersion(uint16_t version)
{
    write<uint16_t>("version", version);
}
