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
* @file usb.h
* @package openpst/libopenpst
* @brief Read and write from usb endpoint(s)
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "transport/transport_interface.h"

namespace OpenPST {
	namespace Transport {
		class Usb : public TransportInterface
		{
			protected:
				
			public:
				Usb();
				Usb(uint16_t vendor, uint16_t product, int inEndpoint, int outEndpoint, int timeout = 30);
				~Usb();			
            private:                
                Usb(const Usb&);
                Usb &operator=(const Usb &p); 
			public:				
				/**
				* @brief isOpen
				*/
				bool isOpen() override;
				
				/**
				* @brief close
				* @see TransportInterface
				*/
				void close() override;

				/**
				* @brief write
				* @see TransportInterface
				*/
				size_t write(std::vector<uint8_t>& out) override;
				
				/**
				* @brief write
				* @see TransportInterface
				*/
				size_t write(uint8_t* out, size_t amount) override;

				/**
				* @brief write
				* @see TransportInterface
				*/
				size_t write(Packet* packet) override;

				/**
				* @brief read
				* @see TransportInterface
				*/
				size_t read(std::vector<uint8_t>& in, size_t amount) override;
				
				/**
				* @brief read
				* @see TransportInterface
				*/
				size_t read(uint8_t* in, size_t amount) override;
				
				/**
				* @brief read
				* @see TransportInterface
				*/
				size_t read(Packet* packet, size_t amount = 0) override;

				/**
				* @brief available
				* @see TransportInterface
				*/
				size_t available() override;

			private:
		};

        /**
        * @brief UsbError
        */
		class UsbError : public std::exception
		{
			private:
				const UsbError& operator=(UsbError);
				std::string _what;
			public:
				UsbError(std::string message) : 
					_what(message)  { }
				UsbError(const UsbError& second) : 
					_what(second._what) {}
				virtual ~UsbError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};
	}
}
