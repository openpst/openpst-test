/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_open_dir_response.h
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
        
        class QcdmEfsOpenDirResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                QcdmEfsOpenDirResponse();
                
                /**
                * @brief Destructor
                */
                ~QcdmEfsOpenDirResponse();

                /**
                * @brief Get dp
                * @return uint32_t
                */
                uint32_t getDp();
                
                /**
                * @brief Set dp
                * @param uint32_t dp
                * @return void
                */
                void setDp(uint32_t dp);
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
