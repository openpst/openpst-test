/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_set_ecc_state_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_set_ecc_state_response.h"

using OpenPST::QC::StreamingDloadPacket;
using OpenPST::QC::StreamingDloadSetEccStateResponse;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadSetEccStateRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadSetEccStateRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadSetEccStateRequest();

                /**
                * @brief Get status
                * @return uint8_t
                */
                uint8_t getStatus();
                
                /**
                * @brief Set status
                * @param uint8_t status
                * @return void
                */
                void setStatus(uint8_t status);
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
