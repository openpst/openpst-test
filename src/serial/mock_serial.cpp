#pragma once

#include "serial/mock_serial.h"
#include "util/hexdump.h"

MockSerial::MockSerial(const std::string& port, int baudrate, int timeout)
{

}

MockSerial::~MockSerial() {

}

bool MockSerial::isOpen() {
	return true;
}

void MockSerial::open() 
{
	return;
}

size_t MockSerial::available()
{
	return resp.size();
}


void MockSerial::setMockResponse(std::vector<uint8_t>& data)
{
	resp.erase();
	resp.reserve(data.size());
	resp.insert(resp.begin(), data.begin(), data.end());
}

size_t MockSerial::write(std::vector<uint8_t>& data)
{
	return data.size();
}

size_t MockSerial::read(std::vector<uint8_t>& data, size_t amount)
{
	data.insert(data.end(), resp.begin(), resp.begin() + amount);
	resp.erase();
	return amount;
}