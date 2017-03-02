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
* @file dm_efs_sync_request.h
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/02/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::Qualcomm::DmEfsPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmEfsSyncRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsSyncRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsSyncRequest();

                
                /**
                * @brief Get sequence
                * @return uint16_t
                */
                uint16_t getSequence();
                                

                /**
                * @brief Set sequence
                * @param uint16_t sequence
                * @return void
                */
                void setSequence(uint16_t sequence);
                
                /**
                * @brief Get path
                * @return variable
                */
                std::vector<uint8_t> getPath();
                                

                /**
                * @brief Set path
                * @param uint8_t* path
                * @param size_t size
                * @return void
                */
                void setPath(uint8_t* data, size_t size);
                				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
