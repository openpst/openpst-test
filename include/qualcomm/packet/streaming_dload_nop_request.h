/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_nop_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_nop_response.h"

using OpenPST::QC::StreamingDloadPacket;
using OpenPST::QC::StreamingDloadNopResponse;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadNopRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadNopRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadNopRequest();

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

				/**
				* @overload Packet::prepareResponse
				*/
				void prepareResponse() override;

        };
    }
}
