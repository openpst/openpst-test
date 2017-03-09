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
* @file streaming_dload_partition_table_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_partition_table_response.h"

using OpenPST::Qualcomm::StreamingDloadPacket;
using OpenPST::Qualcomm::StreamingDloadPartitionTableResponse;

namespace OpenPST {
    namespace Qualcomm {
        
        class StreamingDloadPartitionTableRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadPartitionTableRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadPartitionTableRequest();

                
                /**
                * @brief Get override_existing
                * @return uint8_t
                */
                uint8_t getOverrideExisting();
                                

                /**
                * @brief Set override_existing
                * @param uint8_t overrideExisting
                * @return void
                */
                void setOverrideExisting(uint8_t overrideExisting);
                
                /**
                * @brief Get data
                * @return uint8_t[]
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

				/**
				* @overload Packet::prepareResponse
				*/
				void prepareResponse() override;

        };
    }
}
