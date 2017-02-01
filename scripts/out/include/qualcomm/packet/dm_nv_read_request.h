/**
* LICENSE PLACEHOLDER
*
* @file dm_nv_read_request.h
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
        
        class DmNvReadRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmNvReadRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~DmNvReadRequest();

                /**
                * @brief Get nv_item
                * @return uint16_t
                */
                uint16_t getNvItem();
                
                /**
                * @brief Set nv_item
                * @param uint16_t nvItem
                * @return void
                */
                void setNvItem(uint16_t nvItem);
                /**
                * @brief Get data
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getData();
                
                /**
                * @brief Set data
                * @param uint8_t* data
                * @param size_t size
                * @return void
                */
                void setData(uint8_t* data, size_t size);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
