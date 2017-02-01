/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_read_dir_response.h
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
        
        class DmEfsReadDirResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsReadDirResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~DmEfsReadDirResponse();

                /**
                * @brief Get dp
                * @return uint32_t
                */
                uint32_t getDp();
                
                /**
                * @brief Set dp
                * @param uint32_t dp
                * @return void
                */
                void setDp(uint32_t dp);
                /**
                * @brief Get sequence_number
                * @return uint32_t
                */
                uint32_t getSequenceNumber();
                
                /**
                * @brief Set sequence_number
                * @param uint32_t sequenceNumber
                * @return void
                */
                void setSequenceNumber(uint32_t sequenceNumber);
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
                * @brief Get entry_type
                * @return uint32_t
                */
                uint32_t getEntryType();
                
                /**
                * @brief Set entry_type
                * @param uint32_t entryType
                * @return void
                */
                void setEntryType(uint32_t entryType);
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
                * @brief Get name
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getName();
                
                /**
                * @brief Set name
                * @param uint8_t* name
                * @param size_t name
                * @return void
                */
                void setName(uint8_t* data, size_t size);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
