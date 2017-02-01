/**
* LICENSE PLACEHOLDER
*
* @file dm_guid_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_packet.h"

using OpenPST::QC::DmPacket;

namespace OpenPST {
    namespace QC {
        
        class DmGuidRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmGuidRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~DmGuidRequest();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
