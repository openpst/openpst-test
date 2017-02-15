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
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/smart_ptr.hpp>
#include <iostream>
#include <vector>

namespace OpenPST {
	namespace Transport {
		class Tcp : public TransportInterface
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
				Tcp();
				Tcp(const std::string& host, int port, int timeout = 30);				
				~Tcp();			
            private:                
                Tcp(const Tcp&);
                Tcp &operator=(const Tcp &p); 
			public:
				
				/*
				* @brief connect
				*/
				void connect(const std::string& host, int port, int timeout = 30);

				/**
				* @brief connected
				*/
				bool connected();

				/*
				* @brief disconnect
				*/
				void disconnect();
				
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
				void start(const boost::asio::ip::tcp::endpoint& endpoint);

				void stop();
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

				/**
				* doWork
				*/
				void doWork();


				/**
				* onWorkComplete
				*/
				void onWorkComplete();
		};

        /**
        * @brief TcpError
        */
		class TcpError : public std::exception
		{
			private:
				const TcpError& operator=(TcpError);
				std::string _what;
			public:
				TcpError(std::string message) : 
					_what(message)  { }
				TcpError(const TcpError& second) : 
					_what(second._what) {}
				virtual ~TcpError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};
	}
}
