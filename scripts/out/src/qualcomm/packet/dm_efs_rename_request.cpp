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
* @file dm_efs_rename_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_rename_request.h"

using namespace OpenPST::QC;

DmEfsRenameRequest::DmEfsRenameRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("path", kPacketFieldTypeVariant, 0);
	addField("new_path", kPacketFieldTypeVariant, 0);

}

DmEfsRenameRequest::~DmEfsRenameRequest()
{

}

std::vector<uint8_t> DmEfsRenameRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsRenameRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}
std::vector<uint8_t> DmEfsRenameRequest::getNewPath()
{
	return read(getFieldSize("new_path"), getFieldOffset("new_path"));
}
                
void DmEfsRenameRequest::setNewPath(uint8_t* data, size_t size)
{
    write("new_path", data, size);
}

void DmEfsRenameRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
