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
* @file dm_efs_access_request.h
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
        
        class DmEfsAccessRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsAccessRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsAccessRequest();

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
