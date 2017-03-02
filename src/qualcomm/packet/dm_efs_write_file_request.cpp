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
* @file dm_efs_write_file_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_write_file_request.h"

using namespace OpenPST::Qualcomm;

DmEfsWriteFileRequest::DmEfsWriteFileRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsWrite);

	setResponseExpected(true);
}

DmEfsWriteFileRequest::~DmEfsWriteFileRequest()
{

}

uint32_t DmEfsWriteFileRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                

void DmEfsWriteFileRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}

uint32_t DmEfsWriteFileRequest::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                

void DmEfsWriteFileRequest::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}

std::vector<uint8_t> DmEfsWriteFileRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                

void DmEfsWriteFileRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void DmEfsWriteFileRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsWriteFileResponse* resp = new DmEfsWriteFileResponse();
		response = resp;
	}
}

void DmEfsWriteFileRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	DmEfsPacket::unpack(data, transport);
	setFp(read<uint32_t>(data, getFieldOffset("fp")));
	setOffset(read<uint32_t>(data, getFieldOffset("offset")));
	//variable
}
