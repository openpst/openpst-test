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
#include "transport/packet_transporter.h"
#include "qualcomm/streaming_dload.h"
#include "qualcomm/streaming_dload_packets.h"

namespace OpenPST {
	namespace Qualcomm {
		
		struct StreamingDloadState {
			bool    negotiated    = false;
			uint8_t openMode 	  = 0x00;
			uint8_t openMultiMode = 0x00;
		};

		struct StreamingDloadDeviceInfo {
			uint8_t  	version;
			uint8_t  	compatibleVersion;
			uint32_t 	maxPreferredBlockSize;
			uint32_t 	baseFlashAddress;
			uint16_t 	windowSize;
			uint8_t  	featureBits;
			std::string flashId;
		};

		struct StreamingDloadFlashInfo {
			size_t sectorSize;
			size_t maxSectors;
		};

		class StreamingDloadClient {
			protected:
				TransportInterface& transport;
				PacketTransporter packetTransporter;
				StreamingDloadFlashInfo flashInfo;
				PacketEndianess deviceEndianess;

			public:
				StreamingDloadClient(TransportInterface& transport, const StreamingDloadFlashInfo& flashInfo, PacketEndianess deviceEndianess = kPacketEndianessLittle);

				StreamingDloadClient(TransportInterface& transport, PacketEndianess deviceEndianess = kPacketEndianessLittle);

				~StreamingDloadClient();

				TransportInterface* getTransport();
				
				void setTransport(TransportInterface& transport);

				StreamingDloadDeviceInfo hello(std::string magic = "QCOM fast download protocol host", uint8_t version = 0x05, uint8_t compatibleVersion = 0x02, uint8_t featureBits = STREAMING_DLOAD_FEATURE_ALL);

				bool unlock(uint64_t code);

				bool setSecurityMode(StreamingDloadSecurityMode mode);

				void nop();

				void reset();

				void powerOff();

				uint8_t getEcc();

				bool setEcc(uint8_t status);

				bool openMode(StreamingDloadOpenMode mode);

				bool closeMode();

				bool openMultiImage(StreamingDloadOpenMultiMode imageType);

				size_t readFlash(uint32_t lba, size_t amount, std::vector<uint8_t> &out);

				size_t readFlash(uint32_t lba, size_t amount, std::ofstream& out);

				uint8_t writePartitionTable(std::string filePath, bool overwrite = false);

				size_t writeFlash(uint32_t lba, std::ifstream& file, size_t amount);

				size_t writeFlash(uint32_t lba, std::vector<uint8_t>& data);

				size_t writeFlash(uint32_t lba, uint8_t* data, size_t amount);

				void eraseFlash();

				void setSectorSize(size_t size);

				size_t getSectorSize();

				void setMaxDiskSectors(size_t maxDiskSector);

				size_t getMaxDiskSectors();

				size_t readEncoded(const std::vector<uint8_t>& data);

				size_t readEncoded(uint8_t* data, size_t amount);
				
				size_t readEncoded(Packet* packet);

				size_t writeEncoded(const std::vector<uint8_t>& data);

				size_t writeEncoded(uint8_t* data, size_t amount);

				size_t writeEncoded(Packet* packet);
		};

		class StreamingDloadClientError : public std::exception
		{
			const StreamingDloadClientError& operator=(StreamingDloadClientError);
			std::string _what;
			uint8_t code;
			public:
				StreamingDloadClientError(std::string message, uint8_t code = 0) : _what(message), code(code)  { }
				StreamingDloadClientError(const StreamingDloadClientError& second) : _what(second._what), code(second.code) {}
				virtual ~StreamingDloadClientError() throw() {}
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