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
* @file dm_efs_hotplug_format_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_hotplug_format_request.h"

using namespace OpenPST::Qualcomm;

DmEfsHotplugFormatRequest::DmEfsHotplugFormatRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("path", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsHotplugFormat);
}

DmEfsHotplugFormatRequest::~DmEfsHotplugFormatRequest()
{

}

uint16_t DmEfsHotplugFormatRequest::getSequence()
{
    return read<uint16_t>(getFieldOffset("sequence"));
}
                
void DmEfsHotplugFormatRequest::setSequence(uint16_t sequence)
{
    write<uint16_t>("sequence", sequence);
}
std::vector<uint8_t> DmEfsHotplugFormatRequest::getPath()
{
	return read(getFieldSize("path"), getFieldOffset("path"));
}
                
void DmEfsHotplugFormatRequest::setPath(uint8_t* data, size_t size)
{
    write("path", data, size);
}

void DmEfsHotplugFormatRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
}
void DmEfsHotplugFormatRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsHotplugFormatResponse* resp = new DmEfsHotplugFormatResponse();
		response = resp;
	}
}
