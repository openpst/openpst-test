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
* @file streaming_dload_open_multi_image_with_payload_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_open_multi_image_response.h"

using OpenPST::Qualcomm::StreamingDloadPacket;
using OpenPST::Qualcomm::StreamingDloadOpenMultiImageResponse;

namespace OpenPST {
    namespace Qualcomm {
        
        class StreamingDloadOpenMultiImageWithPayloadRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadOpenMultiImageWithPayloadRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadOpenMultiImageWithPayloadRequest();

                
                /**
                * @brief Get type
                * @return uint8_t
                */
                uint8_t getType();
                                

                /**
                * @brief Set type
                * @param uint8_t type
                * @return void
                */
                void setType(uint8_t type);
                
                /**
                * @brief Get payload
                * @return variable
                */
                std::vector<uint8_t> getPayload();
                                

                /**
                * @brief Set payload
                * @param std::ifstream& file
                * @param size_t size
                * @return void
                */
                void setPayload(std::ifstream& file, size_t size);
                
                /**
                * @brief Set payload
                * @param uint8_t* payload
                * @param size_t size
                * @return void
                */
                void setPayload(uint8_t* data, size_t size);
                
                /**
                * @brief Set payload
                * @param const std::string& payload
                * @return void
                */
                void setPayload(const std::string& payload);
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
