#pragma once

#include "serial/sahara_reset_response.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaResetResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaResetResponse();
                
                /**
                * @brief Destructor
                */
                ~SaharaResetResponse();


        };
    }
}
