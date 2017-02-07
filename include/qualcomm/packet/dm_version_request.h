/**
* LICENSE PLACEHOLDER
*
* @file dm_version_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_packet.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmVersionRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmVersionRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmVersionRequest();

                /**
                * @brief Get version
                * @return uint16_t
                */
                uint16_t getVersion();
                
                /**
                * @brief Set version
                * @param uint16_t version
                * @return void
                */
                void setVersion(uint16_t version);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
