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
