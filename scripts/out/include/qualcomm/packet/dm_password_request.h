/**
* LICENSE PLACEHOLDER
*
* @file dm_password_request.h
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
        
        class DmPasswordRequest : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmPasswordRequest(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~DmPasswordRequest();

                /**
                * @brief Get password
                * @return uint8_t[]
                */
                std::vector<uint8_t> getPassword();
                /**
                * @brief Get password
                * @return std::string
                */
                std::string getPassword();
                
                /**
                * @brief Set password
                * @param uint8_t* password
                * @param size_t size
                * @return void
                */
                void setPassword(uint8_t* data, size_t size);
                /**
                * @brief Set password
                * @param const std::string& password
                * @return void
                */
                void setPassword(const std::string& password);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
