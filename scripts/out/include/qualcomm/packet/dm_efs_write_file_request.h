/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_write_file_request.h
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
        
        class DmEfsWriteFileRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsWriteFileRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~DmEfsWriteFileRequest();

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
                * @brief Get data
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getData();
                
                /**
                * @brief Set data
                * @param uint8_t* data
                * @param size_t data
                * @return void
                */
                void setData(uint8_t* data, size_t size);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
