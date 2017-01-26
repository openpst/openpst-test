/**
* LICENSE PLACEHOLDER
*
* @file sahara_memory_debug64_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/sahara_packet.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaMemoryDebug64Request : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaMemoryDebug64Request();
                
                /**
                * @brief Destructor
                */
                ~SaharaMemoryDebug64Request();

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

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
