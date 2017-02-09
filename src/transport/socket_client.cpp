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

#include "transport/socket_client.h"

using namespace OpenPST::Transport;

SocketClient::SocketClient() : 
	io(), socket(io), timer(io), heartbeat(io)
{

}

SocketClient::SocketClient(const std::string& host, int port) : 
	host(host), port(port), io(), socket(io), timer(io), heartbeat(io)
{
	connect(host, port);
}

SocketClient::~SocketClient()
{

}

void SocketClient::connect(const std::string& host, int port)
{

}

void SocketClient::disconnect()
{

}

size_t SocketClient::write(std::vector<uint8_t>& out)
{
	return 0;
}

size_t SocketClient::read(std::vector<uint8_t>& in, size_t amount)
{
	return 0;
}

void SocketClient::onConnect(const boost::system::error_code& ec)
{

}

void SocketClient::onReceive(const boost::system::error_code& ec)
{

}

void SocketClient::onSend(const boost::system::error_code& ec)
{

}
