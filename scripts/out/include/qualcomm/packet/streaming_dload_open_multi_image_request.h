/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_open_multi_image_request.h
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
        
        class StreamingDloadOpenMultiImageRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadOpenMultiImageRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadOpenMultiImageRequest();

                /**
                * @brief Get type
                * @return uint8_t
                */
                uint8_t getType();
                
                /**
                * @brief Set type
                * @param uint8_t type
                * @return void
                */
                void setType(uint8_t type);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
