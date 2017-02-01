/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_power_off_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadPowerOffResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadPowerOffResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadPowerOffResponse();

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
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
