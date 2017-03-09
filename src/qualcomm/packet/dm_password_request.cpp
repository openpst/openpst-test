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
* @file dm_password_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_password_request.h"

using namespace OpenPST::Qualcomm;

DmPasswordRequest::DmPasswordRequest(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("password", kPacketFieldTypeArray, DIAG_PASSWORD_LENGTH);

	setCommand(kDiagPassword);

	setResponseExpected(false);
}

DmPasswordRequest::~DmPasswordRequest()
{

}

std::vector<uint8_t> DmPasswordRequest::getPassword()
{
	return read(getFieldSize("password"), getFieldOffset("password"));
}

std::string DmPasswordRequest::getPassword()
{
	return getString(8, getFieldOffset("password"));
}
                

void DmPasswordRequest::setPassword(uint8_t* data, size_t size)
{
    write("password", data, size);
}

void DmPasswordRequest::setPassword(const std::string& password)
{
    write("password", password);
}

void DmPasswordRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmPacket::unpack(data, transport);
	//uint8_t[]
}
