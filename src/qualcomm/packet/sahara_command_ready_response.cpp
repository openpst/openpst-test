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
* @file sahara_command_ready_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_command_ready_response.h"

using namespace OpenPST::Qualcomm;

SaharaCommandReadyResponse::SaharaCommandReadyResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("image_tx_status", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandReady);
}

SaharaCommandReadyResponse::~SaharaCommandReadyResponse()
{

}

uint32_t SaharaCommandReadyResponse::getImageTxStatus()
{
    return read<uint32_t>(getFieldOffset("image_tx_status"));
}                
void SaharaCommandReadyResponse::setImageTxStatus(uint32_t imageTxStatus)
{
    write<uint32_t>("image_tx_status", imageTxStatus);
}

void SaharaCommandReadyResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	SaharaPacket::unpack(data, transport);
	setImageTxStatus(read<uint32_t>(data, getFieldOffset("image_tx_status")));
}
