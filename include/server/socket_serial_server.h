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
		* @brief SocketSerialServerRequest
		*/
		struct SocketSerialServerRequest {
			size_t  size;
			uint8_t data[0];
		};

		/**
		* @brief SocketSerialServerResponse
		*/
		struct SocketSerialServerResponse {
			int  	status;
			size_t  size;
			uint8_t data[0];
		};

		/**
		* @brief SocketSerialServer
		*/
		class SocketSerialServer
		{
			protected:
				boost::asio::io_service io;
				boost::asio::ip::tcp::acceptor acceptor;
				Serial& serial;
			public:
				SocketSerialServer(Serial& port);
				~SocketSerialServer();
				void start(const std::string hostname, int port);
				void stop();
			private:                          
                SocketSerialServer(const SocketSerialServer&);
                SocketSerialServer &operator=(const SocketSerialServer &p); 
				void onAccept(SocketSerialServerSession* session, const boost::system::error_code& error);  			
		};
		
		/**
		* @brief SocketSerialServerSession
		*/
		class SocketSerialServerSession
		{
			protected:
				boost::asio::ip::tcp::socket socket;
				std::vector<uint8_t> readBuffer;
				std::vector<uint8_t> writeBuffer;
				Serial serial;
			public:
				SocketSerialServerSession(boost::asio::io_service& io, Serial& serial);
				~SocketSerialServerSession();
				boost::asio::ip::tcp::socket& getSocket();
				void start();
            private:                
                SocketSerialServerSession(const SocketSerialServerSession&);
                SocketSerialServerSession &operator=(const SocketSerialServerSession &p); 
				void handleRead(const boost::system::error_code& error, size_t amount);
				void handleWrite(size_t amount, const boost::system::error_code& error);
		};
	}
}
