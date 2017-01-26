#pragma once

#include "serial/dm_password_request.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmPasswordRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmPasswordRequest();
                
                /**
                * @brief Destructor
                */
                ~DmPasswordRequest();

                /**
                * @brief Get password
                * @return uint8_t[]
                */
                std::vector<uint8_t> getPassword();
                /**
                * @brief Get password
                * @return std::string
                */
                std::string getPassword();
                
                /**
                * @brief Set password
                * @param uint8_t* password
                * @param size_t size
                * @return void
                */
                void setPassword(uint8_t* data, size_t size);
                /**
                * @brief Set password
                * @param const std::string& password
                * @return void
                */
                void setPassword(const std::string& password);

        };
    }
}
