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

#include "server/socket_serial_server.h"

using namespace OpenPST::Server;

/**
* SocketSerialServer
*/
SocketSerialServer::SocketSerialServer(Serial& port) : 
    io(),
    acceptor(io),
	port(port)
{

}

SocketSerialServer::~SocketSerialServer()
{

}

void SocketSerialServer::start(const std::string listenHost, int listenPort)
{
	SocketSerialServerSession* session = new SocketSerialServerSession(io);
	
    acceptor.async_accept(session->getSocket(), boost::bind(&SocketSerialServer::accept, this, session, boost::asio::placeholders::error));
}

void SocketSerialServer::stop()
{

}

void SocketSerialServer::onAccept(SocketSerialServerSession* session, const boost::system::error_code& error)
{
    if (!error) {
    	session->start();
    } else {
    	delete session;
    }

    accept();
}

/**

SocketSerialServerSession::SocketSerialServerSession(boost::asio::io_service& io, Serial& serial) : socket(io), serial(serial)
{

}

SocketSerialServerSession::~SocketSerialServerSession()
{

}

boost::asio::ip::tcp::socket& SocketSerialServerSession::getSocket()
{
	return socket;
}

void SocketSerialServerSession::start()
{
    socket.async_read_some(
        //boost::asio::buffer(buffer, max_length),
        boost::asio::buffer(buffer),
        boost::bind(
            &SocketSerialServerSession::handleRead,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void SocketSerialServerSession::handleRead(const boost::system::error_code& error, size_t amount)
{
	if (error) {
		delete this;
		return;
	}

	 // read from socket

	// write read data to opened serial device

	// read response from serial device

	// write back to socket serial device response wrapped as SocketSerialServerResponse struct
}

void SocketSerialServerSession::handleWrite(size_t amount, const boost::system::error_code& error)
{
	if (error) {
		delete this;
		return;
	}

    socket.async_read_some(
        boost::asio::buffer(data_, max_length),
        boost::bind(&session::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)
    );
}
*/