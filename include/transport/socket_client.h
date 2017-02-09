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

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/smart_ptr.hpp>
#include <iostream>
#include <vector>

namespace OpenPST {
	namespace Transport {
		class SocketClient
		{
			protected:
				boost::asio::io_service 		 io;
				boost::asio::ip::tcp::endpoint 	 endpoint;
				boost::asio::ip::tcp::socket   	 socket;
				boost::asio::deadline_timer    	 timer;
				boost::asio::deadline_timer    	 heartbeat;
				boost::scoped_ptr<boost::thread> thread;
				std::vector<uint8_t> 			 rxbuffer;
				bool 							 idle;
			public:
				SocketClient();
				SocketClient(const std::string& host, int port);				
				~SocketClient();			
            private:                
                SocketClient(const SocketClient&);
                SocketClient &operator=(const SocketClient &p); 
			public:
				
				/*
				* @brief connect
				*/
				void connect(const std::string& host, int port);
				
				/**
				* @brief connected
				*/
				bool connected();

				/*
				* @brief disconnect
				*/
				void disconnect();
				
				/*
				* @brief write
				*/
				size_t write(std::vector<uint8_t>& out);
				
				/*
				* @brief read
				*/
				size_t read(std::vector<uint8_t>& in, size_t amount);

			private:
				/*
				* @brief write
				*/
				void asyncWrite();
				
				/*
				* @brief read
				*/
				void asyncRead();

				/*
				* @brief onConnect
				*/
				void onConnect(const boost::system::error_code& error);
				
				/*
				* @brief onConnectionTimeout
				*/
				void onConnectionTimeout();
				/*
				* @brief onReceive
				*/
				void onReceive(const boost::system::error_code& error);
				
				/*
				* @brief onSend
				*/
				void onSend(const boost::system::error_code& error);
		};

        /**
        * @brief SocketClientError
        */
		class SocketClientError : public std::exception
		{
			private:
				const SocketClientError& operator=(SocketClientError);
				std::string _what;
			public:
				SocketClientError(std::string message) : 
					_what(message)  { }
				SocketClientError(const SocketClientError& second) : 
					_what(second._what) {}
				virtual ~SocketClientError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};
	}
}
