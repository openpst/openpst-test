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
* @file dm_efs_close_file_reponse.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_close_file_reponse.h"

using namespace OpenPST::Qualcomm;

DmEfsCloseFileReponse::DmEfsCloseFileReponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsClose);

	setResponseExpected(false);
}

DmEfsCloseFileReponse::~DmEfsCloseFileReponse()
{

}

uint32_t DmEfsCloseFileReponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                

void DmEfsCloseFileReponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}

void DmEfsCloseFileReponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setError(read<uint32_t>(data, getFieldOffset("error")));
}
