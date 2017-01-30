/**
* LICENSE PLACEHOLDER
*
* @file sahara_done_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/sahara_packet.h"
#include "qualcomm/packet/sahara_done_response.h"

using OpenPST::QC::SaharaPacket;
using OpenPST::QC::SaharaDoneResponse;

namespace OpenPST {
    namespace QC {
        
        class SaharaDoneRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaDoneRequest();
                
                /**
                * @brief Destructor
                */
                ~SaharaDoneRequest();

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
