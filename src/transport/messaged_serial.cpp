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
* @file messaged_serial.cpp
* @package openpst/libopenpst
* @brief Read and write serial data. Read data are parsed messages based on control character(s).
*		Ideal for protocols like AT which end in \r\n or HDLC framed in 0x7E
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "transport/messaged_serial.h"
#ifdef SERIAL_DEBUG
#include "util/hexdump.h"
#include <iostream>
#endif

using namespace OpenPST::Transport;

MessagedSerial::MessagedSerial(
	const std::string& device,
	const std::string& messageEnd,
	unsigned int baud,
	int timeout,
	serial_port_base::parity parity,
	serial_port_base::character_size csize,
	serial_port_base::flow_control flow,
	serial_port_base::stop_bits stop
) : io(), port(io), timer(io), timeout(timeout)
{
	if (device.size() && messageEnd.size()) {
		open(device, messageEnd, baud, parity, csize, flow, stop);
	}
}

MessagedSerial::~MessagedSerial()
{
	if (isOpen()) {
		try {
			close();
		} catch(...) {}
	}
}

bool MessagedSerial::isOpen()
{
	return port.is_open();
}

void MessagedSerial::open(
	const std::string& device,
	const std::string& messageEnd,
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
	
	this->device 	 = device;
	this->messageEnd = messageEnd;
}

void MessagedSerial::close()
{
	if (port.is_open()) {
		port.cancel();
		port.close();
	}

	io.stop();
	io.reset();
}

size_t MessagedSerial::write(std::vector<uint8_t>& out)
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

size_t MessagedSerial::write(uint8_t* out, size_t amount)
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

size_t MessagedSerial::write(Packet* packet)
{
	return 0;
}

size_t MessagedSerial::read(std::vector<uint8_t>& in, size_t amount)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	if (!messages.size()) {
		doAsyncRead();

		timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
		timer.async_wait(boost::bind(&MessagedSerial::onTimeout, this, boost::asio::placeholders::error));

		timedOut = false;
		
		io.run();
		io.reset();
	}

	size_t ret = 0;

	if (messages.size()) {

		auto message = messages.front();

		ret = message.size();

		in.reserve(in.size() + ret);

		in.insert(in.end(), message.begin(), message.end());

		messages.erase(messages.begin());
	}

	return ret;
}

size_t MessagedSerial::read(uint8_t* in, size_t amount)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	if (!messages.size()) {
		doAsyncRead();

		timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
		timer.async_wait(boost::bind(&MessagedSerial::onTimeout, this, boost::asio::placeholders::error));

		timedOut = false;
		
		io.run();
		io.reset();
	}

	size_t ret = 0;

	if (messages.size()) {

		auto message = messages.front();

		if (messages.size() > amount) {
			throw SerialError("Destination buffer not large enough for response");
		}

		ret = message.size();

		std::copy(message.begin(), message.end(), in);

		messages.erase(messages.begin());
	}

	return ret;
}

size_t MessagedSerial::read(Packet* packet, size_t amount)
{
	return 0;
}

size_t MessagedSerial::available()
{
	return port.available();
}

void MessagedSerial::onReadComplete(const boost::system::error_code& error, size_t received)
{
	if (error && error != boost::asio::error::eof) {
		timer.cancel();
		if (error.value() == ECANCELED) {
			return;
		}
		throw SerialError(error.message());
	}

	if (received && received != messageEnd.size()) {

		std::vector<uint8_t> message;

		message.reserve(received);
		message.insert(
			message.begin(),
			boost::asio::buffers_begin(buffer.data()),
			boost::asio::buffers_begin(buffer.data()) + received
		);

		#ifdef SERIAL_DEBUG_RX
			std::cout << "Received " << received << " bytes" << std::endl;
			hexdump((uint8_t*)&message[0], message.size());
		#endif

		if (message.size() == messageEnd.size() && memcmp(&message[0], &messageEnd[0], messageEnd.size()) == 0) {
			buffer.consume(message.size());
			doAsyncRead();
			return;
		}

		// remove the messageEnd from the end of the string
		if (memcmp(&message[message.size() - messageEnd.size()], &messageEnd[0], messageEnd.size()) == 0) {
			message.erase(message.end() - messageEnd.size(), message.end());
		}

		messages.push_back(message);

		buffer.consume(received);
		
		// exit here unless we have more messages we can consume for users next read request
		if (!port.available()) {
			return; 
		}
	} else if (received == messageEnd.size()) {
		buffer.consume(buffer.size());
	}

	doAsyncRead();
}

void MessagedSerial::doAsyncRead()
{
	boost::asio::async_read_until(
		port,
		buffer,
		messageEnd,
		boost::bind(
			&MessagedSerial::onReadComplete, 
			this, 
			boost::asio::placeholders::error, 
			boost::asio::placeholders::bytes_transferred
		)
	);
}

void MessagedSerial::onTimeout(const boost::system::error_code& error)
{	
	timedOut = true;

	port.cancel();

	if (error && error.value() != ECANCELED) {
		throw SerialError(error.message());
	}
}

const std::string& MessagedSerial::getDevice()
{
	return device;
}

const std::string& MessagedSerial::getMessageEnd()
{
	return messageEnd;
}


const std::vector<std::vector<uint8_t>>& MessagedSerial::getMessages()
{
	return messages;
}


void MessagedSerial::setTimeout(int timeout)
{
	this->timeout = timeout;
}

int MessagedSerial::getTimeout()
{
	return timeout;
}
