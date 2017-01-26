/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_get_ecc_state_request.h
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
        
        class StreamingDloadGetEccStateRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadGetEccStateRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadGetEccStateRequest();


            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
