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
* @file dm_efs_access_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_access_request.h"

using namespace OpenPST::Qualcomm;

DmEfsAccessRequest::DmEfsAccessRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("permission_mask", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsAccess);

	setResponseExpected(true);
}

DmEfsAccessRequest::~DmEfsAccessRequest()
{

}

uint32_t DmEfsAccessRequest::getPermissionMask()
{
    return read<uint32_t>(getFieldOffset("permission_mask"));
}
                

void DmEfsAccessRequest::setPermissionMask(uint32_t permissionMask)
{
    write<uint32_t>("permission_mask", permissionMask);
}

std::vector<uint8_t> DmEfsAccessRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                

void DmEfsAccessRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsAccessRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsAccessResponse* resp = new DmEfsAccessResponse();
		response = resp;
	}
}

void DmEfsAccessRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setPermissionMask(read<uint32_t>(data, getFieldOffset("permission_mask")));
	//variable
}
