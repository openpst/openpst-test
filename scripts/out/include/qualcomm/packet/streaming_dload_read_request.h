#pragma once

#include "serial/streaming_dload_read_request.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadReadRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadReadRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadReadRequest();

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
                /**
                * @brief Get length
                * @return uint16_t
                */
                uint16_t getLength();
                
                /**
                * @brief Set length
                * @param uint16_t length
                * @return void
                */
                void setLength(uint16_t length);

        };
    }
}
