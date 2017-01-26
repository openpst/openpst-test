/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_erase_flash_request.h
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
        
        class StreamingDloadEraseFlashRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadEraseFlashRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadEraseFlashRequest();


            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
