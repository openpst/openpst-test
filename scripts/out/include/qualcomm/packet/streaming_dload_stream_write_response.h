#pragma once

#include "serial/streaming_dload_stream_write_response.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadStreamWriteResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadStreamWriteResponse();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadStreamWriteResponse();

                /**
                * @brief Get address
                * @return uint32_t
                */
                uint32_t getAddress();
                
                /**
                * @brief Set address
                * @param uint32_t address
                * @return void
                */
                void setAddress(uint32_t address);

        };
    }
}
