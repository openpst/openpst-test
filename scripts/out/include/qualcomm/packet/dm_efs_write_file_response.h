/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_write_file_response.h
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
        
        class DmEfsWriteFileResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsWriteFileResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~DmEfsWriteFileResponse();

                /**
                * @brief Get fp
                * @return uint32_t
                */
                uint32_t getFp();
                
                /**
                * @brief Set fp
                * @param uint32_t fp
                * @return void
                */
                void setFp(uint32_t fp);
                /**
                * @brief Get offset
                * @return uint32_t
                */
                uint32_t getOffset();
                
                /**
                * @brief Set offset
                * @param uint32_t offset
                * @return void
                */
                void setOffset(uint32_t offset);
                /**
                * @brief Get bytes_written
                * @return uint32_t
                */
                uint32_t getBytesWritten();
                
                /**
                * @brief Set bytes_written
                * @param uint32_t bytesWritten
                * @return void
                */
                void setBytesWritten(uint32_t bytesWritten);
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
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
