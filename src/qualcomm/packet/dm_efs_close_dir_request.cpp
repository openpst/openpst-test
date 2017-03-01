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
* @file dm_efs_close_dir_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_close_dir_request.h"

using namespace OpenPST::Qualcomm;

DmEfsCloseDirRequest::DmEfsCloseDirRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("dp", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsCloseDir);
}

DmEfsCloseDirRequest::~DmEfsCloseDirRequest()
{

}

uint32_t DmEfsCloseDirRequest::getDp()
{
    return read<uint32_t>(getFieldOffset("dp"));
}
                
void DmEfsCloseDirRequest::setDp(uint32_t dp)
{
    write<uint32_t>("dp", dp);
}

void DmEfsCloseDirRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
}
void DmEfsCloseDirRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsCloseDirResponse* resp = new DmEfsCloseDirResponse();
		response = resp;
	}
}
