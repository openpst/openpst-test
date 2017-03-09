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
* @file dm_efs_query_response.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::Qualcomm::DmEfsPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmEfsQueryResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsQueryResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsQueryResponse();

                
                /**
                * @brief Get max_file_name_length
                * @return uint32_t
                */
                uint32_t getMaxFileNameLength();
                                

                /**
                * @brief Set max_file_name_length
                * @param uint32_t maxFileNameLength
                * @return void
                */
                void setMaxFileNameLength(uint32_t maxFileNameLength);
                                
                /**
                * @brief Get max_pathname_length
                * @return uint32_t
                */
                uint32_t getMaxPathnameLength();
                                

                /**
                * @brief Set max_pathname_length
                * @param uint32_t maxPathnameLength
                * @return void
                */
                void setMaxPathnameLength(uint32_t maxPathnameLength);
                                
                /**
                * @brief Get max_symlink_depth
                * @return uint32_t
                */
                uint32_t getMaxSymlinkDepth();
                                

                /**
                * @brief Set max_symlink_depth
                * @param uint32_t maxSymlinkDepth
                * @return void
                */
                void setMaxSymlinkDepth(uint32_t maxSymlinkDepth);
                                
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
                * @brief Get max_directories
                * @return uint32_t
                */
                uint32_t getMaxDirectories();
                                

                /**
                * @brief Set max_directories
                * @param uint32_t maxDirectories
                * @return void
                */
                void setMaxDirectories(uint32_t maxDirectories);
                                
                /**
                * @brief Get max_mounts
                * @return uint32_t
                */
                uint32_t getMaxMounts();
                                

                /**
                * @brief Set max_mounts
                * @param uint32_t maxMounts
                * @return void
                */
                void setMaxMounts(uint32_t maxMounts);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
