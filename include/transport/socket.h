#pragma once

#include <boost/asio.hpp>

namespace OpenPST {
	namespace Transport {
		class Socket
		{
			protected:
				boost::asio::io_service io;
				boost::asio::ip::address address;
				boost::asio::ip::tcp::endpoint endpoint;
				boost::asio::ip::tcp::socket socket;
				std::string host;
				int port;

			public:
				Socket(const std::string& host, int port);
				~Socket();			
            private:                
                Socket(const Socket&);
                Socket &operator=(const Socket &p); 
			public:
				
				/*
				* @brief connect
				*/
				void connect();
				
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
				
				/*
				* @brief setHost
				*/
				void setHost(const std::string& host);
				
				/*
				* @brief getHost
				*/
				const std::string& getHost();
				
				/*
				* @brief setPort
				*/
				void setPort(int port);
				
				/*
				* @brief getPort
				*/
				int getPort();
		};

        /**
        * @brief SocketError
        */
		class SocketError : public std::exception
		{
			private:
				const SocketError& operator=(SocketError);
				std::string _what;
			public:
				SocketError(std::string message) : 
					_what(message)  { }
				SocketError(const SocketError& second) : 
					_what(second._what) {}
				virtual ~SocketError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};
	}
}
