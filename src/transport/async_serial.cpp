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

#include "transport/async_serial.h"
#ifdef SERIAL_DEBUG
#include "util/hexdump.h"
#include <iostream>
#endif

using namespace OpenPST::Transport;

AsyncSerial::AsyncSerial(
	const std::string& device,
	unsigned int baud,
	int timeout,
	serial_port_base::parity parity,
	serial_port_base::character_size csize,
	serial_port_base::flow_control flow,
	serial_port_base::stop_bits stop
) : io(), port(io), timeout(timeout)
{
	if (device.size()) {
		open(device, baud, parity, csize, flow, stop);
	}
}

AsyncSerial::~AsyncSerial()
{
	if (isOpen()) {
		try {
			close();
		} catch(...) {}
	}
}

bool AsyncSerial::isOpen()
{
	return port.is_open();
}

void AsyncSerial::open(
	const std::string& device,
	unsigned int baud,
	serial_port_base::parity parity,
    serial_port_base::character_size csize,
    serial_port_base::flow_control flow,
    serial_port_base::stop_bits stop
)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (!device.size()) {
		throw AsyncSerialError("No device specified");
	}
	if (isOpen()) {
		close();
	}
	
	boost::system::error_code error;

	port.open(device.c_str(), error);

	if (error) {
		throw AsyncSerialError(error.message());
	}

	port.set_option(serial_port_base::baud_rate(baud));
	port.set_option(parity);
	port.set_option(csize);
	port.set_option(flow);
	port.set_option(stop);
	
	this->device = device;

    io.post(boost::bind(&AsyncSerial::doAsyncRead, this));

    boost::thread thread(boost::bind(&AsyncSerial::doWork, this));

    worker.swap(thread);
}

void AsyncSerial::close()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

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

size_t AsyncSerial::write(std::vector<uint8_t>& out)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (!isOpen()) {
		throw AsyncSerialError("Not open");
	}

	boost::lock_guard<boost::mutex> lock(writeLock);

	std::vector<uint8_t> writeData;
	
	writeData.reserve(out.size());

	writeQueue.push(writeData);

	writeQueue.front().insert(writeQueue.front().begin(), out.begin(), out.end());

	//std::copy(out.begin(), out.end(), .begin());
	
	io.post(boost::bind(&AsyncSerial::doAsyncWrite, this));

	return out.size();
}

size_t AsyncSerial::write(uint8_t* out, size_t amount)
{
	return 0;
}

size_t AsyncSerial::write(Packet* packet)
{
	return 0;
}

size_t AsyncSerial::read(std::vector<uint8_t>& in, size_t amount)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	io_service io_; // create a new io service, since our main one is running in another thread
	deadline_timer timer(io_);

	timedOut = false;

	timer.expires_from_now(boost::posix_time::milliseconds(getTimeout()));
    timer.async_wait(boost::bind(&AsyncSerial::onTimeout, this, boost::asio::placeholders::error));

	while(!timedOut) {
		io_.run_one();
		boost::lock_guard<boost::mutex> lock(readLock);

		if (rxbuff.size()) {
			if (amount > rxbuff.size()) {
				amount = rxbuff.size();
			}

			in.insert(in.end(), rxbuff.begin(), rxbuff.begin() + amount);
			rxbuff.erase(rxbuff.begin(), rxbuff.begin() + amount);
		}
	}

	return timedOut ? 0 : amount;
}

size_t AsyncSerial::read(uint8_t* in, size_t amount)
{
	return 0;
}

size_t AsyncSerial::read(Packet* packet, size_t amount)
{
	return 0;
}

size_t AsyncSerial::available()
{
	return port.available();
}

void AsyncSerial::doAsyncRead()
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;

	port.async_read_some(
		//boost::asio::buffer(&rxbuff[rxbuff.size()], 1024), 
		boost::asio::null_buffers(),
		boost::bind(
			&AsyncSerial::onReadComplete, 
			this, 
			boost::asio::placeholders::error, 
			boost::asio::placeholders::bytes_transferred
		)
	);
}

void AsyncSerial::onReadComplete(const boost::system::error_code& error, size_t received)
{
	std::cout << __PRETTY_FUNCTION__ << " " << received <<  " " << port.available() << std::endl;

	if (error && error != boost::asio::error::eof) {
		if (error.value() == ECANCELED) {
			return;
		}
		throw AsyncSerialError(error.message());
	} else if(!isOpen()) {
		throw AsyncSerialError("Port closed");
	}

	boost::lock_guard<boost::mutex> lock(readLock);

	size_t currentlyAvailable = port.available();
	off_t start = rxbuff.size();

	rxbuff.reserve(rxbuff.size() + currentlyAvailable);
	rxbuff.insert(rxbuff.end(), currentlyAvailable, 0x00);

	size_t read = port.read_some(boost::asio::buffer(&rxbuff[start], currentlyAvailable));

	std::cout << "DUMPING " << rxbuff.size() << " " << read << std::endl;

	hexdump((uint8_t*)&rxbuff[0], rxbuff.size());

	doAsyncRead();
}

void AsyncSerial::doAsyncWrite()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (!writeQueue.size()) {
		return;
	}

	boost::lock_guard<boost::mutex> lock(writeLock);

	boost::asio::async_write(
		port,
		boost::asio::buffer(writeQueue.front(), writeQueue.front().size()),
        boost::bind(
        	&AsyncSerial::onWriteComplete, 
			this,
			boost::asio::placeholders::error, 
			boost::asio::placeholders::bytes_transferred
        )
    );	
}

void AsyncSerial::onWriteComplete(const boost::system::error_code& error, size_t written)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (error) {
		std::cout << __FUNCTION__ << " " << error.message() << std::endl;
		throw AsyncSerialError(error.message());
	}
	
	boost::lock_guard<boost::mutex> lock(writeLock);

	if (writeQueue.size()) {
		std::cout << "Wrote " << writeQueue.front().size() << std::endl;
		hexdump((uint8_t*)&writeQueue.front()[0], writeQueue.front().size());
		writeQueue.pop();
	}

	
}

void AsyncSerial::doWork()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	
	boost::this_thread::at_thread_exit(
		boost::bind(&AsyncSerial::onWorkComplete, this)
	);
	try {
		io.run();	
	} catch(AsyncSerialError& e) {
		std::cout << __FUNCTION__ << " - " << e.what() << std::endl;
	}
}

void AsyncSerial::onTimeout(const boost::system::error_code& error)
{	
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	std::cout << "Read Timeout" << std::endl;

	timedOut = true;

	if (error && error.value() != ECANCELED) {
		throw AsyncSerialError(error.message());
	}
}

void AsyncSerial::onWorkComplete()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

const std::string& AsyncSerial::getDevice()
{
	return this->device;
}


void AsyncSerial::setTimeout(int timeout)
{
	this->timeout = timeout;
}

int AsyncSerial::getTimeout()
{
	return timeout;
}

