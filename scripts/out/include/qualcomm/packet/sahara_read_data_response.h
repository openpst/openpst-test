/**
* LICENSE PLACEHOLDER
*
* @file sahara_read_data_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "serial/packet.h"

using OpenPST::Serial::Packet;

namespace OpenPST {
    namespace QC {
        
        class SaharaReadDataResponse : public Packet
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaReadDataResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~SaharaReadDataResponse();

                /**
                * @brief Get data
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getData();
                /**
                * @brief Get data
                * @return std::string
                */
                std::string getData();
                
                /**
                * @brief Set data
                * @param std::ifstream& file
                * @param size_t size
                * @return void
                */
                void setData(std::ifstream& file, size_t size);
                /**
                * @brief Set data
                * @param uint8_t* data
                * @param size_t data
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
