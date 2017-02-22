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
* @file dm_efs_statfs_response.h
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
        
        class DmEfsStatfsResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsStatfsResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsStatfsResponse();

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
                * @brief Get filesystem_id
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getFilesystemId();
                
                /**
                * @brief Set filesystem_id
                * @param uint8_t* filesystemId
                * @param size_t size
                * @return void
                */
                void setFilesystemId(uint8_t* data, size_t size);
                /**
                * @brief Get filesystem_type
                * @return uint32_t
                */
                uint32_t getFilesystemType();
                
                /**
                * @brief Set filesystem_type
                * @param uint32_t filesystemType
                * @return void
                */
                void setFilesystemType(uint32_t filesystemType);
                /**
                * @brief Get block_size
                * @return uint32_t
                */
                uint32_t getBlockSize();
                
                /**
                * @brief Set block_size
                * @param uint32_t blockSize
                * @return void
                */
                void setBlockSize(uint32_t blockSize);
                /**
                * @brief Get total_blocks
                * @return uint32_t
                */
                uint32_t getTotalBlocks();
                
                /**
                * @brief Set total_blocks
                * @param uint32_t totalBlocks
                * @return void
                */
                void setTotalBlocks(uint32_t totalBlocks);
                /**
                * @brief Get available_blocks
                * @return uint32_t
                */
                uint32_t getAvailableBlocks();
                
                /**
                * @brief Set available_blocks
                * @param uint32_t availableBlocks
                * @return void
                */
                void setAvailableBlocks(uint32_t availableBlocks);
                /**
                * @brief Get free_blocks
                * @return uint32_t
                */
                uint32_t getFreeBlocks();
                
                /**
                * @brief Set free_blocks
                * @param uint32_t freeBlocks
                * @return void
                */
                void setFreeBlocks(uint32_t freeBlocks);
                /**
                * @brief Get max_file_size
                * @return uint32_t
                */
                uint32_t getMaxFileSize();
                
                /**
                * @brief Set max_file_size
                * @param uint32_t maxFileSize
                * @return void
                */
                void setMaxFileSize(uint32_t maxFileSize);
                /**
                * @brief Get file_count
                * @return uint32_t
                */
                uint32_t getFileCount();
                
                /**
                * @brief Set file_count
                * @param uint32_t fileCount
                * @return void
                */
                void setFileCount(uint32_t fileCount);
                /**
                * @brief Get max_file_count
                * @return uint32_t
                */
                uint32_t getMaxFileCount();
                
                /**
                * @brief Set max_file_count
                * @param uint32_t maxFileCount
                * @return void
                */
                void setMaxFileCount(uint32_t maxFileCount);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
