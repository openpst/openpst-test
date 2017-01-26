#pragma once

#include "serial/dm_phone_mode_request.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmPhoneModeRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmPhoneModeRequest();
                
                /**
                * @brief Destructor
                */
                ~DmPhoneModeRequest();

                /**
                * @brief Get mode
                * @return uint8_t
                */
                uint8_t getMode();
                
                /**
                * @brief Set mode
                * @param uint8_t mode
                * @return void
                */
                void setMode(uint8_t mode);
                /**
                * @brief Get padding
                * @return uint8_t
                */
                uint8_t getPadding();
                
                /**
                * @brief Set padding
                * @param uint8_t padding
                * @return void
                */
                void setPadding(uint8_t padding);

        };
    }
}
