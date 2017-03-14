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
* @file dm_efs_statfs_v2_response.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::Qualcomm::DmEfsPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmEfsStatfsV2Response : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsStatfsV2Response(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsStatfsV2Response();

                
                /**
                * @brief Get sequence
                * @return uint16_t
                */
                uint16_t getSequence();
                                

                /**
                * @brief Set sequence
                * @param uint16_t sequence
                * @return void
                */
                void setSequence(uint16_t sequence);
                                
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
                * @brief Get fs_id
                * @return uint32_t
                */
                uint32_t getFsId();
                                

                /**
                * @brief Set fs_id
                * @param uint32_t fsId
                * @return void
                */
                void setFsId(uint32_t fsId);
                
                /**
                * @brief Get fs_type
                * @return uint8_t[]
                */
                std::vector<uint8_t> getFsType();
                                

                /**
                * @brief Set fs_type
                * @param uint8_t* fsType
                * @param size_t size
                * @return void
                */
                void setFsType(uint8_t* data, size_t size);
                                
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
                * @brief Get max_files
                * @return uint32_t
                */
                uint32_t getMaxFiles();
                                

                /**
                * @brief Set max_files
                * @param uint32_t maxFiles
                * @return void
                */
                void setMaxFiles(uint32_t maxFiles);
                                
                /**
                * @brief Get max_write_size
                * @return uint32_t
                */
                uint32_t getMaxWriteSize();
                                

                /**
                * @brief Set max_write_size
                * @param uint32_t maxWriteSize
                * @return void
                */
                void setMaxWriteSize(uint32_t maxWriteSize);
                                
                /**
                * @brief Get max_path_size
                * @return uint32_t
                */
                uint32_t getMaxPathSize();
                                

                /**
                * @brief Set max_path_size
                * @param uint32_t maxPathSize
                * @return void
                */
                void setMaxPathSize(uint32_t maxPathSize);
                                
                /**
                * @brief Get case_sensitive
                * @return uint32_t
                */
                uint32_t getCaseSensitive();
                                

                /**
                * @brief Set case_sensitive
                * @param uint32_t caseSensitive
                * @return void
                */
                void setCaseSensitive(uint32_t caseSensitive);
                                
                /**
                * @brief Get case_preserving
                * @return uint32_t
                */
                uint32_t getCasePreserving();
                                

                /**
                * @brief Set case_preserving
                * @param uint32_t casePreserving
                * @return void
                */
                void setCasePreserving(uint32_t casePreserving);
                                
                /**
                * @brief Get file_size_units
                * @return uint32_t
                */
                uint32_t getFileSizeUnits();
                                

                /**
                * @brief Set file_size_units
                * @param uint32_t fileSizeUnits
                * @return void
                */
                void setFileSizeUnits(uint32_t fileSizeUnits);
                                
                /**
                * @brief Get max_open_files
                * @return uint32_t
                */
                uint32_t getMaxOpenFiles();
                                

                /**
                * @brief Set max_open_files
                * @param uint32_t maxOpenFiles
                * @return void
                */
                void setMaxOpenFiles(uint32_t maxOpenFiles);
                                
                /**
                * @brief Get name_rule
                * @return uint32_t
                */
                uint32_t getNameRule();
                                

                /**
                * @brief Set name_rule
                * @param uint32_t nameRule
                * @return void
                */
                void setNameRule(uint32_t nameRule);
                                
                /**
                * @brief Get name_encoding
                * @return uint32_t
                */
                uint32_t getNameEncoding();
                                

                /**
                * @brief Set name_encoding
                * @param uint32_t nameEncoding
                * @return void
                */
                void setNameEncoding(uint32_t nameEncoding);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
