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

#include "server/tcp_serial_server.h"

using namespace OpenPST::Server;

TcpSerialServer::TcpSerialServer(Serial& port) :
    io(),
    acceptor(io),
    port(port)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

}

TcpSerialServer::~TcpSerialServer()
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

}

void TcpSerialServer::start(const std::string hostname, int port)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    
    boost::system::error_code error;

    boost::asio::ip::tcp::resolver resolver(io);

    boost::asio::ip::tcp::resolver::iterator endpoint_iter;
    
    endpoint_iter = resolver.resolve(boost::asio::ip::tcp::resolver::query(hostname, std::to_string(port)));
    

    endpoint = endpoint_iter->endpoint();


    std::cout << "Binding With " << endpoint << " - " << std::endl;

    acceptor = boost::asio::ip::tcp::acceptor(io, endpoint);
    
    //acceptor.open(endpoint.protocol());
    //acceptor.bind(endpoint, error);

    if (error) {
        throw TcpSerialServerError(error.message());
    }

    accept();

    std::cout << "Server Running on " << endpoint << " with " << this->port.getDevice() << std::endl;

    io.run();
}

void TcpSerialServer::start(int port)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    boost::system::error_code error;

    endpoint = boost::asio::ip::tcp::endpoint(
        boost::asio::ip::tcp::v4(), 
        port
    );

    std::cout << "Binding With " << endpoint << std::endl;

    acceptor.open(endpoint.protocol());
    acceptor.bind(endpoint, error);

    if (error) {
        throw TcpSerialServerError(error.message());
    }

    accept();

    std::cout << "Server Running on " << endpoint << " with " << this->port.getDevice() << std::endl;

    io.run();
}

void TcpSerialServer::stop()
{
    io.stop();
}

void TcpSerialServer::accept()
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    
    TcpSerialServerSession* session = new TcpSerialServerSession(io, port);

    acceptor.async_accept(
        session->getSocket(),
        boost::bind(&TcpSerialServer::onAccept, 
        this, 
        session,
        boost::asio::placeholders::error
    ));
}

void TcpSerialServer::onAccept(TcpSerialServerSession* session, const boost::system::error_code& error)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (error) {
        delete session;
        throw TcpSerialServerError(error.message());
    } else {
        std::cout << "New Session!" << std::endl;
        session->start();
    }

    accept();
}


TcpSerialServerSession::TcpSerialServerSession(boost::asio::io_service& io, Serial& port) : 
    socket(io), port(port)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
}

TcpSerialServerSession::~TcpSerialServerSession()
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
}

boost::asio::ip::tcp::socket& TcpSerialServerSession::getSocket()
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

    return socket;
}

void TcpSerialServerSession::start()
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

    socket.async_read_some(
        boost::asio::buffer(rxbuffer, 1024),
        boost::bind(
            &TcpSerialServerSession::onReceive,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void TcpSerialServerSession::onReceive(const boost::system::error_code& error, size_t received)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (error) {
        delete this;
        return;
    }
    
    // read from socket

    // write read data to opened serial device

    // read response from serial device

    // write back to socket serial device response wrapped as TcpSerialServerResponse struct
    boost::asio::async_write(
        socket,
        boost::asio::buffer(txbuffer, txbuffer.size()),
        boost::bind(
            &TcpSerialServerSession::onSend, 
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void TcpSerialServerSession::onSend(const boost::system::error_code& error, size_t sent)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (error) {
        delete this;
        return;
    }

    socket.async_read_some(
        boost::asio::buffer(rxbuffer, 1024),
        boost::bind(
            &TcpSerialServerSession::onReceive, 
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}