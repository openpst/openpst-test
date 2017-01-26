#pragma once

#include "serial/sahara_switch_mode_request.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaSwitchModeRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaSwitchModeRequest();
                
                /**
                * @brief Destructor
                */
                ~SaharaSwitchModeRequest();

                /**
                * @brief Get mode
                * @return uint32_t
                */
                uint32_t getMode();
                
                /**
                * @brief Set mode
                * @param uint32_t mode
                * @return void
                */
                void setMode(uint32_t mode);

        };
    }
}
