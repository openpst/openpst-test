/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_close_dir_request.h
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
        
        class DmEfsCloseDirRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsCloseDirRequest();
                
                /**
                * @brief Destructor
                */
                ~DmEfsCloseDirRequest();

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
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
