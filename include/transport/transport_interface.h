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
* @package 
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "definitions.h"
#include <vector>

namespace OpenPST {
	namespace Transport {
		class TransportInterface
		{
			public:
				
				/*
				* @brief write
				*/
				virtual size_t write(std::vector<uint8_t>& out) = 0;
				
				virtual size_t write(uint8_t* data, size_t amount) = 0;
				
				/*
				* @brief read
				*/
				virtual size_t read(std::vector<uint8_t>& in, size_t amount) = 0;

				virtual size_t read(uint8_t* in, size_t amount) = 0;
		};
	}
}
