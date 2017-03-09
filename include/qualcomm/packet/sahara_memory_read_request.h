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
* @file sahara_memory_read_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/sahara_packet.h"

using OpenPST::Qualcomm::SaharaPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class SaharaMemoryReadRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaMemoryReadRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~SaharaMemoryReadRequest();

                
                /**
                * @brief Get address
                * @return uint32_t
                */
                uint32_t getAddress();
                                

                /**
                * @brief Set address
                * @param uint32_t address
                * @return void
                */
                void setAddress(uint32_t address);
                                
                /**
                * @brief Get size
                * @return uint32_t
                */
                uint32_t getSize();
                                

                /**
                * @brief Set size
                * @param uint32_t size
                * @return void
                */
                void setSize(uint32_t size);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
