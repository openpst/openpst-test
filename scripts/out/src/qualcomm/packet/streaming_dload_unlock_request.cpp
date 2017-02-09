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
* @file streaming_dload_unlock_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unlock_request.h"

using namespace OpenPST::QC;

StreamingDloadUnlockRequest::StreamingDloadUnlockRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("code", kPacketFieldTypePrimitive, sizeof(uint64_t));

	setCommand(kStreamingDloadUnlock);
}

StreamingDloadUnlockRequest::~StreamingDloadUnlockRequest()
{

}

uint64_t StreamingDloadUnlockRequest::getCode()
{
    return read<uint64_t>(getFieldOffset("code"));
}
                
void StreamingDloadUnlockRequest::setCode(uint64_t code)
{
    write<uint64_t>("code", code);
}

void StreamingDloadUnlockRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadUnlockRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadUnlockResponse* resp = new StreamingDloadUnlockResponse();
		response = resp;
	}
}
