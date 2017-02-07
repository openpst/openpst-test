/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_close_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_close_response.h"

using OpenPST::QC::StreamingDloadPacket;
using OpenPST::QC::StreamingDloadCloseResponse;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadCloseRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadCloseRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadCloseRequest();

                /**
                * @brief Get mode
                * @return uint8_t
                */
                uint8_t getMode();
                
                /**
                * @brief Set mode
                * @param uint8_t mode
                * @return void
                */
                void setMode(uint8_t mode);
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
