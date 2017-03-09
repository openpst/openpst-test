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
* @file messaged_transport_interface.h
* @package openpst/libopenpst
* @brief Extends TransportInterface for protocols which are messaged, like AT or HDLC
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "definitions.h"
#include "transport/transport_interface.h"
#include <vector>

namespace OpenPST {
	namespace Transport {

		class MessagedTransportInterface : public TransportInterface
		{
			public:
				virtual const std::vector<std::vector<uint8_t>>& getMessages() = 0;

		};
	}
}
