/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_read_file_request.h
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
        
        class DmEfsReadFileRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsReadFileRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~DmEfsReadFileRequest();

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
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
