/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_access_request.h
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
        
        class QcdmEfsAccessRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                QcdmEfsAccessRequest();
                
                /**
                * @brief Destructor
                */
                ~QcdmEfsAccessRequest();

                /**
                * @brief Get permission_mask
                * @return uint32_t
                */
                uint32_t getPermissionMask();
                
                /**
                * @brief Set permission_mask
                * @param uint32_t permissionMask
                * @return void
                */
                void setPermissionMask(uint32_t permissionMask);
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
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
