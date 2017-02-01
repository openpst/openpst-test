/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_query_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::QC::DmEfsPacket;

namespace OpenPST {
    namespace QC {
        
        class DmEfsQueryResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsQueryResponse(PacketEndianess targetEndian);
                
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
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
