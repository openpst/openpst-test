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

#include "transport/serial.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <vector>

using OpenPST::Transport::Serial;

namespace OpenPST {
	namespace Server {

		/**
		* @brief RemoteSocketSerialServerRequest
		*/
		struct RemoteSocketSerialServerRequest {
			uint8_t data[0];
		};

		/**
		* @brief RemoteSocketSerialServerResponse
		*/
		struct RemoteSocketSerialServerResponse {
			int status;
			size_t amount;
			uint8_t data[0];
		};

		/**
		* @brief RemoteSocketSerialServer
		*/
		class RemoteSocketSerialServer
		{
			protected:
				boost::asio::io_service io;
				boost::asio::ip::tcp::acceptor acceptor;
				Serial serial;
			public:
				RemoteSocketSerialServer(int port, const std::string& device, int baudrate, int timeout);
				~RemoteSocketSerialServer();

			private:                          
                RemoteSocketSerialServer(const RemoteSocketSerialServer&);
                RemoteSocketSerialServer &operator=(const RemoteSocketSerialServer &p); 
				void start();
				void accept(RemoteSocketSerialServerSession* session, const boost::system::error_code& error);  			
		};
		
		/**
		* @brief RemoteSocketSerialServerSession
		*/
		class RemoteSocketSerialServerSession
		{
			protected:
				boost::asio::ip::tcp::socket socket;
				std::vector<uint8_t> readBuffer;
				std::vector<uint8_t> writeBuffer;
				Serial serial;
			public:
				RemoteSocketSerialServerSession(boost::asio::io_service& io, Serial& serial);
				~RemoteSocketSerialServerSession();
				boost::asio::ip::tcp::socket& getSocket();
				void start();
            private:                
                RemoteSocketSerialServerSession(const RemoteSocketSerialServerSession&);
                RemoteSocketSerialServerSession &operator=(const RemoteSocketSerialServerSession &p); 
				void handleRead(const boost::system::error_code& error, size_t amount);
				void handleWrite(size_t amount, const boost::system::error_code& error);
		};
	}
}
