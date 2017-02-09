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
* @file sahara_command_memory_debug64_request.h
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
        
        class SaharaCommandMemoryDebug64Request : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaCommandMemoryDebug64Request(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~SaharaCommandMemoryDebug64Request();

                /**
                * @brief Get client_command
                * @return uint64_t
                */
                uint64_t getClientCommand();
                
                /**
                * @brief Set client_command
                * @param uint64_t clientCommand
                * @return void
                */
                void setClientCommand(uint64_t clientCommand);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
