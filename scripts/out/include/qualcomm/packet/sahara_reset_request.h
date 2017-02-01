/**
* LICENSE PLACEHOLDER
*
* @file sahara_reset_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/sahara_packet.h"
#include "qualcomm/packet/sahara_reset_response.h"

using OpenPST::QC::SaharaPacket;
using OpenPST::QC::SaharaResetResponse;

namespace OpenPST {
    namespace QC {
        
        class SaharaResetRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaResetRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~SaharaResetRequest();

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
