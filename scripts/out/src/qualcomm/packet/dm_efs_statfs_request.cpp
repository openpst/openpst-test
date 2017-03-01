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
* @file dm_efs_statfs_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_statfs_request.h"

using namespace OpenPST::Qualcomm;

DmEfsStatfsRequest::DmEfsStatfsRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsStatFS);
}

DmEfsStatfsRequest::~DmEfsStatfsRequest()
{

}

std::vector<uint8_t> DmEfsStatfsRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsStatfsRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsStatfsRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsStatfsResponse* resp = new DmEfsStatfsResponse();
		response = resp;
	}
}

void DmEfsStatfsRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	//variable
}
