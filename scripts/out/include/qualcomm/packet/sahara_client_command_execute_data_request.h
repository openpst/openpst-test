#pragma once

#include "serial/sahara_client_command_execute_data_request.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaClientCommandExecuteDataRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaClientCommandExecuteDataRequest();
                
                /**
                * @brief Destructor
                */
                ~SaharaClientCommandExecuteDataRequest();

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

        };
    }
}
