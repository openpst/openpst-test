/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_end_image_transfer_response.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/02/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/sahara_packet.h"

using OpenPST::Qualcomm::SaharaPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class SaharaEndImageTransferResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaEndImageTransferResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~SaharaEndImageTransferResponse();

                
                /**
                * @brief Get image_id
                * @return uint32_t
                */
                uint32_t getImageId();
                                

                /**
                * @brief Set image_id
                * @param uint32_t imageId
                * @return void
                */
                void setImageId(uint32_t imageId);
                                
                /**
                * @brief Get status
                * @return uint32_t
                */
                uint32_t getStatus();
                                

                /**
                * @brief Set status
                * @param uint32_t status
                * @return void
                */
                void setStatus(uint32_t status);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
