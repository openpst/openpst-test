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

StreamingDloadClient::StreamingDloadClient(TransportInterface& transport, const StreamingDloadFlashInfo& flashInfo, PacketEndianess deviceEndianess) :
	transport(transport), packetTransporter(transport), deviceEndianess(deviceEndianess)
{
	this->flashInfo.sectorSize = flashInfo.sectorSize;
	this->flashInfo.maxSectors = flashInfo.maxSectors;
}

StreamingDloadClient::StreamingDloadClient(TransportInterface& transport, PacketEndianess deviceEndianess) :
	transport(transport), packetTransporter(transport), deviceEndianess(deviceEndianess)
{
	this->flashInfo.sectorSize = 512;
	this->flashInfo.maxSectors = 0;
}

StreamingDloadClient::~StreamingDloadClient()
{

}

TransportInterface* StreamingDloadClient::getTransport()
{
	return &transport;
}

void StreamingDloadClient::setTransport(TransportInterface& transport)
{
	this->transport = transport;
	packetTransporter.setTransport(transport);
}

StreamingDloadDeviceInfo StreamingDloadClient::hello(std::string magic, uint8_t version, uint8_t compatibleVersion, uint8_t featureBits)
{
	StreamingDloadDeviceInfo ret = {};

	StreamingDloadHelloRequest request;

	request.prepareResponse();
	
	transport.write(&request);
	
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
	return true;
}

void StreamingDloadClient::nop()
{
	StreamingDloadNopRequest request;

	request.prepareResponse();

	request.setIdentifier(10);

	transport.write(&request);

	auto response = reinterpret_cast<StreamingDloadNopResponse*>(request.getResponse());

	transport.read(response);

	if (response->getIdentifier() != request.getIdentifier()) {

	}
}

void StreamingDloadClient::reset()
{
	StreamingDloadResetRequest request;

	request.prepareResponse();

	transport.write(&request);

	auto response = reinterpret_cast<StreamingDloadResetResponse*>(request.getResponse());

	transport.read(response);
}

void StreamingDloadClient::powerOff()
{

}

uint8_t StreamingDloadClient::getEcc()
{
	return 0;
}

bool StreamingDloadClient::setEcc(uint8_t status)
{
	return true;
}

bool StreamingDloadClient::openMode(StreamingDloadOpenMode mode)
{
	return true;
}

bool StreamingDloadClient::closeMode()
{
	return true;
}

bool StreamingDloadClient::openMultiImage(StreamingDloadOpenMultiMode imageType)
{
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

uint8_t StreamingDloadClient::writePartitionTable(std::string filePath, bool overwrite)
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

}

void StreamingDloadClient::setSectorSize(size_t size)
{

}

size_t StreamingDloadClient::getSectorSize()
{
	return 0;
}

void StreamingDloadClient::setMaxDiskSectors(size_t maxDiskSector)
{

}

size_t StreamingDloadClient::getMaxDiskSectors()
{
	return 0;
}

size_t StreamingDloadClient::readEncoded(const std::vector<uint8_t>& data)
{
	return 0;
}

size_t StreamingDloadClient::readEncoded(uint8_t* data, size_t amount)
{
	return 0;
}

size_t StreamingDloadClient::writeEncoded(const std::vector<uint8_t>& data)
{
	return 0;
}

size_t StreamingDloadClient::writeEncoded(uint8_t* data, size_t amount)
{
	return 0;
}

size_t StreamingDloadClient::readEncoded(Packet* packet)
{
	return 0;
}

size_t StreamingDloadClient::writeEncoded(Packet* packet)
{
	return 0;
}
