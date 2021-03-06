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
* @file sahara_hello_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/sahara_packet.h"
#include "qualcomm/packet/sahara_hello_response.h"

using OpenPST::Qualcomm::SaharaPacket;
using OpenPST::Qualcomm::SaharaHelloResponse;

namespace OpenPST {
    namespace Qualcomm {
        
        class SaharaHelloRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaHelloRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~SaharaHelloRequest();

                
                /**
                * @brief Get version
                * @return uint32_t
                */
                uint32_t getVersion();
                                

                /**
                * @brief Set version
                * @param uint32_t version
                * @return void
                */
                void setVersion(uint32_t version);
                                
                /**
                * @brief Get min_version
                * @return uint32_t
                */
                uint32_t getMinVersion();
                                

                /**
                * @brief Set min_version
                * @param uint32_t minVersion
                * @return void
                */
                void setMinVersion(uint32_t minVersion);
                                
                /**
                * @brief Get max_command_packet_size
                * @return uint32_t
                */
                uint32_t getMaxCommandPacketSize();
                                

                /**
                * @brief Set max_command_packet_size
                * @param uint32_t maxCommandPacketSize
                * @return void
                */
                void setMaxCommandPacketSize(uint32_t maxCommandPacketSize);
                                
                /**
                * @brief Get status
                * @return uint32_t
                */
                uint32_t getStatus();
                                

                /**
                * @brief Set status
                * @param uint32_t status
                * @return void
                */
                void setStatus(uint32_t status);
                                
                /**
                * @brief Get mode
                * @return uint32_t
                */
                uint32_t getMode();
                                

                /**
                * @brief Set mode
                * @param uint32_t mode
                * @return void
                */
                void setMode(uint32_t mode);
                
                /**
                * @brief Get reserved
                * @return uint8_t[]
                */
                std::vector<uint8_t> getReserved();
                                

                /**
                * @brief Set reserved
                * @param uint8_t* reserved
                * @param size_t size
                * @return void
                */
                void setReserved(uint8_t* data, size_t size);
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
