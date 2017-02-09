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
	io(), socket(io), timer(io), heartbeat(io), idle(true)
{

}

SocketClient::SocketClient(const std::string& host, int port) : 
	io(), socket(io), timer(io), heartbeat(io), idle(true)
{
	connect(host, port);
}

SocketClient::~SocketClient()
{	
	io.stop();
	if (thread) {
		thread->join();
	}
}

void SocketClient::connect(const std::string& host, int port)
{	
	if (socket.is_open() || !idle || thread) {
		return;
	}

	boost::asio::ip::tcp::resolver resolver(io);

	boost::asio::ip::tcp::resolver::iterator endpoint_iter;
	
	endpoint_iter = resolver.resolve(boost::asio::ip::tcp::resolver::query(host, std::to_string(port)));

    /*if (endpoint_iter != boost::asio::ip::tcp::resolver::iterator()) {
    	throw SocketClientError("Unable to resolve host");
    }*/

    endpoint = endpoint_iter->endpoint();

    timer.expires_from_now(boost::posix_time::seconds(60));
    timer.async_wait(boost::bind(&SocketClient::onConnectionTimeout, this));

	socket.async_connect(
		endpoint_iter->endpoint(),
        boost::bind(
        	&SocketClient::onConnect,
            this, 
            boost::asio::placeholders::error
        )
    );

    idle = false;

    thread.reset(new boost::thread(
        boost::bind(&boost::asio::io_service::run, &io)
    ));
}

bool SocketClient::connected()
{	
	return socket.is_open();
}

void SocketClient::disconnect()
{	idle = true;
	boost::system::error_code ignored; // prevent exception
	socket.close(ignored);
	timer.cancel();
	heartbeat.cancel();
	io.stop();
	thread->join();
	io.reset();
	thread.reset();
}

size_t SocketClient::write(std::vector<uint8_t>& out)
{	
	return 0;
}

size_t SocketClient::read(std::vector<uint8_t>& in, size_t amount)
{	
	return 0;
}

void SocketClient::asyncWrite()
{

}

void SocketClient::asyncRead()
{
    timer.expires_from_now(boost::posix_time::seconds(30));

    socket.async_read_some(
    	boost::asio::buffer(&rxbuffer[0], rxbuffer.size()), 
        boost::bind(
        	&SocketClient::onReceive, 
        	this, 
        	boost::asio::placeholders::error
        )
   	);
}

void SocketClient::onConnect(const boost::system::error_code& error)
{
	if (idle) {
		return;
	} else if (!socket.is_open()) {
		disconnect();
		throw SocketClientError("Connection timed out");
	} else if (error) {
		disconnect();
		throw SocketClientError(error.message());
	}

	std::cout << "Connected to " << endpoint << std::endl;

	asyncRead();
}

void SocketClient::onConnectionTimeout()
{
	if (idle) {
		return;
	}

	if (timer.expires_at() <= boost::asio::deadline_timer::traits_type::now()) {
		socket.close();
		timer.expires_at(boost::posix_time::pos_infin);
	}

	timer.async_wait(boost::bind(&SocketClient::onConnectionTimeout, this));
}

void SocketClient::onReceive(const boost::system::error_code& error)
{
	if (idle) {
		return;
	} else if (error) {
		disconnect();
	}

}

void SocketClient::onSend(const boost::system::error_code& error)
{
	if (idle) {
		return;
	} else if (error) {
		disconnect();
	}

}
