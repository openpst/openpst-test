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

#include "transport/packet_transporter.h"
#include "transport/packet.h"
#include "qualcomm/hdlc_encoder.h"

namespace OpenPST {
	namespace Qualcomm {
		class HdlcPacketTransporter : public PacketTransporter
		{
			protected:
				HdlcEncoder encoder;

			public:
	        	void write(Packet* packet, bool andRead = true) override;

	            void read(Packet* packet, bool andWrite = true) override;
		};
	}
}