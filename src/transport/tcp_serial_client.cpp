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

#include "transport/tcp_serial_client.h"

using namespace OpenPST::Transport;

TcpSerialClient::TcpSerialClient() : 
	Tcp()
{

}

TcpSerialClient::TcpSerialClient(const std::string& host, int port, int timeout) : 
	Tcp(host, port, timeout)
{
	connect(host, port, timeout);
}

TcpSerialClient::~TcpSerialClient()
{	

}

size_t TcpSerialClient::write(std::vector<uint8_t>& out)
{	
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return 0;
}

size_t TcpSerialClient::read(std::vector<uint8_t>& in, size_t amount)
{	
	TcpSerialServerReadRequest request = {};

	request.header.size 	= sizeof(request);
	request.amountToRead    = amount;

	//Tcp::write()
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return 0;
}

bool switchPort(const std::string& port)
{
	return false;
}
