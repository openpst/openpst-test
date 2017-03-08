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
* @file messaged_async_serial.h
* @package openpst/libopenpst
* @brief Read and write serial data. Read data are parsed messages based on control character(s), asynchronous
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "transport/transport_interface.h"
#include "transport/serial.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <queue>

using boost::asio::serial_port_base;
using boost::asio::io_service;
using boost::asio::serial_port;
using boost::asio::deadline_timer;
using boost::system::error_code;
using boost::posix_time::time_duration;

namespace OpenPST {
	namespace Transport {
		

		class MessagedAsyncSerial : public TransportInterface
		{
			protected:
				io_service      io;
				SerialPort      port;
				std::string 	device;
				std::string 	messageEnd;
				int timeout;
				bool timedOut = false;
				boost::thread worker;
				boost::mutex  writeLock;
				boost::mutex  readLock;
				std::queue<std::vector<uint8_t>>  writeQueue;
				boost::asio::streambuf 			  buffer; 
				std::vector<std::vector<uint8_t>> messages;
			public:
				MessagedAsyncSerial(
					const std::string& device,
					const std::string& messageEnd,
					unsigned int baud = 115200,
					int timeout = 1000,
					serial_port_base::parity parity = serial_port_base::parity(serial_port_base::parity::none),
        			serial_port_base::character_size csize = serial_port_base::character_size(8),
        			serial_port_base::flow_control flow = serial_port_base::flow_control(serial_port_base::flow_control::none),
        			serial_port_base::stop_bits stop = serial_port_base::stop_bits(serial_port_base::stop_bits::one)
        		);

				~MessagedAsyncSerial();			
            private:                
                MessagedAsyncSerial(const MessagedAsyncSerial&);
                MessagedAsyncSerial &operator=(const MessagedAsyncSerial &p); 
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
				* @brief getMessageEnd
				*/
				const std::string& getMessageEnd();

				/**
				* @brief setTimeout
				*/
				void setTimeout(int timeout);

				/**
				* @brief getTimeout
				*/
				int getTimeout();

				// void setOnReadCallback(std::function<void(std::vector<uint8_t>& data, size_t amount) cb);

			private:
				void doAsyncRead();
				void doAsyncWrite();
				void onReadComplete(const boost::system::error_code& error, size_t received);
				void onWriteComplete(const boost::system::error_code& error, size_t written);
				void onTimeout(const boost::system::error_code& error);
				void doWork();
				void onWorkComplete();
		};
	}
}
