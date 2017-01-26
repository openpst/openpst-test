#pragma once

#include "serial/streaming_dload_nop_request.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadNopRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadNopRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadNopRequest();

                /**
                * @brief Get identifier
                * @return uint32_t
                */
                uint32_t getIdentifier();
                
                /**
                * @brief Set identifier
                * @param uint32_t identifier
                * @return void
                */
                void setIdentifier(uint32_t identifier);

        };
    }
}
