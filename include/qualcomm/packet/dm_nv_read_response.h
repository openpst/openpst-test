/**
* LICENSE PLACEHOLDER
*
* @file dm_nv_read_response.h
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
        
        class DmNvReadResponse : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmNvReadResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~DmNvReadResponse();

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
                * @return uint8_t[]
                */
                std::vector<uint8_t> getData();
                /**
                * @brief Get data
                * @return std::string
                */
                std::string getData();
                
                /**
                * @brief Set data
                * @param uint8_t* data
                * @param size_t size
                * @return void
                */
                void setData(uint8_t* data, size_t size);
                /**
                * @brief Set data
                * @param const std::string& data
                * @return void
                */
                void setData(const std::string& data);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
