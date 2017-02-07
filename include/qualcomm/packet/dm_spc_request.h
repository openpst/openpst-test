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
#include "qualcomm/packet/dm_spc_response.h"

using OpenPST::QC::DmPacket;
using OpenPST::QC::DmSpcResponse;

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
                * @brief Set spc
                * @param uint8_t* spc
                * @param size_t size
                * @return void
                */
                void setSpc(uint8_t* data, size_t size);
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
