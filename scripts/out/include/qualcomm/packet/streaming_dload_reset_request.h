#pragma once

#include "serial/streaming_dload_reset_request.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadResetRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadResetRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadResetRequest();


        };
    }
}
