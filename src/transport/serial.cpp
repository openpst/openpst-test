#include "transport/serial.h"
#ifdef SERIAL_DEBUG
#include "util/hexdump.h"
#include <iostream>
#endif

using namespace OpenPST::Transport;

/*Serial::Serial(const std::string& device, unsigned int baudRate, int timeout) : 
	device(device), baudRate(baudRate), timeout(timeout), 
	io(), port(io), timer(io)
{
	if (device.size()) {
		open(device, baud);
	}
}*/

Serial::Serial(
	const std::string& device,
	unsigned int baud,
	int timeout,
	serial_port_base::parity parity,
	serial_port_base::character_size csize,
	serial_port_base::flow_control flow,
	serial_port_base::stop_bits stop
) : io(), port(io), timer(io), timeout(timeout)
{
	if (device.size()) {
		open(device, baud, parity, csize, flow, stop);
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

void Serial::open(
	const std::string& device,
	unsigned int baud,
	serial_port_base::parity parity,
    serial_port_base::character_size csize,
    serial_port_base::flow_control flow,
    serial_port_base::stop_bits stop
)
{
	if (!device.size()) {
		throw SerialError("No device specified");
	}
	if (isOpen()) {
		close();
	}
	
	boost::system::error_code error;

	port.open(device.c_str(), error);

	if (error) {
		throw SerialError(error.message());
	}

	port.set_option(serial_port_base::baud_rate(baud));
	port.set_option(parity);
	port.set_option(csize);
	port.set_option(flow);
	port.set_option(stop);
	
	this->device = device;
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
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	error_code error;

	size_t ret = boost::asio::write(port, boost::asio::buffer(out), boost::asio::transfer_all(), error);

	if (error) {
		throw SerialError(error.message());
	}

#ifdef SERIAL_DEBUG_TX
	std::cout << "Wrote " << ret << " bytes" << std::endl;
	hexdump(reinterpret_cast<uint8_t*>(&out[0]), ret);
#endif

	return ret;
}

size_t Serial::read(std::vector<uint8_t>& in, size_t amount)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	rxbuff.empty();
	rxbuff.reserve(amount);

	doAsyncRead(amount);

	timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
    timer.async_wait(boost::bind(&Serial::onTimeout, this, boost::asio::placeholders::error));

    received = 0;
    timedOut = false;

    io.run();

    io.reset();

#ifdef SERIAL_DEBUG_RX
	std::cout << "Read " << received << " bytes" << std::endl;
	hexdump(&rxbuff[0], received);
#endif

	if (received) {
		in.insert(in.end(), rxbuff.begin(), rxbuff.begin() + received);
	}

    return in.size();
}

void Serial::onReadComplete(const boost::system::error_code& error, size_t received, size_t requested)
{
	if (error && error != boost::asio::error::eof) {
		timer.cancel();
		throw SerialError(error.message());
	}

	if (received || timedOut) {
		this->received = received;
		timer.cancel();
		return;
	}

	doAsyncRead(requested);
}

void Serial::doAsyncRead(size_t amount)
{
	port.async_read_some( 
		boost::asio::buffer(&rxbuff[0], amount), 
		boost::bind(
			&Serial::onReadComplete, 
			this, 
			boost::asio::placeholders::error, 
			boost::asio::placeholders::bytes_transferred,
			amount
		)
	);
}

void Serial::onTimeout(const boost::system::error_code& error)
{	
	port.cancel();

	timedOut = true;

	if (error && error.value() != ECANCELED) {
		throw SerialError(error.message());
	}
}

const std::string& Serial::getDevice()
{
	return this->device;
}


void Serial::setTimeout(int timeout)
{
	this->timeout = timeout;
}

int Serial::getTimeout()
{
	return timeout;
}
