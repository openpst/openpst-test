#pragma once

#include "serial/sahara_reset_request.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaResetRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaResetRequest();
                
                /**
                * @brief Destructor
                */
                ~SaharaResetRequest();


        };
    }
}
