/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_lstat_request.h
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
        
        class QcdmEfsLstatRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                QcdmEfsLstatRequest();
                
                /**
                * @brief Destructor
                */
                ~QcdmEfsLstatRequest();

                /**
                * @brief Get path
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getPath();
                
                /**
                * @brief Set path
                * @param uint8_t* path
                * @param size_t path
                * @return void
                */
                void setPath(uint8_t* data, size_t size);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
