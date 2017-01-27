/**
* LICENSE PLACEHOLDER
*
* @file sahara_client_command_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_client_command_request.h"

SaharaClientCommandRequest::SaharaClientCommandRequest() : SaharaPacket()
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandExecute);
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

void SaharaClientCommandRequest::unpack(std::vector<uint8_t>& data)
{
}

