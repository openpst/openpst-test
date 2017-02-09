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
* @file sahara_end_image_transfer_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_end_image_transfer_response.h"

using namespace OpenPST::QC;

SaharaEndImageTransferResponse::SaharaEndImageTransferResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("image_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("status", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandEndImageTransfer);
}

SaharaEndImageTransferResponse::~SaharaEndImageTransferResponse()
{

}

uint32_t SaharaEndImageTransferResponse::getImageId()
{
    return read<uint32_t>(getFieldOffset("image_id"));
}
                
void SaharaEndImageTransferResponse::setImageId(uint32_t imageId)
{
    write<uint32_t>("image_id", imageId);
}
uint32_t SaharaEndImageTransferResponse::getStatus()
{
    return read<uint32_t>(getFieldOffset("status"));
}
                
void SaharaEndImageTransferResponse::setStatus(uint32_t status)
{
    write<uint32_t>("status", status);
}

void SaharaEndImageTransferResponse::unpack(std::vector<uint8_t>& data)
{
}
