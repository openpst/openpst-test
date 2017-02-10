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
#include <iostream>

using OpenPST::Transport::Serial;

namespace OpenPST {
	namespace Server {

		enum TcpSerialServerCommand {
			kTcpSerialServerCommandWriteRequest = 1,
			kTcpSerialServerCommandWriteResponse,
			kTcpSerialServerCommandReadRequest,
			kTcpSerialServerCommandReadResponse,
			kTcpSerialServerCommandChangeDeviceRequest,
			kTcpSerialServerCommandChangeDeviceResponse
		};

		/**
		* @brief TcpSerialServerPacketHeader
		*/
		struct TcpSerialServerPacketHeader {
			int 	command;
			size_t  size;
		};

		struct TcpSerialServerReadRequest {
			TcpSerialServerPacketHeader header = {
				kTcpSerialServerCommandWriteRequest, 
				0
			};
			size_t amountToRead;
		};

		struct TcpSerialServerWriteRequest {
			TcpSerialServerPacketHeader header = {
				kTcpSerialServerCommandWriteResponse, 
				0
			};
			size_t amountToWrite;
		};
		
		struct TcpSerialServerChangeDeviceRequest {
			TcpSerialServerPacketHeader header;
			char path[255];
		};

		/**
		* @brief TcpSerialServerResponse
		*/
		struct TcpSerialServerResponse {
			TcpSerialServerPacketHeader  header;
			uint8_t data[0];
		};
		
		/**
		* @brief TcpSerialServerSession
		*/
		class TcpSerialServerSession
		{
			protected:
				boost::asio::ip::tcp::socket socket;
				std::vector<uint8_t> rxbuffer;
				std::vector<uint8_t> txbuffer;
				Serial& port;
			public:
				TcpSerialServerSession(boost::asio::io_service& io, Serial& serial);
				~TcpSerialServerSession();
				boost::asio::ip::tcp::socket& getSocket();
				void start();
            private:                
                TcpSerialServerSession(const TcpSerialServerSession&);
                TcpSerialServerSession &operator=(const TcpSerialServerSession &p); 
				void onReceive(const boost::system::error_code& error, size_t received);
				void onSend(const boost::system::error_code& error, size_t sent);
		};

		/**
		* @brief TcpSerialServer
		*/
		class TcpSerialServer
		{
			protected:
				boost::asio::io_service io;
				boost::asio::ip::tcp::acceptor acceptor;
				boost::asio::ip::tcp::endpoint endpoint;
				Serial& port;
			public:
				TcpSerialServer(Serial& port);
				//TcpSerialServer(const std::string hostname, int port, Serial& port);
				~TcpSerialServer();
				void start(const std::string hostname, int port);
				void start(int port);
				void stop();
			private:                          
                TcpSerialServer(const TcpSerialServer&);
                TcpSerialServer &operator=(const TcpSerialServer &p);
                void accept();
				void onAccept(TcpSerialServerSession* session, const boost::system::error_code& error);  			
		};


        /**
        * @brief TcpSerialServerError
        */
		class TcpSerialServerError : public std::exception
		{
			private:
				const TcpSerialServerError& operator=(TcpSerialServerError);
				std::string _what;
			public:
				TcpSerialServerError(std::string message) : 
					_what(message)  { }
				TcpSerialServerError(const TcpSerialServerError& second) : 
					_what(second._what) {}
				virtual ~TcpSerialServerError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};
	}
}
