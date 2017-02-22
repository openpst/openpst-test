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
* @file dm_efs_statfs_v2_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_statfs_v2_request.h"

using namespace OpenPST::Qualcomm;

DmEfsStatfsV2Request::DmEfsStatfsV2Request(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsStatVFS_V2);
}

DmEfsStatfsV2Request::~DmEfsStatfsV2Request()
{

}

uint16_t DmEfsStatfsV2Request::getSequence()
{
    return read<uint16_t>(getFieldOffset("sequence"));
}
                
void DmEfsStatfsV2Request::setSequence(uint16_t sequence)
{
    write<uint16_t>("sequence", sequence);
}
std::vector<uint8_t> DmEfsStatfsV2Request::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsStatfsV2Request::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsStatfsV2Request::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
void DmEfsStatfsV2Request::prepareResponse()
{
	if (response == nullptr) {
		DmEfsStatfsV2Response* resp = new DmEfsStatfsV2Response();
		response = resp;
	}
}
