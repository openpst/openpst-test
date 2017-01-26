#include "/.h"

SaharaClientCommandResponse::SaharaClientCommandResponse() : SaharaPacket()
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
}

SaharaClientCommandResponse::~SaharaClientCommandResponse()
{

}

uint32_t SaharaClientCommandResponse::getClientCommand()
{
    return read<uint32_t>(getFieldOffset("client_command"));
}
                
void SaharaClientCommandResponse::setClientCommand(uint32_t clientCommand)
{
    write<uint32_t>("client_command", clientCommand);
}
uint32_t SaharaClientCommandResponse::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaClientCommandResponse::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}
