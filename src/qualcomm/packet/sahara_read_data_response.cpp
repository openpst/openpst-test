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
* @file sahara_read_data_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_read_data_response.h"

using namespace OpenPST::Qualcomm;

SaharaReadDataResponse::SaharaReadDataResponse(PacketEndianess targetEndian) : Packet(targetEndian)
{
	addField("data", kPacketFieldTypeVariant, 0);

	setCommand(kSaharaCommandReadData);
}

SaharaReadDataResponse::~SaharaReadDataResponse()
{

}

std::vector<uint8_t> SaharaReadDataResponse::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
std::string SaharaReadDataResponse::getData()
{
	return getString(0, getFieldOffset("data"));
}
                
void SaharaReadDataResponse::setData(std::ifstream& file, size_t size)
{
    write("data", file, size);
}
void SaharaReadDataResponse::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}
void SaharaReadDataResponse::setData(const std::string& data)
{
    write("data", data);
}

void SaharaReadDataResponse::unpack(std::vector<uint8_t>& data)
{
}
