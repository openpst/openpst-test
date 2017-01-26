/**
* LICENSE PLACEHOLDER
*
* @file k_sahara_command_memory_debug64_request.h
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
        
        class kSaharaCommandMemoryDebug64Request : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                kSaharaCommandMemoryDebug64Request();
                
                /**
                * @brief Destructor
                */
                ~kSaharaCommandMemoryDebug64Request();

                /**
                * @brief Get client_command
                * @return uint64_t
                */
                uint64_t getClientCommand();
                
                /**
                * @brief Set client_command
                * @param uint64_t clientCommand
                * @return void
                */
                void setClientCommand(uint64_t clientCommand);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
