#pragma once

#include <vector>
#include <stdint.h>
#include <algorithm>
#include <stdexcept>
#include "qualcomm/packet/sahara_packet.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaHelloResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaHelloResponse();
                
                /**
                * @brief Destructor
                */
                ~SaharaHelloResponse();

                /**
                * @brief Set session version
                * @param uint32_t version
                * @return void
                */
                void setVersion(uint32_t version);

                /**
                * @brief Get the current version
                * @return uint32_t
                */
                uint32_t getVersion();

                /**
                * @brief Set session min version
                * @param uint8_t minVersion
                * @return void
                */
                void setMinVersion(uint32_t minVersion);
                
                /**
                * @brief Get the current compatible version
                * @return uint32_t
                */
                uint32_t getMinVersion();

                /**
                * @brief Query for features
                * @param uint8_t featureBits
                * @return void
                */
                void setMaxCommandPacketSize(uint32_t maxCommandPacketSize);

                /**
                * @brief Get the current feature bits
                * @return uint8_t
                */
                uint32_t getMaxCommandPacketSize();

        };
    }
}
