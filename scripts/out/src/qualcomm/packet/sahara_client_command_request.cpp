#include "/.h"

SaharaClientCommandRequest::SaharaClientCommandRequest() : SaharaPacket()
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint32_t));
}

SaharaClientCommandRequest::~SaharaClientCommandRequest()
{

}

uint32_t SaharaClientCommandRequest::getClientCommand()
{
    return read<uint32_t>(getFieldOffset("client_command"));
}
                
void SaharaClientCommandRequest::setClientCommand(uint32_t clientCommand)
{
    write<uint32_t>("client_command", clientCommand);
}
