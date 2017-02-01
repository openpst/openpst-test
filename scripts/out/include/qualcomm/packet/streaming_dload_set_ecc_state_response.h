/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_set_ecc_state_response.h
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
        
        class StreamingDloadSetEccStateResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadSetEccStateResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadSetEccStateResponse();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
