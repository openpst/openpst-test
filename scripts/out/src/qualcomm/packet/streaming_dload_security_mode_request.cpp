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
* @file streaming_dload_security_mode_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_security_mode_request.h"

using namespace OpenPST::QC;

StreamingDloadSecurityModeRequest::StreamingDloadSecurityModeRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadSecurityMode);
}

StreamingDloadSecurityModeRequest::~StreamingDloadSecurityModeRequest()
{

}

uint8_t StreamingDloadSecurityModeRequest::getMode()
{
    return read<uint8_t>(getFieldOffset("mode"));
}
                
void StreamingDloadSecurityModeRequest::setMode(uint8_t mode)
{
    write<uint8_t>("mode", mode);
}

void StreamingDloadSecurityModeRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadSecurityModeRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadSecurityModeResponse* resp = new StreamingDloadSecurityModeResponse();
		response = resp;
	}
}
