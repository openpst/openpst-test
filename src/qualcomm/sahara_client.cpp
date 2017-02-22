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

const SaharaState& SaharaClient::getState()
{
	return state;
}

SaharaState SaharaClient::hello()
{
	SaharaHello hello = readHello();

	return sendHello(hello);
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

	state.version 	  = ret.version;
	state.minVersion  = ret.minVersion;
	state.initialMode = ret.mode;
	state.mode   	  = ret.mode;

	return ret;
}

SaharaState SaharaClient::sendHello(SaharaHello hello)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	SaharaHelloResponse response(deviceEndianess);

	response.setMode(hello.mode);
	response.setVersion(hello.version);
	response.setMinVersion(hello.minVersion);
	response.setStatus(0x00);

	transport.write(&response);

	state.version 	  = hello.version;
	state.minVersion  = hello.minVersion;
	state.initialMode = hello.mode;
	state.mode   	  = hello.mode;

	return ret;
}

void SaharaClient::switchMode(uint32_t mode)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	SaharaSwitchModeRequest request(deviceEndianess);

	request.setMode(mode);

	transport.write(&mode);
}

SaharaState SaharaClient::switchModeAndHello(uint32_t mode)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	SaharaState ret = {};


	return ret;
}

const SaharaHostInfo& SaharaClient::getHostInfo()
{
	if (hostInfo.requested) {
		return hostInfo;
	}

	//std::vector data;

	//data = sendClientCommand(kSaharaClientCmdSerialNumRead);

	//data = sendClientCommand(kSaharaClientCmdMsmHWIDRead);

	//data = sendClientCommand(kSaharaClientOemPkHashRead);

	//data = sendClientCommand(kSaharaClientCmdGetSblVersion);

	hostInfo.requested = true;

	return hostInfo;
}

std::vector<uint8_t> SaharaClient::sendClientCommand(uint32_t command)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	std::vector<uint8_t> ret;

	SaharaClientCommandRequest  request(deviceEndianess);

	request.setClientCommand(command);

	request.prepareResponse();

	transport.write(&request);

	auto response = reinterpret_cast<SaharaClientCommandResponse*>(request.getResponse());

	transport.read(response);

	size_t dataSize = response->getDataSize(); // amount of data to expect

	// ok let sahara know we are ready to receive data
	// SaharaClientCommandExecuteDataRequest execRequest(deviceEndianess);
	// transport.write(&request);

	// RawDataPacket execResponse;
	//transport.read(&requested, response->getDataSize());

	// ret.insert(ret.begin(), execResponse.getData().begin(), execResponse.getData().end());
	
	return ret;
}

SaharaImageRequestInfo SaharaClient::sendImage(const std::string& filePath, SaharaImageRequestInfo requestInfo)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	std::ifstream file(filePath.c_str(), std::ios::in | std::ios::binary);
	
	if (!file.is_open()) {
		throw SaharaClientError("Could Not Open File " + filePath);
	}

	file.seekg(0, file.end);

	size_t sent  = 0;
	size_t total = static_cast<size_t>(file.tellg());

	file.seekg(0, file.beg);

	RawDataPacket response(deviceEndianess);

	SaharaImageRequestInfo next = requestInfo;
	
	try {
		while(sent < total) {
			
			if (next.offset > total || (next.offset + next.size) > total) {
				file.close();
				throw SaharaClientError("Requested image offset and size exceed the total size of file " + filePath);
			}

			file.seekg(next.offset, file.end);

			response.setData(file, next.size);

			transport.write(&response);

			next = readNextImageOffset();
			
			if ((!next.offset && !next.size) || 
				requestInfo.imageId != next.imageId) {
				break;
			}
		}
	} catch (std::exception& e) {
		file.close();
		throw SaharaClientError(e.what());
	}

	file.close();

	std::cout << "Sent a total of " << sent << "/" << total << " bytes from " << filePath << std::endl;

	if (requestInfo.imageId != next.imageId) {
		std::cout << "Device is now requesting " << next.size << " bytes from image ";
		std::cout << next.imageId << " - " << getRequestedImageName(next.imageId) << std::endl;
	}

	return next;
}

SaharaImageRequestInfo SaharaClient::sendImage(std::ifstream& file, uint32_t offset, size_t size)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}



	return readNextImageOffset();
}

SaharaImageRequestInfo SaharaClient::readNextImageOffset()
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	} else if(!transport.available()) {
		throw SaharaClientError("No data waiting. Not requesting an image transfer.");
	}

	SaharaReadDataRequest request;

	transport.read(&request);

	state.lastImageRequest.imageId  = request.getImageId();
	state.lastImageRequest.offset 	= request.getOffset();
	state.lastImageRequest.size 	= request.getAmount();

	return state.lastImageRequest;
}

size_t SaharaClient::readMemory(uint32_t address, size_t size, std::vector<uint8_t>&out)
{
	return 0;
}

size_t SaharaClient::readMemory(uint32_t address, size_t size, const std::string& outFilePath)
{
	return 0;
}

size_t SaharaClient::readMemory(uint32_t address, size_t size, std::ofstream& out)
{
	return 0;
}

void SaharaClient::done()
{
	SaharaDoneRequest request(deviceEndianess);

	request.prepareResponse();

	transport.write(&request);

	transport.read(request.getResponse());

	state = {};
	hostInfo = {};
}

void SaharaClient::reset()
{
	SaharaResetRequest request(deviceEndianess);

	request.prepareResponse();

	transport.write(&request);

	transport.read(request.getResponse());

	state = {};
	hostInfo = {};
}

const std::string SaharaClient::getRequestedImageName(uint32_t imageId)
{
	switch (imageId) {
		case kMbnImageNone:          return "None";
		case kMbnImageOemSbl:        return "OEM SBL";
		case kMbnImageAmss:          return "AMSS";
		case kMbnImageOcbl:          return "QCSBL";
		case kMbnImageHash:          return "Hash";
		case kMbnImageAppbl:         return "APPSBL";
		case kMbnImageHostDl:        return "HOSTDL";
		case kMbnImageDsp1:          return "DSP1";
		case kMbnImageFsbl:          return "FSBL";
		case kMbnImageDbl:           return "DBL";
		case kMbnImageOsbl:          return "OSBL";
		case kMbnImageDsp2:          return "DSP2";
		case kMbnImageEhostdl:       return "EHOSTDL";
		case kMbnImageNandprg:       return "NANDPRG";
		case kMbnImageNorprg:        return "NORPRG";
		case kMbnImageRamfs1:        return "RAMFS1";
		case kMbnImageRamfs2:        return "RAMFS2";
		case kMbnImageAdspQ5:        return "ADSP Q5";
		case kMbnImageAppsKernel:    return "APPS Kernel";
		case kMbnImageBackupRamfs:   return "Backup RAMFS";
		case kMbnImageSbl1:          return "SBL1";
		case kMbnImageSbl2:          return "SBL2";
		case kMbnImageRpm:           return "RPM";
		case kMbnImageSbl3:          return "SBL3";
		case kMbnImageTz:            return "TZ";
		case kMbnImageSsdKeys:       return "SSD Keys";
		case kMbnImageGen:           return "GEN";
		case kMbnImageDsp3:          return "DSP3";
		case kMbnImageAcdb:          return "ACDB";
		case kMbnImageWdt:           return "WDT";
		case kMbnImageMba:           return "MBA";
		default:                     return "Unknown";
	}
}