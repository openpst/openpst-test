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
* @file dm_efs_factory_image_read_response.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/02/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::Qualcomm::DmEfsPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmEfsFactoryImageReadResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsFactoryImageReadResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsFactoryImageReadResponse();

                
                /**
                * @brief Get error
                * @return uint32_t
                */
                uint32_t getError();
                                

                /**
                * @brief Set error
                * @param uint32_t error
                * @return void
                */
                void setError(uint32_t error);
                                
                /**
                * @brief Get stream_state
                * @return uint8_t
                */
                uint8_t getStreamState();
                                

                /**
                * @brief Set stream_state
                * @param uint8_t streamState
                * @return void
                */
                void setStreamState(uint8_t streamState);
                                
                /**
                * @brief Get info_cluster_sent
                * @return uint8_t
                */
                uint8_t getInfoClusterSent();
                                

                /**
                * @brief Set info_cluster_sent
                * @param uint8_t infoClusterSent
                * @return void
                */
                void setInfoClusterSent(uint8_t infoClusterSent);
                                
                /**
                * @brief Get custer_map_sequence
                * @return uint16_t
                */
                uint16_t getCusterMapSequence();
                                

                /**
                * @brief Set custer_map_sequence
                * @param uint16_t custerMapSequence
                * @return void
                */
                void setCusterMapSequence(uint16_t custerMapSequence);
                                
                /**
                * @brief Get custer_data_sequence
                * @return uint16_t
                */
                uint16_t getCusterDataSequence();
                                

                /**
                * @brief Set custer_data_sequence
                * @param uint16_t custerDataSequence
                * @return void
                */
                void setCusterDataSequence(uint16_t custerDataSequence);
                
                /**
                * @brief Get data
                * @return variable
                */
                std::vector<uint8_t> getData();
                                

                /**
                * @brief Set data
                * @param uint8_t* data
                * @param size_t size
                * @return void
                */
                void setData(uint8_t* data, size_t size);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
