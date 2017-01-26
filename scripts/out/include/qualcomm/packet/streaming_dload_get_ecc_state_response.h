/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_get_ecc_state_response.h
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
        
        class StreamingDloadGetEccStateResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadGetEccStateResponse();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadGetEccStateResponse();

                /**
                * @brief Get status
                * @return uint8_t
                */
                uint8_t getStatus();
                
                /**
                * @brief Set status
                * @param uint8_t status
                * @return void
                */
                void setStatus(uint8_t status);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
