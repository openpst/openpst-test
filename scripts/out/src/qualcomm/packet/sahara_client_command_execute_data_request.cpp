#include "/.h"

SaharaClientCommandExecuteDataRequest::SaharaClientCommandExecuteDataRequest() : SaharaPacket()
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint32_t));
}

SaharaClientCommandExecuteDataRequest::~SaharaClientCommandExecuteDataRequest()
{

}

uint32_t SaharaClientCommandExecuteDataRequest::getClientCommand()
{
    return read<uint32_t>(getFieldOffset("client_command"));
}
                
void SaharaClientCommandExecuteDataRequest::setClientCommand(uint32_t clientCommand)
{
    write<uint32_t>("client_command", clientCommand);
}
