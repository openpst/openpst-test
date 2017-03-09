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

#include "qualcomm/streaming_dload_client.h"

using namespace OpenPST::Qualcomm;

StreamingDloadClient::StreamingDloadClient(MessagedTransportInterface& transport, const StreamingDloadFlashInfo& flashInfo, PacketEndianess deviceEndianess) :
	transport(transport), packetTransporter(transport), deviceEndianess(deviceEndianess)
{
	this->flashInfo.sectorSize = flashInfo.sectorSize;
	this->flashInfo.maxSectors = flashInfo.maxSectors;
}

StreamingDloadClient::StreamingDloadClient(MessagedTransportInterface& transport, PacketEndianess deviceEndianess) :
	transport(transport), packetTransporter(transport), deviceEndianess(deviceEndianess)
{
	this->flashInfo.sectorSize = 512;
	this->flashInfo.maxSectors = 0;
}

StreamingDloadClient::~StreamingDloadClient()
{

}

MessagedTransportInterface* StreamingDloadClient::getTransport()
{
	return &transport;
}

void StreamingDloadClient::setTransport(MessagedTransportInterface& transport)
{
	this->transport = transport;
	packetTransporter.setTransport(transport);
}

StreamingDloadDeviceInfo StreamingDloadClient::hello(const std::string& magic, uint8_t version, uint8_t compatibleVersion, uint8_t featureBits)
{
	StreamingDloadDeviceInfo ret = {};

	StreamingDloadHelloRequest request;

	request.setMagic(magic);
	request.setVersion(version);
	request.setCompatibleVersion(compatibleVersion);
	request.setFeatureBits(featureBits);

	writeAndReadEncoded(&request);

	auto response = reinterpret_cast<StreamingDloadHelloResponse*>(request.getResponse());

	ret.version 				= response->getVersion();
	ret.compatibleVersion 		= response->getCompatibleVersion();
	ret.maxPreferredBlockSize 	= response->getPreferredBlockSize();
	ret.baseFlashAddress 		= response->getBaseFlashAddress();
	ret.windowSize 			 	= response->getWindowSize();
	ret.featureBits 			= response->getFeatureBits();
	ret.flashId 				= response->getFlashId();

	return ret;
}

bool StreamingDloadClient::unlock(uint64_t code)
{
	return true;
}

bool StreamingDloadClient::setSecurityMode(StreamingDloadSecurityMode mode)
{
	StreamingDloadSecurityModeRequest request;

	request.setMode(mode);

	writeAndReadEncoded(&request);
}

void StreamingDloadClient::nop(uint32_t identifier)
{
	StreamingDloadNopRequest request;

	request.prepareResponse();

	request.setIdentifier(identifier);

	writeAndReadEncoded(&request);

	auto response = reinterpret_cast<StreamingDloadNopResponse*>(request.getResponse());

	if (response != nullptr && response->getIdentifier() != request.getIdentifier()) {
		std::cout << "NOP Response Identifier differes from request";
	}
}

void StreamingDloadClient::reset()
{
	StreamingDloadResetRequest request;
	writeAndReadEncoded(&request);
}

void StreamingDloadClient::powerOff()
{
	StreamingDloadPowerOffRequest request;
	writeAndReadEncoded(&request);
}

uint8_t StreamingDloadClient::getEcc()
{
	StreamingDloadGetEccStateRequest request;
	writeAndReadEncoded(&request);
	return 0;
}

bool StreamingDloadClient::setEcc(uint8_t status)
{
	StreamingDloadSetEccStateRequest request;
	request.setStatus(status);
	writeAndReadEncoded(&request);
	return true;
}

bool StreamingDloadClient::openMode(StreamingDloadOpenMode mode)
{
	StreamingDloadOpenRequest request;
	request.setMode(mode);
	writeAndReadEncoded(&request);
	return true;
}

bool StreamingDloadClient::closeMode()
{
	StreamingDloadCloseRequest request;
	writeAndReadEncoded(&request);
	return true;
}

bool StreamingDloadClient::openMultiImage(StreamingDloadOpenMultiMode imageType)
{
	StreamingDloadOpenMultiImageRequest request;
	request.setType(imageType);
	writeAndReadEncoded(&request);
	return true;
}

size_t StreamingDloadClient::readFlash(uint32_t lba, size_t amount, std::vector<uint8_t> &out)
{
	return 0;
}

size_t StreamingDloadClient::readFlash(uint32_t lba, size_t amount, std::ofstream& out)
{
	return 0;
}

uint8_t StreamingDloadClient::writePartitionTable(const std::string& filePath, bool overwrite)
{
	return 0;
}

size_t StreamingDloadClient::writeFlash(uint32_t lba, std::ifstream& file, size_t amount)
{
	return 0;
}

size_t StreamingDloadClient::writeFlash(uint32_t lba, std::vector<uint8_t>& data)
{
	return 0;
}

size_t StreamingDloadClient::writeFlash(uint32_t lba, uint8_t* data, size_t amount)
{
	return 0;
}

void StreamingDloadClient::eraseFlash()
{
	StreamingDloadEraseFlashRequest request;
	writeAndReadEncoded(&request);
}

void StreamingDloadClient::setSectorSize(size_t size)
{
	flashInfo.sectorSize = size;
}

size_t StreamingDloadClient::getSectorSize()
{
	return flashInfo.sectorSize;
}

void StreamingDloadClient::setMaxDiskSectors(size_t maxDiskSectors)
{
	flashInfo.maxSectors = maxDiskSectors;
}

size_t StreamingDloadClient::getMaxDiskSectors()
{
	return flashInfo.maxSectors;
}

size_t StreamingDloadClient::readEncoded(std::vector<uint8_t>& data, size_t amount)
{
	std::vector<uint8_t> tmp;

	tmp.reserve(amount);

	transport.read(tmp, amount);

	encoder.decode(tmp);

	return tmp.size();
}

size_t StreamingDloadClient::readEncoded(uint8_t* data, size_t amount)
{
	std::vector<uint8_t> tmp;

	tmp.reserve(amount);

	size_t amountRead = transport.read(tmp, amount);

	encoder.decode(tmp);

	if (tmp.size() > amountRead) {

	}

	std::copy(tmp.begin(), tmp.begin() + amountRead, data);

	return amountRead;
}

size_t StreamingDloadClient::writeEncoded(const std::vector<uint8_t>& data)
{
	if (!data.size()) {
		return 0;
	}

	std::vector<uint8_t> tmp = data;

	encoder.encode(tmp);

	return transport.write(tmp);
}

size_t StreamingDloadClient::writeEncoded(uint8_t* data, size_t amount)
{
	if (!amount) {
		return 0;
	}

	std::vector<uint8_t> tmp;

	tmp.reserve(amount);

	tmp.insert(tmp.begin(), data, data + amount);

	encoder.encode(tmp);

	return transport.write(tmp);
}

size_t StreamingDloadClient::readEncoded(Packet* packet)
{
	std::vector<uint8_t> tmp;

	tmp.reserve(packet->getMaxDataSize());

	transport.read(tmp, packet->getMaxDataSize());

	encoder.decode(tmp);

	packet->unpack(tmp, &transport);

	return packet->size();
}

size_t StreamingDloadClient::writeEncoded(Packet* packet)
{
	if (!packet->size()) {
		return 0;
	}

	std::vector<uint8_t> tmp = packet->getData();

	encoder.encode(tmp);

	return transport.write(tmp);
}


void StreamingDloadClient::writeAndReadEncoded(Packet* packet)
{
	if (!transport.isOpen()) {
		throw StreamingDloadClientError("Transport not open");
	}

	packet->prepare();

	writeEncoded(packet);

	if (packet->isResponseExpected()) {
		
		packet->prepareResponse();

		if (packet->getResponse() == nullptr) {
			throw StreamingDloadClientError("Response packet has not been allocated");
		}

		readEncoded(packet->getResponse());
	}
}
