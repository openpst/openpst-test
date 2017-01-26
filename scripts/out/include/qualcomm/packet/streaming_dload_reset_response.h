#pragma once

#include "serial/streaming_dload_reset_response.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadResetResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadResetResponse();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadResetResponse();


        };
    }
}
