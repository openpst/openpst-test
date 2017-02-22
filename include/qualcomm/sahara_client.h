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
#include "qualcomm/sahara.h"
#include "qualcomm/sahara_packets.h"

namespace OpenPST {
	namespace Qualcomm {

		struct SaharaState {
			uint32_t version;
			uint32_t minVersion;
			uint32_t mode;
		};

		struct SaharaReadDataInfo {
			uint32_t imageId;
			uint32_t offset;
			uint32_t amount;
		};

		struct SaharaHello {
			uint32_t mode;
			uint32_t version;
			uint32_t minVersion;
			uint32_t status;
		};

		class SaharaClient {
			protected:
				TransportInterface& transport;
				PacketEndianess deviceEndianess;
			public:
				SaharaClient(TransportInterface& transport, PacketEndianess deviceEndianess = kPacketEndianessLittle);

				~SaharaClient();

				TransportInterface* getTransport();

				SaharaHello readHello();

				SaharaState sendHello(SaharaHello resp);

				void switchMode(uint32_t mode);

				SaharaState switchModeAndHello(uint32_t mode);

				std::vector<uint8_t> sendClientCommand(uint32_t command);

				SaharaReadDataInfo sendImage(std::string filePath, SaharaReadDataInfo initialReadRequest);

				SaharaReadDataInfo sendImage(std::ifstream& file, uint32_t offset, size_t size);

				SaharaReadDataInfo readNextImageOffset();

				size_t readMemory(uint32_t address, size_t size, std::vector<uint8_t>&out);

				size_t readMemory(uint32_t address, size_t size, std::string outFilePath);

				size_t readMemory(uint32_t address, size_t size, std::ofstream& out);

				void done();

				void reset();

		};

		class SaharaClientError : public std::exception
		{
			const SaharaClientError& operator=(SaharaClientError);
			std::string _what;
			uint8_t code;
			
			public:
				SaharaClientError(std::string message, uint8_t code = 0) : _what(message), code(code)  { }
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