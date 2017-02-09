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

#include "server/remote_socket_serial_server.h"

using namespace OpenPST::Server;

/**
* RemoteSocketSerialServer
*/
RemoteSocketSerialServer::RemoteSocketSerialServer(int port, const std::string& device, int baudRate, int timeout) : 
	acceptor(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),,
	serial(device, baudRate, timeout)
{

}

RemoteSocketSerialServer::~RemoteSocketSerialServer()
{

}

void RemoteSocketSerialServer::start()
{
	RemoteSocketSerialServerSession* session = new RemoteSocketSerialServerSession(io);
	acceptor.async_accept(session->getSocket(), boost::bind(&RemoteSocketSerialServer::accept, this, session, boost::asio::placeholders::error));
}

void RemoteSocketSerialServer::accept(RemoteSocketSerialServerSession* session, const boost::system::error_code& error)
{
    if (!error) {
    	session->start();
    } else {
    	delete session;
    }

    accept();
}

/**
* RemoteSocketSerialServerSession
*/
RemoteSocketSerialServerSession::RemoteSocketSerialServerSession(boost::asio::io_service& io, Serial& serial) : socket(io), serial(serial)
{

}

RemoteSocketSerialServerSession::~RemoteSocketSerialServerSession()
{

}

boost::asio::ip::tcp::socket& RemoteSocketSerialServerSession::getSocket()
{
	return socket;
}

void RemoteSocketSerialServerSession::start()
{
    socket.async_read_some(
        //boost::asio::buffer(buffer, max_length),
        boost::asio::buffer(buffer),
        boost::bind(
            &RemoteSocketSerialServerSession::handleRead,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void RemoteSocketSerialServerSession::handleRead(const boost::system::error_code& error, size_t amount)
{
	if (error) {
		delete this;
		return;
	}

	 // read from socket

	// write read data to opened serial device

	// read response from serial device

	// write back to socket serial device response wrapped as RemoteSocketSerialServerResponse struct
}

void RemoteSocketSerialServerSession::handleWrite(size_t amount, const boost::system::error_code& error)
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