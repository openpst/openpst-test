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