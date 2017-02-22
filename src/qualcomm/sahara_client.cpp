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
* @package libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/sahara_client.h"

using namespace OpenPST::Qualcomm;

SaharaClient::SaharaClient(TransportInterface& transport, PacketEndianess deviceEndianess) :
	transport(transport), deviceEndianess(deviceEndianess)
{

}

SaharaClient::~SaharaClient()
{

}

TransportInterface* SaharaClient::getTransport()
{
	return &transport;
}

SaharaHello SaharaClient::readHello()
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	} else if(!transport.available()) {
		throw SaharaClientError("No data waiting. Not in sahara mode or device requires restart.");
	}

	SaharaHello ret = {};
	SaharaHelloRequest request(deviceEndianess);

	transport.read(&request);

	if (request.getCommand() != kSaharaCommandHello) {
		throw SaharaClientError("Received an unexpected response");
	}

	ret.mode 	    = request.getMode();
	ret.version 	= request.getVersion();
	ret.minVersion  = request.getMinVersion();
	ret.status 		= request.getStatus();

	return ret;
}

SaharaState SaharaClient::sendHello(SaharaHello hello)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	SaharaState ret = {};
	SaharaHelloResponse response(deviceEndianess);

	response.setMode(hello.mode);
	response.setVersion(hello.version);
	response.setMinVersion(hello.minVersion);
	response.setStatus(0x00);

	transport.write(&response);

	ret.version 	= hello.version;
	ret.minVersion  = hello.minVersion;
	ret.mode   		= hello.mode;

	return ret;
}

void SaharaClient::switchMode(uint32_t mode)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}
}

SaharaState SaharaClient::switchModeAndHello(uint32_t mode)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	SaharaState ret = {};


	return ret;
}

std::vector<uint8_t> SaharaClient::sendClientCommand(uint32_t command)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	std::vector<uint8_t> ret;

	return ret;
}

SaharaReadDataInfo SaharaClient::sendImage(std::string filePath, SaharaReadDataInfo initialReadRequest)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	SaharaReadDataInfo ret = {};

	return ret;
}

SaharaReadDataInfo SaharaClient::sendImage(std::ifstream& file, uint32_t offset, size_t size)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	SaharaReadDataInfo ret = {};

	return ret;
}

SaharaReadDataInfo SaharaClient::readNextImageOffset()
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	} else if(!transport.available()) {
		throw SaharaClientError("No data waiting. Not requesting an image transfer.");
	}

	SaharaReadDataInfo ret = {};
	SaharaReadDataRequest request;

	transport.read(&request);

	ret.imageId = request.getImageId();
	ret.offset 	= request.getOffset();
	ret.amount 	= request.getAmount();

	return ret;
}

size_t SaharaClient::readMemory(uint32_t address, size_t size, std::vector<uint8_t>&out)
{
	return 0;
}

size_t SaharaClient::readMemory(uint32_t address, size_t size, std::string outFilePath)
{
	return 0;
}

size_t SaharaClient::readMemory(uint32_t address, size_t size, std::ofstream& out)
{
	return 0;
}

void SaharaClient::done()
{

}

void SaharaClient::reset()
{
	SaharaResetRequest request;

	request.prepareResponse();

	transport.write(&request);

	transport.read(request.getResponse());
}