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

#include "transport/serial.h"
#ifdef SERIAL_DEBUG
#include "util/hexdump.h"
#include <iostream>
#endif

using namespace OpenPST::Transport;

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
		try {
			close();
		} catch(...) {}
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

	size_t ret = boost::asio::write(
		port, 
		boost::asio::buffer(out), 
		boost::asio::transfer_all(), 
		error
	);

	if (error) {
		throw SerialError(error.message());
	}

#ifdef SERIAL_DEBUG_TX
	std::cout << "Wrote " << ret << " bytes" << std::endl;
	hexdump(reinterpret_cast<uint8_t*>(&out[0]), ret);
#endif

	return ret;
}

size_t Serial::write(uint8_t* out, size_t amount)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	error_code error;

	size_t ret = boost::asio::write(
		port, 
		boost::asio::buffer(out, amount), 
		boost::asio::transfer_all(), 
		error
	);

	if (error) {
		throw SerialError(error.message());
	}

#ifdef SERIAL_DEBUG_TX
	std::cout << "Wrote " << ret << " bytes" << std::endl;
	hexdump(out, ret);
#endif

	return ret;
}

size_t Serial::write(Packet* packet)
{
	packet->prepare();

	return write(packet->getData());
}

size_t Serial::read(std::vector<uint8_t>& in, size_t amount)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	doAsyncRead(amount);

	timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
	timer.async_wait(boost::bind(&Serial::onTimeout, this, boost::asio::placeholders::error));

	received = 0;
	timedOut = false;
	
	io.run();
	io.reset();

	size_t ret = (received > 0 && received > amount) ? amount : received;

	if (ret) {
		in.reserve(in.size() + ret);
		in.insert(
			in.end(), 
			buffer.begin(), 
			buffer.begin() + ret
		);
		buffer.erase(buffer.begin(), buffer.begin() + ret);
	}

	return ret;
}

size_t Serial::read(uint8_t* in, size_t amount)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	doAsyncRead(amount);

	timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
	timer.async_wait(boost::bind(&Serial::onTimeout, this, boost::asio::placeholders::error));

	received = 0;
	timedOut = false;
	
	io.run();
	io.reset();

	size_t ret = (received > 0 && received > amount) ? amount : received;

	if (ret) {		
		std::copy(
			buffer.begin(), 
			buffer.begin() + ret,
			in
		);
		buffer.erase(buffer.begin(), buffer.begin() + ret);
	}

	return ret;
}

size_t Serial::read(Packet* packet, size_t amount)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	#ifdef SERIAL_DEBUG_RX
		std::cout << "Reading into Packet. Reading at max " << packet->getMaxDataSize() << " (Override: " << amount << ") bytes" << std::endl;
	#endif

	std::vector<uint8_t> rbuffer;

	if (amount > 0) {
		read(rbuffer, amount);
	} else {
		read(rbuffer, packet->getMaxDataSize());
	}

	packet->unpack(rbuffer, this);
	
	return packet->size();
}

size_t Serial::available()
{
	return port.available();
}

void Serial::onReadReady(const boost::system::error_code& error, size_t requested)
{
	if (error && error != boost::asio::error::eof) {
		timer.cancel();
		if (error.value() == ECANCELED) {
			return;
		}
		throw SerialError(error.message());
	}

	size_t available = port.available();
	
	if (available) {	
		size_t toRead = available > requested ? requested : available;
		size_t start  = buffer.size();


		buffer.reserve(buffer.size() + toRead);
		buffer.insert(buffer.end(), toRead, 0);

		received += port.read_some(boost::asio::buffer(&buffer[start], toRead));
		
		if (received < toRead) {
			buffer.erase(buffer.begin() + start + received, buffer.end());
		}

		#ifdef SERIAL_DEBUG_RX
			std::cout << "Read " << received << " of " << available << " bytes" << std::endl;
			hexdump(&buffer[start], received);
		#endif

		if (!port.available()) {
			timer.cancel();
			return;
		}
	}

	if (timedOut) {		
		return;	
	}
	
	doAsyncRead(requested);
}

void Serial::doAsyncRead(size_t amount)
{
	#ifdef SERIAL_DEBUG_RX
		std::cout << "doAsyncRead " << amount << " bytes" << std::endl;
	#endif
		
	port.async_read_some(
		boost::asio::null_buffers(),
		boost::bind(
			&Serial::onReadReady, 
			this, 
			boost::asio::placeholders::error,
			amount
		)
	);
}

void Serial::onTimeout(const boost::system::error_code& error)
{	
	timedOut = true;

	port.cancel();

	if (error && error.value() != ECANCELED) {
		throw SerialError(error.message());
	}
}

const std::string& Serial::getDevice()
{
	return device;
}

void Serial::setTimeout(int timeout)
{
	this->timeout = timeout;
}

int Serial::getTimeout()
{
	return timeout;
}
