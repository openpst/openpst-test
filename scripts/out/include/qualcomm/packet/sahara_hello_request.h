/**
* LICENSE PLACEHOLDER
*
* @file sahara_hello_request.h
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
        
        class SaharaHelloRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaHelloRequest();
                
                /**
                * @brief Destructor
                */
                ~SaharaHelloRequest();

                /**
                * @brief Get version
                * @return uint32_t
                */
                uint32_t getVersion();
                
                /**
                * @brief Set version
                * @param uint32_t version
                * @return void
                */
                void setVersion(uint32_t version);
                /**
                * @brief Get min_version
                * @return uint32_t
                */
                uint32_t getMinVersion();
                
                /**
                * @brief Set min_version
                * @param uint32_t minVersion
                * @return void
                */
                void setMinVersion(uint32_t minVersion);
                /**
                * @brief Get max_command_packet_size
                * @return uint32_t
                */
                uint32_t getMaxCommandPacketSize();
                
                /**
                * @brief Set max_command_packet_size
                * @param uint32_t maxCommandPacketSize
                * @return void
                */
                void setMaxCommandPacketSize(uint32_t maxCommandPacketSize);
                /**
                * @brief Get status
                * @return uint32_t
                */
                uint32_t getStatus();
                
                /**
                * @brief Set status
                * @param uint32_t status
                * @return void
                */
                void setStatus(uint32_t status);
                /**
                * @brief Get reserved
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getReserved();
                
                /**
                * @brief Set reserved
                * @param uint8_t* reserved
                * @param size_t size
                * @return void
                */
                void setReserved(uint8_t* data, size_t size);
                /**
                * @brief Get mode
                * @return uint32_t
                */
                uint32_t getMode();
                
                /**
                * @brief Set mode
                * @param uint32_t mode
                * @return void
                */
                void setMode(uint32_t mode);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
