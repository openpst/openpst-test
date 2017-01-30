/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_open_response.h
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
        
        class StreamingDloadOpenResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadOpenResponse();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadOpenResponse();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
