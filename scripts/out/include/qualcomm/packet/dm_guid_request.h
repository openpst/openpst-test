#pragma once

#include "serial/dm_guid_request.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmGuidRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmGuidRequest();
                
                /**
                * @brief Destructor
                */
                ~DmGuidRequest();


        };
    }
}
