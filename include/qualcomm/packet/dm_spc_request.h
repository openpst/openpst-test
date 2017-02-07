/**
* LICENSE PLACEHOLDER
*
* @file dm_spc_request.h
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
        
        class DmSpcRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmSpcRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmSpcRequest();

                /**
                * @brief Get spc
                * @return uint8_t[]
                */
                std::vector<uint8_t> getSpc();
                /**
                * @brief Get spc
                * @return std::string
                */
                std::string getSpc();
                
                /**
                * @brief Set spc
                * @param uint8_t* spc
                * @param size_t size
                * @return void
                */
                void setSpc(uint8_t* data, size_t size);
                /**
                * @brief Set spc
                * @param const std::string& spc
                * @return void
                */
                void setSpc(const std::string& spc);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
