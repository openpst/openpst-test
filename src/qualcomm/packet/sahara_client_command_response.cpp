/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_client_command_response.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_client_command_response.h"

using namespace OpenPST::Qualcomm;

SaharaClientCommandResponse::SaharaClientCommandResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data_size", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandExecuteResponse);

	setResponseExpected(false);
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

uint32_t SaharaClientCommandResponse::getDataSize()
{
    return read<uint32_t>(getFieldOffset("data_size"));
}
                

void SaharaClientCommandResponse::setDataSize(uint32_t dataSize)
{
    write<uint32_t>("data_size", dataSize);
}

void SaharaClientCommandResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	SaharaPacket::unpack(data, transport);
	setClientCommand(read<uint32_t>(data, getFieldOffset("client_command")));
	setDataSize(read<uint32_t>(data, getFieldOffset("data_size")));
}
