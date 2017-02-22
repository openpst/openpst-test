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

#include "transport/messaged_async_serial.h"
#ifdef SERIAL_DEBUG
#include "util/hexdump.h"
#include <iostream>
#endif

using namespace OpenPST::Transport;

MessagedAsyncSerial::MessagedAsyncSerial(
	const std::string& device,
	const std::string& messageEnd,
	unsigned int baud,
	int timeout,
	serial_port_base::parity parity,
	serial_port_base::character_size csize,
	serial_port_base::flow_control flow,
	serial_port_base::stop_bits stop
) : io(), port(io), timeout(timeout)
{
	if (device.size() && messageEnd.size()) {
		open(device, messageEnd, baud, parity, csize, flow, stop);
	}
}

MessagedAsyncSerial::~MessagedAsyncSerial()
{
	if (isOpen()) {
		try {
			close();
		} catch(...) {}
	}
}

bool MessagedAsyncSerial::isOpen()
{
	return port.is_open();
}

void MessagedAsyncSerial::open(
	const std::string& device,
	const std::string& messageEnd,
	unsigned int baud,
	serial_port_base::parity parity,
    serial_port_base::character_size csize,
    serial_port_base::flow_control flow,
    serial_port_base::stop_bits stop
)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (!device.size()) {
		throw SerialError("No device specified");
	} else if(!messageEnd.size()) {
		throw SerialError("No end of message specified");
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

    io.post(boost::bind(&MessagedAsyncSerial::doAsyncRead, this));

    boost::thread thread(boost::bind(&MessagedAsyncSerial::doWork, this));

    worker.swap(thread);
}

void MessagedAsyncSerial::close()
{
	if (port.is_open()) {
		port.cancel();
		port.close();
	}

	io.stop();
	io.reset();

	if (boost::this_thread::get_id() != worker.get_id()) {
		worker.join();
	}
}

size_t MessagedAsyncSerial::write(std::vector<uint8_t>& out)
{
	if (!isOpen()) {
		throw SerialError("Not open");
	}

	boost::lock_guard<boost::mutex> lock(writeLock);

	std::vector<uint8_t> writeData;
	
	writeData.reserve(out.size());

	writeQueue.push(writeData);

	writeQueue.front().insert(writeQueue.front().begin(), out.begin(), out.end());
	
	io.post(boost::bind(&MessagedAsyncSerial::doAsyncWrite, this));

	return out.size();
}

size_t MessagedAsyncSerial::write(uint8_t* out, size_t amount)
{
	return 0;
}

size_t MessagedAsyncSerial::write(Packet* packet)
{
	return 0;
}

size_t MessagedAsyncSerial::read(std::vector<uint8_t>& in, size_t amount)
{

	io_service io_; // create a new io service, since our main one is running in another thread
	deadline_timer timer(io_);

	timedOut = false;

	timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
    timer.async_wait(boost::bind(&MessagedAsyncSerial::onTimeout, this, boost::asio::placeholders::error));

	while(!timedOut) {
		io_.run_one();
		boost::lock_guard<boost::mutex> lock(readLock);

		/*if (messages.size()) {
			if (amount > rxbuff.size()) {
				amount = rxbuff.size();
			}

			in.insert(in.end(), rxbuff.begin(), rxbuff.begin() + amount);
			rxbuff.erase(rxbuff.begin(), rxbuff.begin() + amount);
		}*/
	}

	return timedOut ? 0 : amount;
}

size_t MessagedAsyncSerial::read(uint8_t* in, size_t amount)
{
	return 0;
}

size_t MessagedAsyncSerial::read(Packet* packet, size_t amount)
{
	return 0;
}

size_t MessagedAsyncSerial::available()
{
	return port.available();
}

void MessagedAsyncSerial::doAsyncRead()
{
	boost::asio::async_read_until(
		port,
		buffer,
		messageEnd,
		boost::bind(
			&MessagedAsyncSerial::onReadComplete, 
			this, 
			boost::asio::placeholders::error, 
			boost::asio::placeholders::bytes_transferred
		)
	);
}

void MessagedAsyncSerial::onReadComplete(const boost::system::error_code& error, size_t received)
{
	if (error && error != boost::asio::error::eof) {
		if (error.value() == ECANCELED) {
			return;
		}
		throw SerialError(error.message());
	} else if(!isOpen()) {
		throw SerialError("Port closed");
	}

	if (received) {
		std::vector<uint8_t> message(
			boost::asio::buffers_begin(buffer.data()), 
			boost::asio::buffers_begin(buffer.data()) + received
		);

		if (message.size() == messageEnd.size() && memcmp(&message[0], &messageEnd[0], messageEnd.size()) == 0) {
			buffer.consume(message.size());
			doAsyncRead();
			return;
		}

		// remove the messageEnd from the end of the string
		if (memcmp(&message[message.size() - messageEnd.size()], &messageEnd[0], messageEnd.size()) == 0) {
			message.erase(message.end() - messageEnd.size(), message.end());
		}

		std::cout << "DUMPING " << buffer.size() << " " << received << " " << message.size()  << std::endl;
		hexdump((uint8_t*)&message[0], message.size());

		buffer.consume(received);

		messages.push_back(message);
	}

	doAsyncRead();
}

void MessagedAsyncSerial::doAsyncWrite()
{
	if (!writeQueue.size()) {
		return;
	}

	boost::lock_guard<boost::mutex> lock(writeLock);

	boost::asio::async_write(
		port,
		boost::asio::buffer(writeQueue.front(), writeQueue.front().size()),
        boost::bind(
        	&MessagedAsyncSerial::onWriteComplete, 
			this,
			boost::asio::placeholders::error, 
			boost::asio::placeholders::bytes_transferred
        )
    );	
}

void MessagedAsyncSerial::onWriteComplete(const boost::system::error_code& error, size_t written)
{
	if (error) {
		std::cout << __FUNCTION__ << " " << error.message() << std::endl;
		throw SerialError(error.message());
	}
	
	boost::lock_guard<boost::mutex> lock(writeLock);

	if (writeQueue.size()) {
		std::cout << "Wrote " << writeQueue.front().size() << std::endl;
		hexdump((uint8_t*)&writeQueue.front()[0], writeQueue.front().size());
		writeQueue.pop();
	}

	
}

void MessagedAsyncSerial::doWork()
{
	boost::this_thread::at_thread_exit(
		boost::bind(&MessagedAsyncSerial::onWorkComplete, this)
	);
	try {
		io.run();	
	} catch(SerialError& e) {
		std::cout << __FUNCTION__ << " - " << e.what() << std::endl;
	}
}

void MessagedAsyncSerial::onTimeout(const boost::system::error_code& error)
{	
	std::cout << "Read Timeout" << std::endl;

	timedOut = true;

	if (error && error.value() != ECANCELED) {
		throw SerialError(error.message());
	}
}

void MessagedAsyncSerial::onWorkComplete()
{

}

const std::string& MessagedAsyncSerial::getDevice()
{
	return this->device;
}

const std::string& MessagedAsyncSerial::getMessageEnd()
{
	return this->messageEnd;
}

void MessagedAsyncSerial::setTimeout(int timeout)
{
	this->timeout = timeout;
}

int MessagedAsyncSerial::getTimeout()
{
	return timeout;
}

