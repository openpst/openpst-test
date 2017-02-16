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
* @file dm_spc_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_spc_request.h"

using namespace OpenPST::QC;

DmSpcRequest::DmSpcRequest(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("spc", kPacketFieldTypeArray, DIAG_SPC_LENGTH);

	setCommand(kDiagSpc);
}

DmSpcRequest::~DmSpcRequest()
{

}

std::vector<uint8_t> DmSpcRequest::getSpc()
{
	return read(getFieldSize("spc"), getFieldOffset("spc"));
}
                
void DmSpcRequest::setSpc(uint8_t* data, size_t size)
{
    write("spc", data, size);
}

void DmSpcRequest::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}
void DmSpcRequest::prepareResponse()
{
	if (response == nullptr) {
		DmSpcResponse* resp = new DmSpcResponse();
		response = resp;
	}
}
