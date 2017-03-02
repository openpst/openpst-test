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
* @file dm_efs_get_group_info_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_get_group_info_request.h"

using namespace OpenPST::Qualcomm;

DmEfsGetGroupInfoRequest::DmEfsGetGroupInfoRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("gid", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsGetGroupInfo);

	setResponseExpected(true);
}

DmEfsGetGroupInfoRequest::~DmEfsGetGroupInfoRequest()
{

}

uint32_t DmEfsGetGroupInfoRequest::getGid()
{
    return read<uint32_t>(getFieldOffset("gid"));
}
                

void DmEfsGetGroupInfoRequest::setGid(uint32_t gid)
{
    write<uint32_t>("gid", gid);
}

std::vector<uint8_t> DmEfsGetGroupInfoRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                

void DmEfsGetGroupInfoRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsGetGroupInfoRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsGetGroupInfoResponse* resp = new DmEfsGetGroupInfoResponse();
		response = resp;
	}
}

void DmEfsGetGroupInfoRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	DmEfsPacket::unpack(data, transport);
	setGid(read<uint32_t>(data, getFieldOffset("gid")));
	//variable
}
