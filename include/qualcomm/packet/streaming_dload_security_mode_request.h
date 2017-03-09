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
* @file streaming_dload_security_mode_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_security_mode_response.h"

using OpenPST::Qualcomm::StreamingDloadPacket;
using OpenPST::Qualcomm::StreamingDloadSecurityModeResponse;

namespace OpenPST {
    namespace Qualcomm {
        
        class StreamingDloadSecurityModeRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadSecurityModeRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadSecurityModeRequest();

                
                /**
                * @brief Get mode
                * @return uint8_t
                */
                uint8_t getMode();
                                

                /**
                * @brief Set mode
                * @param uint8_t mode
                * @return void
                */
                void setMode(uint8_t mode);
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
