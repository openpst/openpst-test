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
* @file dm_efs_read_link_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_read_link_request.h"

using namespace OpenPST::Qualcomm;

DmEfsReadLinkRequest::DmEfsReadLinkRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsReadLink);

	setResponseExpected(true);
}

DmEfsReadLinkRequest::~DmEfsReadLinkRequest()
{

}

std::vector<uint8_t> DmEfsReadLinkRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                

void DmEfsReadLinkRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsReadLinkRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsReadLinkResponse* resp = new DmEfsReadLinkResponse();
		response = resp;
	}
}

void DmEfsReadLinkRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	DmEfsPacket::unpack(data, transport);
	//variable
}
