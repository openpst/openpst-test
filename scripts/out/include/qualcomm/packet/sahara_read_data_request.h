#pragma once

#include "serial/sahara_read_data_request.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaReadDataRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaReadDataRequest();
                
                /**
                * @brief Destructor
                */
                ~SaharaReadDataRequest();

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
                * @brief Get offset
                * @return uint32_t
                */
                uint32_t getOffset();
                
                /**
                * @brief Set offset
                * @param uint32_t offset
                * @return void
                */
                void setOffset(uint32_t offset);
                /**
                * @brief Get size
                * @return uint32_t
                */
                uint32_t getSize();
                
                /**
                * @brief Set size
                * @param uint32_t size
                * @return void
                */
                void setSize(uint32_t size);

        };
    }
}