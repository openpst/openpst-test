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
* @file sahara_command_ready_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/sahara_packet.h"

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaCommandReadyResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaCommandReadyResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
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
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
