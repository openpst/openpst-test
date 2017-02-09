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
* @file sahara_command_memory_debug64_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_command_memory_debug64_request.h"

using namespace OpenPST::QC;

SaharaCommandMemoryDebug64Request::SaharaCommandMemoryDebug64Request(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint64_t));

	setCommand(kSaharaCommandMemoryRead64);
}

SaharaCommandMemoryDebug64Request::~SaharaCommandMemoryDebug64Request()
{

}

uint64_t SaharaCommandMemoryDebug64Request::getClientCommand()
{
    return read<uint64_t>(getFieldOffset("client_command"));
}
                
void SaharaCommandMemoryDebug64Request::setClientCommand(uint64_t clientCommand)
{
    write<uint64_t>("client_command", clientCommand);
}

void SaharaCommandMemoryDebug64Request::unpack(std::vector<uint8_t>& data)
{
}
