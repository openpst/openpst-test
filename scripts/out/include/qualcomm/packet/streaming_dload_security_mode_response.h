/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_security_mode_response.h
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
        
        class StreamingDloadSecurityModeResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadSecurityModeResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadSecurityModeResponse();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
