/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_unlock_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_unlock_response.h"

using OpenPST::QC::StreamingDloadPacket;
using OpenPST::QC::StreamingDloadUnlockResponse;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadUnlockRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadUnlockRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadUnlockRequest();

                /**
                * @brief Get code
                * @return uint64_t
                */
                uint64_t getCode();
                
                /**
                * @brief Set code
                * @param uint64_t code
                * @return void
                */
                void setCode(uint64_t code);
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
