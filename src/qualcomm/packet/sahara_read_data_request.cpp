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
* @file sahara_read_data_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_read_data_request.h"

using namespace OpenPST::QC;

SaharaReadDataRequest::SaharaReadDataRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("image_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

SaharaReadDataRequest::~SaharaReadDataRequest()
{

}

uint32_t SaharaReadDataRequest::getImageId()
{
    return read<uint32_t>(getFieldOffset("image_id"));
}
                
void SaharaReadDataRequest::setImageId(uint32_t imageId)
{
    write<uint32_t>("image_id", imageId);
}
uint32_t SaharaReadDataRequest::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                
void SaharaReadDataRequest::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}
uint32_t SaharaReadDataRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaReadDataRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaReadDataRequest::unpack(std::vector<uint8_t>& data)
{
}
void SaharaReadDataRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaReadDataResponse* resp = new SaharaReadDataResponse();
		response = resp;
	}
}
