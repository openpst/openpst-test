#pragma once

#include "serial/dm_phone_mode_response.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmPhoneModeResponse : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmPhoneModeResponse();
                
                /**
                * @brief Destructor
                */
                ~DmPhoneModeResponse();

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
