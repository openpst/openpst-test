#pragma once

#include "serial/sahara_client_command_response.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaClientCommandResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaClientCommandResponse();
                
                /**
                * @brief Destructor
                */
                ~SaharaClientCommandResponse();

                /**
                * @brief Get client_command
                * @return uint32_t
                */
                uint32_t getClientCommand();
                
                /**
                * @brief Set client_command
                * @param uint32_t clientCommand
                * @return void
                */
                void setClientCommand(uint32_t clientCommand);
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
