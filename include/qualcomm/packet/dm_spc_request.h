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
* @file dm_spc_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_packet.h"
#include "qualcomm/packet/dm_spc_response.h"

using OpenPST::Qualcomm::DmPacket;
using OpenPST::Qualcomm::DmSpcResponse;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmSpcRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmSpcRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmSpcRequest();

                /**
                * @brief Get spc
                * @return uint8_t[]
                */
                std::vector<uint8_t> getSpc();
                                

                /**
                * @brief Set spc
                * @param uint8_t* spc
                * @param size_t size
                * @return void
                */
                void setSpc(uint8_t* data, size_t size);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

				/**
				* @overload Packet::prepareResponse
				*/
				void prepareResponse() override;

        };
    }
}
