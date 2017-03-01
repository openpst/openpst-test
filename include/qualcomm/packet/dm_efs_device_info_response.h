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
* @file dm_efs_device_info_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::Qualcomm::DmEfsPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmEfsDeviceInfoResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsDeviceInfoResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsDeviceInfoResponse();

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
                void setError(uint32_t error);                /**
                * @brief Get total_blocks
                * @return uint32_t
                */
                uint32_t getTotalBlocks();                
                /**
                * @brief Set total_blocks
                * @param uint32_t totalBlocks
                * @return void
                */
                void setTotalBlocks(uint32_t totalBlocks);                /**
                * @brief Get pages_per_block
                * @return uint32_t
                */
                uint32_t getPagesPerBlock();                
                /**
                * @brief Set pages_per_block
                * @param uint32_t pagesPerBlock
                * @return void
                */
                void setPagesPerBlock(uint32_t pagesPerBlock);                /**
                * @brief Get page_size
                * @return uint32_t
                */
                uint32_t getPageSize();                
                /**
                * @brief Set page_size
                * @param uint32_t pageSize
                * @return void
                */
                void setPageSize(uint32_t pageSize);                /**
                * @brief Get total_page_size
                * @return uint32_t
                */
                uint32_t getTotalPageSize();                
                /**
                * @brief Set total_page_size
                * @param uint32_t totalPageSize
                * @return void
                */
                void setTotalPageSize(uint32_t totalPageSize);                /**
                * @brief Get maker_id
                * @return uint32_t
                */
                uint32_t getMakerId();                
                /**
                * @brief Set maker_id
                * @param uint32_t makerId
                * @return void
                */
                void setMakerId(uint32_t makerId);                /**
                * @brief Get device_id
                * @return uint32_t
                */
                uint32_t getDeviceId();                
                /**
                * @brief Set device_id
                * @param uint32_t deviceId
                * @return void
                */
                void setDeviceId(uint32_t deviceId);                /**
                * @brief Get device_type
                * @return uint8_t
                */
                uint8_t getDeviceType();                
                /**
                * @brief Set device_type
                * @param uint8_t deviceType
                * @return void
                */
                void setDeviceType(uint8_t deviceType);                /**
                * @brief Get name
                * @return variable
                */
                std::vector<uint8_t> getName();                
                /**
                * @brief Set name
                * @param uint8_t* name
                * @param size_t size
                * @return void
                */
                void setName(uint8_t* data, size_t size);				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
