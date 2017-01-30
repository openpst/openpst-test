/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_hello_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"
#include "qualcomm/packet/streaming_dload_hello_response.h"

using OpenPST::QC::StreamingDloadPacket;
using OpenPST::QC::StreamingDloadHelloResponse;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadHelloRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadHelloRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadHelloRequest();

                /**
                * @brief Get magic
                * @return std::string
                */
                std::string getMagic();
                
                /**
                * @brief Set magic
                * @param const std::string& magic
                * @return void
                */
                void setMagic(const std::string& magic);
                /**
                * @brief Get version
                * @return uint8_t
                */
                uint8_t getVersion();
                
                /**
                * @brief Set version
                * @param uint8_t version
                * @return void
                */
                void setVersion(uint8_t version);
                /**
                * @brief Get compatible_version
                * @return uint8_t
                */
                uint8_t getCompatibleVersion();
                
                /**
                * @brief Set compatible_version
                * @param uint8_t compatibleVersion
                * @return void
                */
                void setCompatibleVersion(uint8_t compatibleVersion);
                /**
                * @brief Get feature_bits
                * @return uint8_t
                */
                uint8_t getFeatureBits();
                
                /**
                * @brief Set feature_bits
                * @param uint8_t featureBits
                * @return void
                */
                void setFeatureBits(uint8_t featureBits);
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
