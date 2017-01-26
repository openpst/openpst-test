#pragma once

#include "serial/dm_spc_response.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmSpcResponse : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmSpcResponse();
                
                /**
                * @brief Destructor
                */
                ~DmSpcResponse();

                /**
                * @brief Get status
                * @return uint8_t
                */
                uint8_t getStatus();
                
                /**
                * @brief Set status
                * @param uint8_t status
                * @return void
                */
                void setStatus(uint8_t status);

        };
    }
}
