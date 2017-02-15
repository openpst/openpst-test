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

#include "transport/tcp.h"

using namespace OpenPST::Transport;

Tcp::Tcp() : 
	io(), socket(io), timer(io), heartbeat(io), idle(true)
{

}

Tcp::Tcp(const std::string& host, int port, int timeout) : 
	io(), socket(io), timer(io), heartbeat(io), idle(true)
{
	connect(host, port, timeout);
}

Tcp::~Tcp()
{	
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	io.stop();
	if (thread) {
		thread->join();
	}
}

void Tcp::connect(const std::string& host, int port, int timeout)
{	
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (socket.is_open() || !idle || thread) {
		return;
	}

	boost::asio::ip::tcp::resolver resolver(io);

	boost::asio::ip::tcp::resolver::iterator endpoint_iter;
	
	endpoint_iter = resolver.resolve(boost::asio::ip::tcp::resolver::query(host, std::to_string(port)));

    endpoint = endpoint_iter->endpoint();

    timer.expires_from_now(boost::posix_time::seconds(timeout));
    timer.async_wait(boost::bind(&Tcp::onConnectionTimeout, this));

	socket.async_connect(
		endpoint,
        boost::bind(
        	&Tcp::onConnect,
            this, 
            boost::asio::placeholders::error
        )
    );

    idle  = false;

	std::cout << "Connecting to " << endpoint << std::endl;

	io.run();
}

bool Tcp::connected()
{	
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return socket.is_open();
}

void Tcp::disconnect()
{	
	stop();
	if (thread && boost::this_thread::get_id() != thread->get_id()) {
		thread->join();
		thread.reset();
	}
}

bool Tcp::isOpen()
{
	return connected();
}

void Tcp::close()
{
	disconnect();
}

void Tcp::start(const boost::asio::ip::tcp::endpoint& endpoint)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    timer.expires_from_now(boost::posix_time::seconds(10));
    timer.async_wait(boost::bind(&Tcp::onConnectionTimeout, this));

	socket.async_connect(
		endpoint,
        boost::bind(
        	&Tcp::onConnect,
            this, 
            boost::asio::placeholders::error
        )
    );

    idle  = false;

	std::cout << "Connecting to " << endpoint << std::endl;

    thread.reset(new boost::thread(
        boost::bind(&Tcp::doWork, this)
        //,
        //boost::bind(&Tcp::onWorkComplete, this)
    ));
	boost::this_thread::at_thread_exit(
		boost::bind(&Tcp::onWorkComplete, this)
	);
	
	//thread->join();
}

void Tcp::stop() 
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

    idle = true;
    boost::system::error_code ignored_ec;
    socket.close(ignored_ec);
    timer.cancel();
    heartbeat.cancel();
	io.stop();
	io.reset();

	/*boost::system::error_code ignored; // prevent exception
	socket.close(ignored);
	if (ignored) {
		std::cout << "stop() : " << ignored.message() << std::endl;
	}
	timer.cancel();
	heartbeat.cancel();
		*/
}

size_t Tcp::write(std::vector<uint8_t>& out)
{	
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return 0;
}

size_t Tcp::write(uint8_t* out, size_t amount)
{
	return 0;
}

size_t Tcp::write(Packet* packet)
{
	return 0;
}

size_t Tcp::read(std::vector<uint8_t>& in, size_t amount)
{	
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return 0;
}

size_t Tcp::read(uint8_t* in, size_t amount)
{
	return 0;
}

size_t Tcp::read(Packet* packet, size_t amount)
{
	return 0;
}

size_t Tcp::available()
{
	return socket.available();
}

void Tcp::asyncWrite()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Tcp::asyncRead()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    timer.expires_from_now(boost::posix_time::seconds(30));

    socket.async_read_some(
    	boost::asio::buffer(&rxbuffer[0], rxbuffer.size()), 
        boost::bind(
        	&Tcp::onReceive, 
        	this, 
        	boost::asio::placeholders::error
        )
   	);
}

void Tcp::onConnect(const boost::system::error_code& error)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (idle) {
		return;
	} else if (!socket.is_open()) {		
		throw TcpError("Connection timed out");
	} else if (error) {
		throw TcpError(error.message());
	}

	std::cout << "Connected to " << endpoint << std::endl;
	timer.cancel();
	io.stop();

    thread.reset(new boost::thread(
        boost::bind(&Tcp::doWork, this)
    ));
	
	/*boost::this_thread::at_thread_exit(
		boost::bind(&Tcp::onWorkComplete, this)
	);*/
	
	asyncRead();
}

void Tcp::onConnectionTimeout()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (idle) {
		return;
	}

	if (timer.expires_at() <= boost::asio::deadline_timer::traits_type::now()) {
		socket.close();
		timer.expires_at(boost::posix_time::pos_infin);
	}

	timer.async_wait(boost::bind(&Tcp::onConnectionTimeout, this));
}

void Tcp::onReceive(const boost::system::error_code& error)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (idle) {
		return;
	} else if (error) {
		std::cout << __PRETTY_FUNCTION__ << "\n" << error.message() << std::endl;		
		return;
	}

}

void Tcp::onSend(const boost::system::error_code& error)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (idle) {
		return;
	} else if (error) {
		std::cout << __PRETTY_FUNCTION__ << "\n" << error.message() << std::endl;
		stop();
	}

}

void Tcp::doWork()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	try {
		io.run();
	} catch(TcpError& e) {
		stop();
		thread->interrupt();
		std::cout << "E:: " << e.what() << std::endl;
		return;
	} catch(...) {
		stop();
		thread->interrupt();
		std::cout << "Unhandled Exception in " << std::endl;
		return;
	}
}


void Tcp::onWorkComplete()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "Work Complete" << std::endl;
	disconnect();
}
