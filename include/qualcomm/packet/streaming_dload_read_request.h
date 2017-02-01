/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_read_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_read_response.h"

using OpenPST::QC::StreamingDloadPacket;
using OpenPST::QC::StreamingDloadReadResponse;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadReadRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadReadRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadReadRequest();

                /**
                * @brief Get address
                * @return uint32_t
                */
                uint32_t getAddress();
                
                /**
                * @brief Set address
                * @param uint32_t address
                * @return void
                */
                void setAddress(uint32_t address);
                /**
                * @brief Get length
                * @return uint16_t
                */
                uint16_t getLength();
                
                /**
                * @brief Set length
                * @param uint16_t length
                * @return void
                */
                void setLength(uint16_t length);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

				/**
				* @overload Packet::prepareResponse
				*/
				void prepareResponse() override;

        };
    }
}
