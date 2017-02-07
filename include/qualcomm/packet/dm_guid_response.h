/**
* LICENSE PLACEHOLDER
*
* @file dm_guid_response.h
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
        
        class DmGuidResponse : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmGuidResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmGuidResponse();

                /**
                * @brief Get guid
                * @return uint8_t[]
                */
                std::vector<uint8_t> getGuid();
                /**
                * @brief Get guid
                * @return std::string
                */
                std::string getGuid();
                
                /**
                * @brief Set guid
                * @param uint8_t* guid
                * @param size_t size
                * @return void
                */
                void setGuid(uint8_t* data, size_t size);
                /**
                * @brief Set guid
                * @param const std::string& guid
                * @return void
                */
                void setGuid(const std::string& guid);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
