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
* @file streaming_dload_nop_response.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"

using OpenPST::Qualcomm::StreamingDloadPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class StreamingDloadNopResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadNopResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadNopResponse();

                
                /**
                * @brief Get identifier
                * @return uint32_t
                */
                uint32_t getIdentifier();
                                

                /**
                * @brief Set identifier
                * @param uint32_t identifier
                * @return void
                */
                void setIdentifier(uint32_t identifier);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
