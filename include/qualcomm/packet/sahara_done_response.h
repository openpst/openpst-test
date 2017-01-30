/**
* LICENSE PLACEHOLDER
*
* @file sahara_done_response.h
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
        
        class SaharaDoneResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaDoneResponse();
                
                /**
                * @brief Destructor
                */
                ~SaharaDoneResponse();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
