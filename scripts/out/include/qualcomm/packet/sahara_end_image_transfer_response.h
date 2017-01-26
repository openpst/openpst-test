#pragma once

#include "serial/sahara_end_image_transfer_response.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaEndImageTransferResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaEndImageTransferResponse();
                
                /**
                * @brief Destructor
                */
                ~SaharaEndImageTransferResponse();

                /**
                * @brief Get image_id
                * @return uint32_t
                */
                uint32_t getImageId();
                
                /**
                * @brief Set image_id
                * @param uint32_t imageId
                * @return void
                */
                void setImageId(uint32_t imageId);
                /**
                * @brief Get status
                * @return uint32_t
                */
                uint32_t getStatus();
                
                /**
                * @brief Set status
                * @param uint32_t status
                * @return void
                */
                void setStatus(uint32_t status);

        };
    }
}
