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

size_t Serial::read(std::vector<uint8_t>& in, size_t amount)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	doAsyncRead();

	timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
    timer.async_wait(boost::bind(&Serial::onTimeout, this, boost::asio::placeholders::error));

    received = 0;
    timedOut = false;
    
    io.run();
    io.reset();

    if(received > amount) {
    	in.insert(in.end(), rxbuffer.begin(), rxbuffer.begin() + amount);
    	rxbuffer.erase(rxbuffer.begin(), rxbuffer.begin() + amount);
    	return amount;
    }
    
    in.insert(in.end(), rxbuffer.begin(), rxbuffer.begin() + received);
    rxbuffer.erase(rxbuffer.begin(), rxbuffer.begin() + received);
    return received;
}

size_t Serial::read(uint8_t* in, size_t amount)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	doAsyncRead();

	timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
    timer.async_wait(boost::bind(&Serial::onTimeout, this, boost::asio::placeholders::error));

    received = 0;
    timedOut = false;
    
    io.run();
    io.reset();

    if(received > amount) {
    	std::copy(rxbuffer.begin(), rxbuffer.begin() + amount, in);
    	rxbuffer.erase(rxbuffer.begin(), rxbuffer.begin() + amount);
    	return amount;
    }
    
    std::copy(rxbuffer.begin(), rxbuffer.begin() + received, in);
    rxbuffer.erase(rxbuffer.begin(), rxbuffer.begin() + received);
    return received;
}

size_t Serial::available()
{
	if (!isOpen()) {
		return 0;
	}

	boost::system::error_code error;
	#if defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
		COMSTAT status;
		if (::ClearCommError(port.native_handle(), NULL, &status)) {
			error = boost::system::error_code(
				::GetLastError(), 
				boost::asio::error::get_system_category()
			);
			throw SerialError(error.message());
		}
		return static_cast<size_t>(status.cbInQue);
	#else
		int amount = 0;
		if (::ioctl(port.native_handle(), FIONREAD, &amount)) {
			error = boost::system::error_code(errno, boost::asio::error::get_system_category());
			throw SerialError(error.message());
		}
		return static_cast<size_t>(amount);
	#endif
}


void Serial::onReadReady(const boost::system::error_code& error)
{
	if (error && error != boost::asio::error::eof) {
		timer.cancel();
		if (error.value() == ECANCELED) {
			return;
		}
		throw SerialError(error.message());
	}

	off_t  start = rxbuffer.size();
	size_t avail = available();

	if (avail) {	

		rxbuffer.insert(rxbuffer.end(), avail, 0);

		received += port.read_some(boost::asio::buffer(&rxbuffer[start], avail));
		
		if (received < avail) {
			rxbuffer.erase(rxbuffer.begin() + start + received, rxbuffer.end());
		}

		#ifdef SERIAL_DEBUG_RX
			std::cout << "Read " << received << " bytes" << std::endl;
			hexdump(&rxbuffer[start], received);
		#endif

		if (!available()) {
			timer.cancel();
			return;
		}
	}

	if (timedOut) {		
		timer.cancel();		
	} else {
		doAsyncRead();
	}	
}

void Serial::doAsyncRead()
{
	port.async_read_some(
		boost::asio::null_buffers(), 
		boost::bind(
			&Serial::onReadReady, 
			this, 
			boost::asio::placeholders::error
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
