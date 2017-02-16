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
* @file tcp_serial_client.h
* @package openpst/libopenpst
* @brief A client wrapper for TcpSerialServer
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "transport/tcp.h"
#include "server/tcp_serial_server.h"

using OpenPST::Transport::Tcp;

namespace OpenPST {
	namespace Transport {
		class TcpSerialClient : public Tcp
		{
			
			public:
				TcpSerialClient();
				TcpSerialClient(const std::string& host, int port, int timeout = 30);				
				~TcpSerialClient();		
				size_t write(std::vector<uint8_t>& out) override;
				size_t read(std::vector<uint8_t>& in, size_t amount) override;
				bool switchPort(const std::string& port);
            private:                
                TcpSerialClient(const TcpSerialClient&);
                TcpSerialClient &operator=(const TcpSerialClient &p); 
			public:

		};

	}
}
