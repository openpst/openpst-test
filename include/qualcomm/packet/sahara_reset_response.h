/**
* LICENSE PLACEHOLDER
*
* @file sahara_reset_response.h
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
        
        class SaharaResetResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaResetResponse();
                
                /**
                * @brief Destructor
                */
                ~SaharaResetResponse();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
