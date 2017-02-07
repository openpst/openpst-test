#include "transport/serial.h"

using namespace OpenPST::Transport;

Socket::Socket(const std::string& host, int port) : 
	host(host), port(port), socket(io)
{

}

Socket::~Socket()
{

}

void Socket::connect()
{

}

void Socket::disconnect()
{

}

size_t Socket::write(std::vector<uint8_t>& out)
{
	return 0;
}

size_t Socket::read(std::vector<uint8_t>& in, size_t amount)
{
	return 0;
}

void Socket::setHost(const std::string& host)
{
	this->host = host;
}

const std::string& Socket::getHost()
{
	return this->host;
}

void Socket::setPort(int port)
{
	this->port = port;
}

int Socket::getPort()
{
	return this->port;
}
