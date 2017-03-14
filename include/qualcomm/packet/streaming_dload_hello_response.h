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
* @file streaming_dload_hello_response.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"

using OpenPST::Qualcomm::StreamingDloadPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class StreamingDloadHelloResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadHelloResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadHelloResponse();

                /**
                * @brief Get magic
                * @return std::string
                */
                std::string getMagic();
                                

                /**
                * @brief Set magic
                * @param uint8_t* magic
                * @param size_t size
                * @return void
                */
                void setMagic(uint8_t* data, size_t size);
                                
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
                * @brief Get preferred_block_size
                * @return uint32_t
                */
                uint32_t getPreferredBlockSize();
                                

                /**
                * @brief Set preferred_block_size
                * @param uint32_t preferredBlockSize
                * @return void
                */
                void setPreferredBlockSize(uint32_t preferredBlockSize);
                                
                /**
                * @brief Get base_flash_address
                * @return uint32_t
                */
                uint32_t getBaseFlashAddress();
                                

                /**
                * @brief Set base_flash_address
                * @param uint32_t baseFlashAddress
                * @return void
                */
                void setBaseFlashAddress(uint32_t baseFlashAddress);
                                
                /**
                * @brief Get flash_id_length
                * @return uint8_t
                */
                uint8_t getFlashIdLength();
                                

                /**
                * @brief Set flash_id_length
                * @param uint8_t flashIdLength
                * @return void
                */
                void setFlashIdLength(uint8_t flashIdLength);
                
                /**
                * @brief Get flash_id
                * @return std::string
                */
                std::string getFlashId();
                                

                /**
                * @brief Set flash_id
                * @param uint8_t* flashId
                * @param size_t size
                * @return void
                */
                void setFlashId(uint8_t* data, size_t size);
                                
                /**
                * @brief Get window_size
                * @return uint16_t
                */
                uint16_t getWindowSize();
                                

                /**
                * @brief Set window_size
                * @param uint16_t windowSize
                * @return void
                */
                void setWindowSize(uint16_t windowSize);
                                
                /**
                * @brief Get number_of_sectors
                * @return uint16_t
                */
                uint16_t getNumberOfSectors();
                                

                /**
                * @brief Set number_of_sectors
                * @param uint16_t numberOfSectors
                * @return void
                */
                void setNumberOfSectors(uint16_t numberOfSectors);
                
                /**
                * @brief Get sector_sizes
                * @return variable
                */
                std::vector<uint8_t> getSectorSizes();
                                

                /**
                * @brief Set sector_sizes
                * @param uint8_t* sectorSizes
                * @param size_t size
                * @return void
                */
                void setSectorSizes(uint8_t* data, size_t size);
                                
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

        };
    }
}
