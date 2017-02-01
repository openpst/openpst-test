/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_reset_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_reset_response.h"

using OpenPST::QC::StreamingDloadPacket;
using OpenPST::QC::StreamingDloadResetResponse;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadResetRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadResetRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadResetRequest();

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
