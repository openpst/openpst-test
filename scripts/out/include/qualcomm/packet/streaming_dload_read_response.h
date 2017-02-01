/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_read_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadReadResponse : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadReadResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadReadResponse();

                /**
                * @brief Get address
                * @return uint32_t
                */
                uint32_t getAddress();
                
                /**
                * @brief Set address
                * @param uint32_t address
                * @return void
                */
                void setAddress(uint32_t address);
                /**
                * @brief Get data
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getData();
                
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
