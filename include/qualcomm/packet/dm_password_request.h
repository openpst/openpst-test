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
* @file dm_password_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_packet.h"

using OpenPST::Qualcomm::DmPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmPasswordRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmPasswordRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
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
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
