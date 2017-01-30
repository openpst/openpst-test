/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_query_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::QC::DmEfsPacket;

namespace OpenPST {
    namespace QC {
        
        class DmEfsQueryRequest : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsQueryRequest();
                
                /**
                * @brief Destructor
                */
                ~DmEfsQueryRequest();

				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
