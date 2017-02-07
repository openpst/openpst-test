#include "transport/serial.h"

using namespace OpenPST::Transport;


Serial::Serial(const std::string& device, int baudRate, int timeout) : 
	device(device), baudRate(baudRate), timeout(timeout), port(io)
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

	if (device.size()) {

		port.open(device.c_str(), lastError);

		if (lastError) {
			throw SerialError(lastError.message());
		}

		port.set_option(boost::asio::serial_port_base::baud_rate(baudRate));
		port.set_option(boost::asio::serial_port_base::character_size(8));
		port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
		port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
		port.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));
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

	ret = boost::asio::write(port, boost::asio::buffer(out), boost::asio::transfer_all(), lastError);

	if (lastError) {
		throw SerialError(lastError.message());
	}

	return ret;
}

size_t Serial::read(std::vector<uint8_t>& in, size_t amount)
{
	size_t ret = 0;

	ret = boost::asio::read(port, boost::asio::buffer(in, amount), boost::asio::transfer_all(), lastError);

	if (lastError) {
		throw SerialError(lastError.message());
	}

	return ret;
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
