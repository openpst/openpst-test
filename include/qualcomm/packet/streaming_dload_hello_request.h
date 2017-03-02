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
* @file streaming_dload_hello_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_hello_response.h"

using OpenPST::Qualcomm::StreamingDloadPacket;
using OpenPST::Qualcomm::StreamingDloadHelloResponse;

namespace OpenPST {
    namespace Qualcomm {
        
        class StreamingDloadHelloRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadHelloRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadHelloRequest();

                /**
                * @brief Get magic
                * @return std::string
                */
                std::string getMagic();
                                

                /**
                * @brief Set magic
                * @param const std::string& magic
                * @return void
                */
                void setMagic(const std::string& magic);
                                
                /**
                * @brief Get version
                * @return uint8_t
                */
                uint8_t getVersion();
                                

                /**
                * @brief Set version
                * @param uint8_t version
                * @return void
                */
                void setVersion(uint8_t version);
                                
                /**
                * @brief Get compatible_version
                * @return uint8_t
                */
                uint8_t getCompatibleVersion();
                                

                /**
                * @brief Set compatible_version
                * @param uint8_t compatibleVersion
                * @return void
                */
                void setCompatibleVersion(uint8_t compatibleVersion);
                                
                /**
                * @brief Get feature_bits
                * @return uint8_t
                */
                uint8_t getFeatureBits();
                                

                /**
                * @brief Set feature_bits
                * @param uint8_t featureBits
                * @return void
                */
                void setFeatureBits(uint8_t featureBits);
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
