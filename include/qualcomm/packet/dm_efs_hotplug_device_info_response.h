/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file dm_efs_hotplug_device_info_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::Qualcomm::DmEfsPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmEfsHotplugDeviceInfoResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsHotplugDeviceInfoResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmEfsHotplugDeviceInfoResponse();

                /**
                * @brief Get sequence
                * @return uint16_t
                */
                uint16_t getSequence();
                
                /**
                * @brief Set sequence
                * @param uint16_t sequence
                * @return void
                */
                void setSequence(uint16_t sequence);
                /**
                * @brief Get error
                * @return uint32_t
                */
                uint32_t getError();
                
                /**
                * @brief Set error
                * @param uint32_t error
                * @return void
                */
                void setError(uint32_t error);
                /**
                * @brief Get manufacturer_id
                * @return uint32_t
                */
                uint32_t getManufacturerId();
                
                /**
                * @brief Set manufacturer_id
                * @param uint32_t manufacturerId
                * @return void
                */
                void setManufacturerId(uint32_t manufacturerId);
                /**
                * @brief Get oem_id
                * @return uint32_t
                */
                uint32_t getOemId();
                
                /**
                * @brief Set oem_id
                * @param uint32_t oemId
                * @return void
                */
                void setOemId(uint32_t oemId);
                /**
                * @brief Get product_revision
                * @return uint32_t
                */
                uint32_t getProductRevision();
                
                /**
                * @brief Set product_revision
                * @param uint32_t productRevision
                * @return void
                */
                void setProductRevision(uint32_t productRevision);
                /**
                * @brief Get product_name
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getProductName();
                
                /**
                * @brief Set product_name
                * @param uint8_t* productName
                * @param size_t size
                * @return void
                */
                void setProductName(uint8_t* data, size_t size);
                /**
                * @brief Get manufactured_date
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getManufacturedDate();
                
                /**
                * @brief Set manufactured_date
                * @param uint8_t* manufacturedDate
                * @param size_t size
                * @return void
                */
                void setManufacturedDate(uint8_t* data, size_t size);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
