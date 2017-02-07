/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_erase_flash_response.h
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
        
        class StreamingDloadEraseFlashResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadEraseFlashResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadEraseFlashResponse();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
