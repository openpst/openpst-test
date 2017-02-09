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
* @file sahara_client_command_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_client_command_request.h"

using namespace OpenPST::QC;

SaharaClientCommandRequest::SaharaClientCommandRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
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
