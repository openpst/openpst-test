/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_open_multi_image_with_payload_request.h
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
        
        class StreamingDloadOpenMultiImageWithPayloadRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadOpenMultiImageWithPayloadRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadOpenMultiImageWithPayloadRequest();

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
                /**
                * @brief Get payload
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getPayload();
                
                /**
                * @brief Set payload
                * @param std::ifstream& file
                * @param size_t size
                * @return void
                */
                void setPayload(std::ifstream& file, size_t size);
                /**
                * @brief Set payload
                * @param uint8_t* payload
                * @param size_t payload
                * @return void
                */
                void setPayload(uint8_t* data, size_t size);
                /**
                * @brief Set payload
                * @param const std::string& payload
                * @return void
                */
                void setPayload(const std::string& payload);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
