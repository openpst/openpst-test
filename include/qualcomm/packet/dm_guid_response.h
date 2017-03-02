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
* @file dm_guid_response.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/02/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_packet.h"

using OpenPST::Qualcomm::DmPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmGuidResponse : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmGuidResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmGuidResponse();

                /**
                * @brief Get guid
                * @return uint8_t[]
                */
                std::vector<uint8_t> getGuid();
                
                /**
                * @brief Get guid
                * @return std::string
                */
                std::string getGuid();
                                

                /**
                * @brief Set guid
                * @param uint8_t* guid
                * @param size_t size
                * @return void
                */
                void setGuid(uint8_t* data, size_t size);
                
                /**
                * @brief Set guid
                * @param const std::string& guid
                * @return void
                */
                void setGuid(const std::string& guid);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
