#pragma once

#include "serial/sahara_memory_debug_request.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaMemoryDebugRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaMemoryDebugRequest();
                
                /**
                * @brief Destructor
                */
                ~SaharaMemoryDebugRequest();

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
                * @brief Get size
                * @return uint32_t
                */
                uint32_t getSize();
                
                /**
                * @brief Set size
                * @param uint32_t size
                * @return void
                */
                void setSize(uint32_t size);

        };
    }
}
