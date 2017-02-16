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
* @file packet.h
* @package openpst/libopenpst
* @brief Read and write serial data
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

	/**
	* @brief SerialPort - we suppliment boost serial port with some additional features we need
	*/
	class SerialPort : public boost::asio::serial_port
		{
			
			public:
				SerialPort(boost::asio::io_service & io_service) : boost::asio::serial_port(io_service) {}

				size_t available()
				{
					if (!is_open()) {
						return 0;
					}

					boost::system::error_code error;
					#if defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
						COMSTAT status;
						if (::ClearCommError(native_handle(), NULL, &status)) {
							error = boost::system::error_code(
								::GetLastError(), 
								boost::asio::error::get_system_category()
							);
							//throw AsyncSerialError(error.message());
							return 0;
						}
						return static_cast<size_t>(status.cbInQue);
					#else
						int amount = 0;
						if (::ioctl(native_handle(), FIONREAD, &amount)) {
							error = boost::system::error_code(errno, boost::asio::error::get_system_category());
							//throw AsyncSerialError(error.message());
							return 0;
						}
						return static_cast<size_t>(amount);
					#endif
				}

				void flush()
				{
					if (!is_open()) {
						return;
					}
					#ifdef _WIN32
						FlushFileBuffers(native_handle());
					#else
						tcdrain(native_handle());
					#endif
				}

				void flushInput()
				{
					if (!is_open()) {
						return;
					}
					#ifdef _WIN32
						return;
					#else
						tcflush(native_handle(), TCIFLUSH);
					#endif
				}

				void flushOutput()
				{
					if (!is_open()) {
						return;
					}
					#ifdef _WIN32
						return;
					#else
						tcflush(native_handle(), TCOFLUSH);
					#endif
				}
		};

		class Serial : public TransportInterface
		{
			protected:
				io_service     io;
				SerialPort     port;				
				deadline_timer timer;
				int 		   timeout;
				std::string    device;
				size_t 		   received = 0;
				bool 		   timedOut = false;
				std::vector<uint8_t> buffer;
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
				void onReadReady(const boost::system::error_code& error, size_t requested);
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
