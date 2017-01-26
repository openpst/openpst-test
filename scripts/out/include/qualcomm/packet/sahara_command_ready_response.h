#pragma once

#include "serial/sahara_command_ready_response.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaCommandReadyResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaCommandReadyResponse();
                
                /**
                * @brief Destructor
                */
                ~SaharaCommandReadyResponse();

                /**
                * @brief Get image_tx_status
                * @return uint32_t
                */
                uint32_t getImageTxStatus();
                
                /**
                * @brief Set image_tx_status
                * @param uint32_t imageTxStatus
                * @return void
                */
                void setImageTxStatus(uint32_t imageTxStatus);

        };
    }
}
