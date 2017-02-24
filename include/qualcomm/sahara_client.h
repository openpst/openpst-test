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

#pragma once

#include "definitions.h"
#include "transport/transport_interface.h"
#include "transport/packet.h"
#include "transport/packet/raw_data_packet.h"
#include "qualcomm/sahara.h"
#include "qualcomm/sahara_packets.h"
#include "qualcomm/mbn.h"

using OpenPST::Transport::RawDataPacket;

namespace OpenPST {
	namespace Qualcomm {

		struct SaharaState {
			uint32_t version;
			uint32_t minVersion;
			uint32_t initialMode;
			uint32_t mode;
			SaharaImageRequestInfo lastImageRequest;
		};

		struct SaharaImageRequestInfo {
			uint32_t imageId;
			uint32_t offset;
			uint32_t size;
		};

		struct SaharaHello {
			uint32_t mode;
			uint32_t version;
			uint32_t minVersion;
			uint32_t status;
		};

		struct SaharaHostInfo {			
			bool  			    requested;
			uint32_t  			serial;
			uint32_t 			sblVersion;
			SaharaMsmHwId		hwId;
			uint8_t 			oemPublicKeyHash[32];
		};

		class SaharaClient {
			protected:
				TransportInterface& transport;
				PacketEndianess deviceEndianess;
				SaharaState state = {};
				SaharaHostInfo hostInfo = {};

			public:
				SaharaClient(TransportInterface& transport, PacketEndianess deviceEndianess = kPacketEndianessLittle);

				~SaharaClient();

				TransportInterface* getTransport();

				void setTransport(TransportInterface& transport);

				const SaharaState& getState();

				SaharaState hello();

				SaharaHello readHello();

				SaharaState sendHello(SaharaHello resp);

				void switchMode(uint32_t mode);

				SaharaState switchModeAndHello(uint32_t mode);

				const SaharaHostInfo& getHostInfo();

				std::vector<uint8_t> sendClientCommand(uint32_t command);

				SaharaImageRequestInfo sendImage(const std::string& filePath, SaharaImageRequestInfo requestInfo);

				SaharaImageRequestInfo sendImage(std::ifstream& file, uint32_t offset, size_t size);

				SaharaImageRequestInfo readNextImageOffset();

				size_t readMemory(uint32_t address, size_t size, std::vector<uint8_t>& out);

				size_t readMemory(uint32_t address, size_t size, const std::string& outFilePath);

				size_t readMemory(uint32_t address, size_t size, std::ofstream& out);

				void done();

				void reset();

				const std::string getRequestedImageName(uint32_t imageId);
		};

		class SaharaClientError : public std::exception
		{
			const SaharaClientError& operator=(SaharaClientError);
			std::string _what;
			uint8_t code;
			
			public:
				SaharaClientError(std::string message, uint8_t code = 0) : _what(message), code(code)  {}
				SaharaClientError(const SaharaClientError& second) : _what(second._what), code(second.code) {}
				virtual ~SaharaClientError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}

				uint32_t getCode()
				{
					return code;
				}

		};
	}
}