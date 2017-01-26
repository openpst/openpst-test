#pragma once

#include "serial/sahara_done_response.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaDoneResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaDoneResponse();
                
                /**
                * @brief Destructor
                */
                ~SaharaDoneResponse();


        };
    }
}
