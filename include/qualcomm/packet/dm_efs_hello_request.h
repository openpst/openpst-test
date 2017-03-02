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
* @file dm_efs_hello_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/01/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"
#include "qualcomm/packet/dm_efs_hello_response.h"

using OpenPST::Qualcomm::DmEfsPacket;
using OpenPST::Qualcomm::DmEfsHelloResponse;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmEfsHelloRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsHelloRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsHelloRequest();

                
                /**
                * @brief Get target_packet_window_size
                * @return uint32_t
                */
                uint32_t getTargetPacketWindowSize();
                                

                /**
                * @brief Set target_packet_window_size
                * @param uint32_t targetPacketWindowSize
                * @return void
                */
                void setTargetPacketWindowSize(uint32_t targetPacketWindowSize);
                                
                /**
                * @brief Get target_packet_window_byte_size
                * @return uint32_t
                */
                uint32_t getTargetPacketWindowByteSize();
                                

                /**
                * @brief Set target_packet_window_byte_size
                * @param uint32_t targetPacketWindowByteSize
                * @return void
                */
                void setTargetPacketWindowByteSize(uint32_t targetPacketWindowByteSize);
                                
                /**
                * @brief Get host_packet_window_size
                * @return uint32_t
                */
                uint32_t getHostPacketWindowSize();
                                

                /**
                * @brief Set host_packet_window_size
                * @param uint32_t hostPacketWindowSize
                * @return void
                */
                void setHostPacketWindowSize(uint32_t hostPacketWindowSize);
                                
                /**
                * @brief Get host_packet_window_byte_size
                * @return uint32_t
                */
                uint32_t getHostPacketWindowByteSize();
                                

                /**
                * @brief Set host_packet_window_byte_size
                * @param uint32_t hostPacketWindowByteSize
                * @return void
                */
                void setHostPacketWindowByteSize(uint32_t hostPacketWindowByteSize);
                                
                /**
                * @brief Get dir_iterator_window_size
                * @return uint32_t
                */
                uint32_t getDirIteratorWindowSize();
                                

                /**
                * @brief Set dir_iterator_window_size
                * @param uint32_t dirIteratorWindowSize
                * @return void
                */
                void setDirIteratorWindowSize(uint32_t dirIteratorWindowSize);
                                
                /**
                * @brief Get dir_iterator_window_byte_size
                * @return uint32_t
                */
                uint32_t getDirIteratorWindowByteSize();
                                

                /**
                * @brief Set dir_iterator_window_byte_size
                * @param uint32_t dirIteratorWindowByteSize
                * @return void
                */
                void setDirIteratorWindowByteSize(uint32_t dirIteratorWindowByteSize);
                                
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
                * @brief Get max_version
                * @return uint32_t
                */
                uint32_t getMaxVersion();
                                

                /**
                * @brief Set max_version
                * @param uint32_t maxVersion
                * @return void
                */
                void setMaxVersion(uint32_t maxVersion);
                                
                /**
                * @brief Get feature_bits
                * @return uint32_t
                */
                uint32_t getFeatureBits();
                                

                /**
                * @brief Set feature_bits
                * @param uint32_t featureBits
                * @return void
                */
                void setFeatureBits(uint32_t featureBits);
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
