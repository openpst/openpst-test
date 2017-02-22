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
* @file
* @package libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "definitions.h"
#include "transport/transport_interface.h"
#include "transport/packet.h"
#include "qualcomm/dm.h"
#include "qualcomm/dm_packets.h"

namespace OpenPST {
	namespace Qualcomm {
		class DmClient {
			protected:
				TransportInterface& transport;
				PacketEndianess deviceEndianess;
			public:
				DmClient(TransportInterface& transport, PacketEndianess deviceEndianess = kPacketEndianessLittle);

				~DmClient();

				TransportInterface* getTransport();
				/*
				QcdmVersionResponse getVersion();

				uint16_t getDiagVersion();

				QcdmStatusResponse getStatus();

				QcdmGuidResponse getGuid();

				bool sendSpc(std::string spc);

				bool sendPassword(std::string password);

				bool setPhoneMode(QcdmPhoneMode mode);

				QcdmNvResponse readNV(uint16_t itemId);

				bool writeNV(uint16_t itemId, uint8_t* data, size_t size);

				QcdmNvPeekResponse peekNV(uint32_t address, uint8_t size);

				void switchToDload();

				bool sendHtcNvUnlock();

				bool sendLgNvUnlock();  

				bool getLgSpc();
		*/
		};
	}
}