/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_close_dir_response.h
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
        
        class DmEfsCloseDirResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsCloseDirResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsCloseDirResponse();

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
