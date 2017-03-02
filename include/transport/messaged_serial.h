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
* @file messaged_serial.h
* @package openpst/libopenpst
* @brief Read and write serial data. Read data are parsed messages based on control character(s).
*		Ideal for protocols like AT which end in \r\n or HDLC framed in 0x7E
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "transport/transport_interface.h"
#include "transport/serial.h"
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

		class MessagedSerial : public TransportInterface
		{
			protected:
				io_service     io;
				SerialPort     port;				
				deadline_timer timer;
				int 		   timeout;
				std::string    device;
				std::string    messageEnd;
				bool 		   timedOut = false;
				boost::asio::streambuf 	buffer; 
				std::vector<std::vector<uint8_t>> messages;
			public:
				MessagedSerial(
					const std::string& device,
					const std::string& messageEnd,
					unsigned int baud = 115200,
					int timeout = 1000,
					serial_port_base::parity parity = serial_port_base::parity(serial_port_base::parity::none),
        			serial_port_base::character_size csize = serial_port_base::character_size(8),
        			serial_port_base::flow_control flow = serial_port_base::flow_control(serial_port_base::flow_control::none),
        			serial_port_base::stop_bits stop = serial_port_base::stop_bits(serial_port_base::stop_bits::one)
        		);

				~MessagedSerial();			
            private:                
                MessagedSerial(const MessagedSerial&);
                MessagedSerial &operator=(const MessagedSerial &p); 
			public:

				/**
				* @brief open
				*/
				void open(const std::string& device,
					const std::string& messageEnd,
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
				* @note amount is not used. read is performed until 
				* a message has ended by messageEnd variable or time out
				*/
				size_t read(std::vector<uint8_t>& in, size_t amount) override;
				
				/**
				* @brief read
				* @see TransportInterface
				* @note amount is not used. read is performed until 
				* a message has ended by messageEnd variable or time out
				*/
				size_t read(uint8_t* in, size_t amount) override;
				
				/**
				* @brief read
				* @see TransportInterface
				* @note amount is not used. read is performed until 
				* a message has ended by messageEnd variable or time out
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
				* @brief getMessageEnd - get the current message end string terminator
				*/
				const std::string& getMessageEnd();

				/**
				* @brief - Get a what should be read only reference to the current message buffer.
				* 			Use this for peeking, use read() to pop out messages
				*/
				const std::vector<std::vector<uint8_t>>& getMessages();

				/**
				* @brief setTimeout
				*/
				void setTimeout(int timeout);

				/**
				* @brief getTimeout
				*/
				int getTimeout();

			private:
				void doAsyncRead();
				void onReadComplete(const boost::system::error_code& error, size_t received);
				void onTimeout(const boost::system::error_code& error);
		};
	}
}
