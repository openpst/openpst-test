/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_stat_response.h
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
        
        class DmEfsStatResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsStatResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsStatResponse();

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
                * @brief Get size
                * @return uint32_t
                */
                uint32_t getSize();
                
                /**
                * @brief Set size
                * @param uint32_t size
                * @return void
                */
                void setSize(uint32_t size);
                /**
                * @brief Get link_count
                * @return uint32_t
                */
                uint32_t getLinkCount();
                
                /**
                * @brief Set link_count
                * @param uint32_t linkCount
                * @return void
                */
                void setLinkCount(uint32_t linkCount);
                /**
                * @brief Get atime
                * @return uint32_t
                */
                uint32_t getAtime();
                
                /**
                * @brief Set atime
                * @param uint32_t atime
                * @return void
                */
                void setAtime(uint32_t atime);
                /**
                * @brief Get mtime
                * @return uint32_t
                */
                uint32_t getMtime();
                
                /**
                * @brief Set mtime
                * @param uint32_t mtime
                * @return void
                */
                void setMtime(uint32_t mtime);
                /**
                * @brief Get ctime
                * @return uint32_t
                */
                uint32_t getCtime();
                
                /**
                * @brief Set ctime
                * @param uint32_t ctime
                * @return void
                */
                void setCtime(uint32_t ctime);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
