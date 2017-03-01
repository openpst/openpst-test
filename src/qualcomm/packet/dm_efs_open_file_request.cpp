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
* @file dm_efs_open_file_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_open_file_request.h"

using namespace OpenPST::Qualcomm;

DmEfsOpenFileRequest::DmEfsOpenFileRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("flags", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("file_path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsOpen);
}

DmEfsOpenFileRequest::~DmEfsOpenFileRequest()
{

}

uint32_t DmEfsOpenFileRequest::getFlags()
{
    return read<uint32_t>(getFieldOffset("flags"));
}
                
void DmEfsOpenFileRequest::setFlags(uint32_t flags)
{
    write<uint32_t>("flags", flags);
}
uint32_t DmEfsOpenFileRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void DmEfsOpenFileRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}
std::vector<uint8_t> DmEfsOpenFileRequest::getFilePath()
{
	return read(getFieldSize("file_path"), getFieldOffset("file_path"));
}
                
void DmEfsOpenFileRequest::setFilePath(uint8_t* data, size_t size)
{
    write("file_path", data, size);
}

void DmEfsOpenFileRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
}
void DmEfsOpenFileRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsOpenFileResponse* resp = new DmEfsOpenFileResponse();
		response = resp;
	}
}
