/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_nop_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadNopResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadNopResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadNopResponse();

                /**
                * @brief Get identifier
                * @return uint32_t
                */
                uint32_t getIdentifier();
                
                /**
                * @brief Set identifier
                * @param uint32_t identifier
                * @return void
                */
                void setIdentifier(uint32_t identifier);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
