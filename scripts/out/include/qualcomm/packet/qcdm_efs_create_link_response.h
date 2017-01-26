/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_create_link_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::QC::DmEfsPacket;

namespace OpenPST {
    namespace QC {
        
        class QcdmEfsCreateLinkResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                QcdmEfsCreateLinkResponse();
                
                /**
                * @brief Destructor
                */
                ~QcdmEfsCreateLinkResponse();

                /**
                * @brief Get error
                * @return uint32_t
                */
                uint32_t getError();
                
                /**
                * @brief Set error
                * @param uint32_t error
                * @return void
                */
                void setError(uint32_t error);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
