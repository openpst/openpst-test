/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_read_dir_request.h
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
        
        class DmEfsReadDirRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsReadDirRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsReadDirRequest();

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
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
