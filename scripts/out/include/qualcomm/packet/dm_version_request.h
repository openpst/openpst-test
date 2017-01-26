#pragma once

#include "serial/dm_version_request.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmVersionRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmVersionRequest();
                
                /**
                * @brief Destructor
                */
                ~DmVersionRequest();

                /**
                * @brief Get version
                * @return uint16_t
                */
                uint16_t getVersion();
                
                /**
                * @brief Set version
                * @param uint16_t version
                * @return void
                */
                void setVersion(uint16_t version);

        };
    }
}
