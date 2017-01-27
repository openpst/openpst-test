/**
* LICENSE PLACEHOLDER
*
* @file qcdm_efs_create_link_request.h
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
        
        class QcdmEfsCreateLinkRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                QcdmEfsCreateLinkRequest();
                
                /**
                * @brief Destructor
                */
                ~QcdmEfsCreateLinkRequest();

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
                * @brief Get new_path
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getNewPath();
                
                /**
                * @brief Set new_path
                * @param uint8_t* newPath
                * @param size_t newPath
                * @return void
                */
                void setNewPath(uint8_t* data, size_t size);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
