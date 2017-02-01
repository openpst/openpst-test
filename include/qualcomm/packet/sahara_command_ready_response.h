/**
* LICENSE PLACEHOLDER
*
* @file sahara_command_ready_response.h
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
        
        class SaharaCommandReadyResponse : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaCommandReadyResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~SaharaCommandReadyResponse();

                /**
                * @brief Get image_tx_status
                * @return uint32_t
                */
                uint32_t getImageTxStatus();
                
                /**
                * @brief Set image_tx_status
                * @param uint32_t imageTxStatus
                * @return void
                */
                void setImageTxStatus(uint32_t imageTxStatus);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
