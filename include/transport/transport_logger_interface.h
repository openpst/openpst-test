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
* @file transport_logger_interface.h
* @package openpst/libopenpst
* @brief TransportInterface can log tx and tx data through this interface
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "definitions.h"
#include <vector>

namespace OpenPST {
	namespace Transport {

		class TransportLoggerInterface
		{
			public:

				virtual void logString(const std::string& what) = 0;

				virtual void log(std::vector<uint8_t>& data) = 0;

				virtual void log(uint8_t* data, size_t amount) = 0;

		};
	}
}
