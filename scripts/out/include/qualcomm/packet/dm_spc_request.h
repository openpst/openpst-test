#pragma once

#include "serial/dm_spc_request.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmSpcRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmSpcRequest();
                
                /**
                * @brief Destructor
                */
                ~DmSpcRequest();

                /**
                * @brief Get spc
                * @return uint8_t[]
                */
                std::vector<uint8_t> getSpc();
                /**
                * @brief Get spc
                * @return std::string
                */
                std::string getSpc();
                
                /**
                * @brief Set spc
                * @param uint8_t* spc
                * @param size_t size
                * @return void
                */
                void setSpc(uint8_t* data, size_t size);
                /**
                * @brief Set spc
                * @param const std::string& spc
                * @return void
                */
                void setSpc(const std::string& spc);

        };
    }
}
