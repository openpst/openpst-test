#pragma once

#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <boost/bind.hpp>
//#include <boost/thread.hpp>

namespace OpenPST {
	namespace Transport {
		class Serial
		{
			protected:
				boost::asio::io_service   io;
				boost::asio::serial_port  port;
				boost::system::error_code lastError;
				std::string device;

				// default options
				int baudRate 	  = 115200;
				int timeout   	  = 0;
			public:
				Serial(const std::string& device, int baudrate, int timeout);
				~Serial();			
            private:                
                Serial(const Serial&);
                Serial &operator=(const Serial &p); 
			public:
				/**
				* @brief isOpen
				*/
				bool isOpen();

				/**
				* @brief open
				*/
				void open();

				/**
				* @brief close
				*/
				void close();

				/**
				* @brief write
				*/
				size_t write(std::vector<uint8_t>& out);
				//size_t writeAsync(std::vector<uint8_t>& out);

				/**
				* @brief read
				*/
				size_t read(std::vector<uint8_t>& in, size_t size);
				//size_t readAsync(std::vector<uint8_t>& in, size_t size);

				/**
				* @brief setDevice
				*/
				void setDevice(const std::string& device);

				/**
				* @brief getDevice
				*/
				const std::string& getDevice();

				/**
				* @brief setBaudRate
				*/
				void setBaudRate(int baudRate);

				/**
				* @brief getBaudRate
				*/
				int getBaudRate();

				/**
				* @brief setTimeout
				*/
				void setTimeout(int timeout);

				/**
				* @brief getTimeout
				*/
				int getTimeout();

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
