/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_create_link_response.h
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
        
        class DmEfsCreateLinkResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsCreateLinkResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsCreateLinkResponse();

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
