/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_open_file_request.h
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
        
        class DmEfsOpenFileRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsOpenFileRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsOpenFileRequest();

                /**
                * @brief Get flags
                * @return uint32_t
                */
                uint32_t getFlags();
                
                /**
                * @brief Set flags
                * @param uint32_t flags
                * @return void
                */
                void setFlags(uint32_t flags);
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
                * @brief Get file_path
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getFilePath();
                
                /**
                * @brief Set file_path
                * @param uint8_t* filePath
                * @param size_t filePath
                * @return void
                */
                void setFilePath(uint8_t* data, size_t size);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
