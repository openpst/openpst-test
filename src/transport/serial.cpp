#include "transport/serial.h"
#ifdef SERIAL_DEBUG
#include "util/hexdump.h"
#include <iostream>
#endif

using namespace OpenPST::Transport;

Serial::Serial(const std::string& device, int baudRate, int timeout) : 
	device(device), baudRate(baudRate), timeout(timeout), 
	port(io), timer(io)
{
	if (device.size()) {
		open();
	}
}

Serial::~Serial()
{
	if (isOpen()) {
		close();
	}
}

bool Serial::isOpen()
{
	return port.is_open();
}

void Serial::open()
{
	if (isOpen()) {
		return;
	}
	
	boost::system::error_code error;

	if (device.size()) {

		port.open(device.c_str(), error);

		if (error) {
			throw SerialError(error.message());
		}

		port.set_option(boost::asio::serial_port_base::baud_rate(baudRate));
		//port.set_option(boost::asio::serial_port_base::character_size(8));
		//port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
		//port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
		//port.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
	}
}

void Serial::close()
{
	if (port.is_open()) {
		port.cancel();
		port.close();
	}

	io.stop();
	io.reset();
}

size_t Serial::write(std::vector<uint8_t>& out)
{
	size_t ret = 0;
	boost::system::error_code error;

	ret = boost::asio::write(port, boost::asio::buffer(out), boost::asio::transfer_all(), error);

	if (error) {
		throw SerialError(error.message());
	}

	return ret;
}

size_t Serial::read(std::vector<uint8_t>& in, size_t amount)
{
	uint8_t* test = new uint8_t[amount];

	port.async_read_some(
		boost::asio::buffer(test, amount), 
		boost::bind(
			&Serial::onReadComplete, 
			this, 
			boost::asio::placeholders::error, 
			boost::asio::placeholders::bytes_transferred,
			amount
		)
	);
	
	timer.expires_from_now(boost::posix_time::seconds(getTimeout()));
    timer.async_wait(
    	boost::bind(
        	&Serial::onTimeout, 
        	this
        )
    );

    io.run();

    delete[] test;
}

void Serial::onReadComplete(const boost::system::error_code& error, size_t received, size_t expected)
{
#ifdef SERIAL_DEBUG
	std::cout << __FUNCTION__ << " Read " << received << std::endl;
#endif

	if (error || !received) {
#ifdef SERIAL_DEBUG
		std::cout << __FUNCTION__ << " Error! " << std::endl;
#endif
		return;
		//lastError = error;
	} else if (received == 0) {

	}

	timer.cancel();
}

void Serial::onWriteComplete(const boost::system::error_code& error, size_t written, size_t expected)
{

}

void Serial::onTimeout()
{
	std::cout << "TIMED OUT" << std::endl;
	port.cancel();
}

void Serial::setDevice(const std::string& device)
{
	if (isOpen()) {
		close();
	}

	this->device = device;
}

const std::string& Serial::getDevice()
{
	return this->device;
}

void Serial::setBaudRate(int baudRate)
{
	this->baudRate = baudRate;
	
	if (isOpen()) {
		port.set_option(boost::asio::serial_port_base::baud_rate(baudRate));
	}
}

int Serial::getBaudRate()
{
	return this->baudRate;
}

void Serial::setTimeout(int timeout)
{
	this->timeout = timeout;
}

int Serial::getTimeout()
{
	return this->timeout;
}
