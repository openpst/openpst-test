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

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadResetRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadResetRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadResetRequest();


            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
