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
* @file sahara_done_response.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_done_response.h"

using namespace OpenPST::Qualcomm;

SaharaDoneResponse::SaharaDoneResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{

	setCommand(kSaharaCommandDoneResponse);

	setResponseExpected(false);
}

SaharaDoneResponse::~SaharaDoneResponse()
{

}

void SaharaDoneResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	SaharaPacket::unpack(data, transport);
}
