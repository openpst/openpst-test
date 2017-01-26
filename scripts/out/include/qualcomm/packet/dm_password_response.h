#pragma once

#include "serial/dm_password_response.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmPasswordResponse : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmPasswordResponse();
                
                /**
                * @brief Destructor
                */
                ~DmPasswordResponse();

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

        };
    }
}
