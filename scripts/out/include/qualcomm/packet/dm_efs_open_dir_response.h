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
* @file dm_efs_open_dir_response.h
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
        
        class DmEfsOpenDirResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsOpenDirResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsOpenDirResponse();

                /**
                * @brief Get dp
                * @return uint32_t
                */
                uint32_t getDp();
                
                /**
                * @brief Set dp
                * @param uint32_t dp
                * @return void
                */
                void setDp(uint32_t dp);
                /**
                * @brief Get error
                * @return uint32_t
                */
                uint32_t getError();
                
                /**
                * @brief Set error
                * @param uint32_t error
                * @return void
                */
                void setError(uint32_t error);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
