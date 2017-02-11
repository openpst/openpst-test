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

#include "transport/transport_interface.h"
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <boost/bind.hpp>

using boost::asio::serial_port_base;
using boost::asio::io_service;
using boost::asio::serial_port;
using boost::asio::deadline_timer;
using boost::system::error_code;
using boost::posix_time::time_duration;

namespace OpenPST {
	namespace Transport {

		class Serial : TransportInterface
		{
			protected:
				io_service     io;
				serial_port    port;				
				deadline_timer timer;
				error_code     lastError;
				size_t received = 0;
				std::string device;
				int timeout;
				std::vector<uint8_t> rxbuff;
				bool timedOut = false;
			public:
				Serial(
					const std::string& device,
					unsigned int baud = 115200,
					int timeout = 1000,
					serial_port_base::parity parity = serial_port_base::parity(serial_port_base::parity::none),
        			serial_port_base::character_size csize = serial_port_base::character_size(8),
        			serial_port_base::flow_control flow = serial_port_base::flow_control(serial_port_base::flow_control::none),
        			serial_port_base::stop_bits stop = serial_port_base::stop_bits(serial_port_base::stop_bits::one)
        		);

				~Serial();			
            private:                
                Serial(const Serial&);
                Serial &operator=(const Serial &p); 
			public:
				/**
				* @brief isOpen
				*/
				bool isOpen();

				/**
				* @brief open
				*/
				void open(const std::string& device,
					unsigned int baud = 115200,
					serial_port_base::parity parity = serial_port_base::parity(serial_port_base::parity::none),
        			serial_port_base::character_size csize = serial_port_base::character_size(8),
        			serial_port_base::flow_control flow = serial_port_base::flow_control(serial_port_base::flow_control::none),
        			serial_port_base::stop_bits stop = serial_port_base::stop_bits(serial_port_base::stop_bits::one)
        		);

				/**
				* @brief close
				*/
				void close();

				/**
				* @brief write
				*/
				size_t write(std::vector<uint8_t>& out);

				/**
				* @brief read
				*/
				size_t read(std::vector<uint8_t>& in, size_t size);

				/**
				* available
				*/
				size_t available();

				/**
				* @brief getDevice
				*/
				const std::string& getDevice();

				/**
				* @brief setTimeout
				*/
				void setTimeout(int timeout);

				/**
				* @brief getTimeout
				*/
				int getTimeout();

			private:
				void doAsyncRead(size_t amount);
				void onReadComplete(const boost::system::error_code& error, size_t received, size_t requested);
				void onTimeout(const boost::system::error_code& error);
		};

        /**
        * @brief SerialError
        */
		class SerialError : public std::exception
		{
			private:
				const SerialError& operator=(SerialError);
				std::string _what;
			public:
				SerialError(std::string message) : 
					_what(message)  { }
				SerialError(const SerialError& second) : 
					_what(second._what) {}
				virtual ~SerialError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};
	}
}
