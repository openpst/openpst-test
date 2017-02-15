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
* @file serial_port.h
* @package openpst/libopenpst
* @brief Wraps boost::asio::serial_port providing additional functionality on top
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include <boost/asio/serial_port.hpp>

namespace OpenPST {
	namespace Transport {

		class SerialPort : public boost::asio::serial_port
		{
			
			public:
				SerialPort(boost::asio::io_service & io_service) : boost::asio::serial_port(io_service) {}

				size_t available()
				{
					if (!is_open()) {
						return 0;
					}

					boost::system::error_code error;
					#if defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
						COMSTAT status;
						if (::ClearCommError(native_handle(), NULL, &status)) {
							error = boost::system::error_code(
								::GetLastError(), 
								boost::asio::error::get_system_category()
							);
							//throw AsyncSerialError(error.message());
							return 0;
						}
						return static_cast<size_t>(status.cbInQue);
					#else
						int amount = 0;
						if (::ioctl(native_handle(), FIONREAD, &amount)) {
							error = boost::system::error_code(errno, boost::asio::error::get_system_category());
							//throw AsyncSerialError(error.message());
							return 0;
						}
						return static_cast<size_t>(amount);
					#endif
				}

				void flush()
				{
					if (!is_open()) {
						return;
					}
					#ifdef _WIN32
						FlushFileBuffers(native_handle());
					#else
						tcdrain(native_handle());
					#endif
				}

				void flushInput()
				{
					if (!is_open()) {
						return;
					}
					#ifdef _WIN32
						return;
					#else
						tcflush(native_handle(), TCIFLUSH);
					#endif
				}

				void flushOutput()
				{
					if (!is_open()) {
						return;
					}
					#ifdef _WIN32
						return;
					#else
						tcflush(native_handle(), TCOFLUSH);
					#endif
				}
		};

	}
}