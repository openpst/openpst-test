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

void SaharaClient::setTransport(TransportInterface& transport)
{
	this->transport = transport;
}

const SaharaState& SaharaClient::getState()
{
	return state;
}

const SaharaState& SaharaClient::hello()
{
	SaharaHello hello = readHello();

	return sendHello(hello);
}


SaharaHello SaharaClient::readHello()
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	SaharaHello ret = {};
	SaharaHelloRequest request(deviceEndianess);

	try {
		transport.read(&request);
	} catch(std::exception& e) {
		std::stringstream ss;
		ss << "Error reading hello: " << e.what();
		throw SaharaClientError(ss.str());
	}

	if (request.getCommand() != kSaharaCommandHello) {
		throw SaharaClientError("Received an unexpected response");
	}

	#ifdef SAHARA_CLIENT_DEBUG
		std::cout << "Received Hello. Device in mode " << getModeName(request.getMode()) << std::endl;
	#endif

	ret.mode 	    = request.getMode();
	ret.version 	= request.getVersion();
	ret.minVersion  = request.getMinVersion();
	ret.status 		= request.getStatus();

	state.version 	  = ret.version;
	state.minVersion  = ret.minVersion;	
	state.mode   	  = ret.mode;

	if (!state.establishedSession) {
		state.initialMode = ret.mode;
	}

	state.establishedSession = true;

	return ret;
}

const SaharaState& SaharaClient::sendHello(SaharaHello hello)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	#ifdef SAHARA_CLIENT_DEBUG
		std::cout << "Sending hello response requesting mode " << getModeName(hello.mode) << std::endl;
	#endif

	SaharaHelloResponse response(deviceEndianess);

	response.setMode(hello.mode);
	response.setVersion(hello.version);
	response.setMinVersion(hello.minVersion);
	response.setStatus(0x00);

	transport.write(&response);

	state.version 	  = hello.version;
	state.minVersion  = hello.minVersion;
	state.mode   	  = hello.mode;

	if (state.mode == kSaharaModeImageTxPending) {
		readNextImageOffset();
	} else if (state.mode == kSaharaModeCommand) {
		readCommandModeReady();
	} else if (state.mode == kSaharaModeMemoryDebug) {

	}

	return state;
}

void SaharaClient::switchMode(uint32_t mode)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	#ifdef SAHARA_CLIENT_DEBUG
		std::cout << "Attempting mode switch to " << getModeName(mode) << std::endl;
	#endif

	SaharaSwitchModeRequest request(deviceEndianess);

	request.setMode(mode);

	transport.write(&request);
}

const SaharaState& SaharaClient::switchModeAndHello(uint32_t mode)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	switchMode(mode);

	SaharaHello hello = readHello();

	return sendHello(hello);;
}

const SaharaHostInfo& SaharaClient::getHostInfo()
{
	if (hostInfo.requested) {
		return hostInfo;
	}

	sendClientCommand(kSaharaClientCmdSerialNumRead, reinterpret_cast<uint8_t*>(&hostInfo.serial), sizeof(hostInfo.serial));
	sendClientCommand(kSaharaClientCmdMsmHWIDRead, 	 reinterpret_cast<uint8_t*>(&hostInfo.hwId), sizeof(hostInfo.hwId));
	sendClientCommand(kSaharaClientCmdGetSblVersion, reinterpret_cast<uint8_t*>(&hostInfo.sblVersion), sizeof(hostInfo.sblVersion));
	sendClientCommand(kSaharaClientOemPkHashRead, 	 &hostInfo.oemPublicKeyHash[0], sizeof(hostInfo.oemPublicKeyHash));

	hostInfo.requested = true;

	return hostInfo;
}

std::vector<uint8_t> SaharaClient::sendClientCommand(uint32_t command)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	#ifdef SAHARA_CLIENT_DEBUG
		std::cout << "Requesting Client Command " << getClientCommandName(command) << std::endl;
	#endif

	SaharaClientCommandRequest  request(deviceEndianess);

	request.setClientCommand(command);

	request.prepareResponse();

	transport.write(&request);

	auto response = reinterpret_cast<SaharaClientCommandResponse*>(request.getResponse());

	transport.read(response);

	size_t dataSize = static_cast<size_t>(response->getDataSize()); // amount of data to expect

	// ok let sahara know we are ready to receive data
	SaharaClientCommandExecuteDataRequest execRequest(deviceEndianess);

	execRequest.setClientCommand(command);

	transport.write(&execRequest);

	// read the data
	std::vector<uint8_t> ret;

	ret.reserve(dataSize);

	transport.read(ret, SAHARA_MAX_PACKET_SIZE);

	return ret;
}

void SaharaClient::sendClientCommand(uint32_t command, uint8_t* in, size_t amount)
{
	auto data = sendClientCommand(command);

	std::copy(data.begin(), data.begin() + amount, in);
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

			#ifdef SAHARA_CLIENT_DEBUG
				std::cout << "Device is now requesting " << next.size << " bytes from image starting at offset " << next.offset << std::endl;
			#endif

			if (next.offset > total || (next.offset + next.size) > total) {
				file.close();
				throw SaharaClientError("Requested image offset and size exceed the total size of file " + filePath);
			}

			file.seekg(next.offset, file.beg);
			
			response.setData(file, next.size);

			transport.write(&response);

			sent += next.size;

			next = readNextImageOffset();
			
			if ((!next.offset && !next.size) || 
				requestInfo.imageId != next.imageId) {
				break;
			}
		}
	} catch (std::exception& e) {
		file.close();
		throw SaharaClientError(e.what());
	} catch (...) {
		file.close();
		throw;
	}

	file.close();

	#ifdef SAHARA_CLIENT_DEBUG
		std::cout << "Sent a total of " << sent << "/" << total << " bytes from " << filePath << std::endl;

		if (requestInfo.imageId != next.imageId) {
			std::cout << "Device is now requesting " << next.size << " bytes from image ";
			std::cout << next.imageId << " - " << getRequestedImageName(next.imageId) << std::endl;
		}
	#endif

	return next;
}

SaharaImageRequestInfo SaharaClient::sendImage(std::ifstream& file, uint32_t offset, size_t size)
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	return readNextImageOffset();
}

const SaharaImageRequestInfo& SaharaClient::readNextImageOffset()
{
	if (!transport.isOpen()) {
		throw SaharaClientError("Transport is not open");
	}

	SaharaReadDataRequest request;

	transport.read(&request);

	state.lastImageRequest.imageId  = request.getImageId();
	state.lastImageRequest.offset 	= request.getOffset();
	state.lastImageRequest.size 	= request.getAmount();

	return state.lastImageRequest;
}

bool SaharaClient::readCommandModeReady()
{
	SaharaCommandReadyResponse isReadyRequest(deviceEndianess);

	try {
		transport.read(&isReadyRequest);

		return true;

	} catch (...) {
		return false;
	}
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

const std::string SaharaClient::getModeName(uint32_t mode)
{
	switch (mode) {
		case kSaharaModeImageTxPending:  return "Image Transfer Pending";
		case kSaharaModeImageTxComplete: return "Image Transfer Complete";
		case kSaharaModeMemoryDebug:     return "Memory Debug";
		case kSaharaModeCommand:         return "Command Mode";
		default:                         return "Unknown";
	}
}

const std::string SaharaClient::getClientCommandName(uint32_t command)
{
	switch (command) {
		case kSaharaClientCmdNop:                       return "NOP";
		case kSaharaClientCmdSerialNumRead:             return "Read Serial Number";
		case kSaharaClientCmdMsmHWIDRead:               return "Read MSM HW ID";
		case kSaharaClientOemPkHashRead:                return "Read OEM PK Hash";
		case kSaharaClientCmdSwitchDMSS:                return "Switch To DMSS DLOAD";
		case kSaharaClientCmdSwitchToStreamingDload:    return "Switch To Streaming DLOAD";
		case kSaharaClientCmdReadDebugData:             return "Read Debug Data";
		case kSaharaClientCmdGetSblVersion:             return "Read SBL SW Version";
		default:                                        return "Unknown";
	}
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