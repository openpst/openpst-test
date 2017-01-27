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

using OpenPST::QC::SaharaPacket;

namespace OpenPST {
    namespace QC {
        
        class SaharaResetRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaResetRequest();
                
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
