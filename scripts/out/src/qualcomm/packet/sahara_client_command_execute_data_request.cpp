/**
* LICENSE PLACEHOLDER
*
* @file sahara_client_command_execute_data_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_client_command_execute_data_request.h"

using namespace OpenPST::QC;

SaharaClientCommandExecuteDataRequest::SaharaClientCommandExecuteDataRequest() : SaharaPacket()
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandExecuteData);
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

void SaharaClientCommandExecuteDataRequest::unpack(std::vector<uint8_t>& data)
{
}

