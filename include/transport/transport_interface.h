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
* @file transport_interface.h
* @package openpst/libopenpst
* @brief All means of transfer of data (serial,tcp,etc) must implement this interface
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "definitions.h"
#include "transport/packet.h"
#include <vector>

namespace OpenPST {
	namespace Transport {
		class TransportInterface
		{
			public:

				/**
				* @brief isOpen
				* 		Check if the TransportInterface has an active connection
				*/
				virtual bool isOpen() = 0;
				
				/**
				* @brief close
				* 		Close the active connection if isOpen
				*/
				virtual void close() = 0;
				
				/**
				* @brief write
				* 		Write a vector buffer. Writes the whole buffer determined by out.size()
				*/
				virtual size_t write(std::vector<uint8_t>& out) = 0;
				
				/**
				* @brief write
				* 		Write a buffer pointer. Writes specified amount
				*/
				virtual size_t write(uint8_t* data, size_t amount) = 0;
				
				/**
				* @brief write
				* 		Write a Packet
				*/
				virtual size_t write(Packet* packet) = 0;
				
				/**
				* @brief read
				* 		Read into vector end, at most specified amount. May not read full amount.
				*/
				virtual size_t read(std::vector<uint8_t>& in, size_t amount) = 0;
				
				/**
				* @brief read
				* 		Read into buffer pointer at most specified amount. May not read full amount.
				*/
				virtual size_t read(uint8_t* in, size_t amount) = 0;
								
				/**
				* @brief read
				* 		Read into Packet and unpack(). Amount is ignored here unless not zero. 
				* 		Otherwise the amount to read will be determined by the Packet
				*/
				virtual size_t read(Packet* packet, size_t amount = 0) = 0;
				
				/**
				* @brief available
				* 		Check to see how much data is available in the OS buffer for reading
				*/
				virtual size_t available() = 0;
		};
	}
}
