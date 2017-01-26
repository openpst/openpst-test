#pragma once

#include "serial/sahara_done_request.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaDoneRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaDoneRequest();
                
                /**
                * @brief Destructor
                */
                ~SaharaDoneRequest();


        };
    }
}
