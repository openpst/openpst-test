#pragma once

#include <vector>
#include <stdint.h>
#include <algorithm>
#include <stdexcept>
#include "qualcomm/packet/sahara_packet.h"
#include "qualcomm/mbn.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaReadDataResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaReadDataResponse();
                
                /**
                * @brief Destructor
                */
                ~SaharaReadDataResponse();

                /**
                * @brief Set the image id 
                * @param uint32_t imageId
                * @return void
                */
                void setImageId(uint32_t imageId);

                /**
                * @brief Get the image id
                * @return uint32_t
                */
                uint32_t getImageId();

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

                /**
                * @override Packet::unpack()
                */
                void unpack(std::vector<uint8_t>& data) override;
        };
    }
}
