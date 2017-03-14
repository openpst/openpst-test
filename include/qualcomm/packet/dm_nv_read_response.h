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
* @file dm_nv_read_response.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_packet.h"

using OpenPST::Qualcomm::DmPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmNvReadResponse : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmNvReadResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmNvReadResponse();

                
                /**
                * @brief Get nv_item
                * @return uint16_t
                */
                uint16_t getNvItem();
                                

                /**
                * @brief Set nv_item
                * @param uint16_t nvItem
                * @return void
                */
                void setNvItem(uint16_t nvItem);
                
                /**
                * @brief Get data
                * @return uint8_t[]
                */
                std::vector<uint8_t> getData();
                
                /**
                * @brief Get data
                * @return std::string
                */
                std::string getData();
                                

                /**
                * @brief Set data
                * @param uint8_t* data
                * @param size_t size
                * @return void
                */
                void setData(uint8_t* data, size_t size);
                
                /**
                * @brief Set data
                * @param const std::string& data
                * @return void
                */
                void setData(const std::string& data);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
