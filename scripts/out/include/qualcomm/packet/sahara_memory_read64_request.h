/**
* LICENSE PLACEHOLDER
*
* @file sahara_memory_read64_request.h
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
        
        class SaharaMemoryRead64Request : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaMemoryRead64Request(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~SaharaMemoryRead64Request();

                /**
                * @brief Get address
                * @return uint64_t
                */
                uint64_t getAddress();
                
                /**
                * @brief Set address
                * @param uint64_t address
                * @return void
                */
                void setAddress(uint64_t address);
                /**
                * @brief Get size
                * @return uint64_t
                */
                uint64_t getSize();
                
                /**
                * @brief Set size
                * @param uint64_t size
                * @return void
                */
                void setSize(uint64_t size);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
