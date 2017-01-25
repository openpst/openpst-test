#pragma once

#include <vector>
#include <stdint.h>
#include <algorithm>
#include <stdexcept>
#include "qualcomm/packet/streaming_dload_packet.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace Serial {
    	
        class PacketTest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                PacketTest();
                
                /**
                * @brief Destructor
                */
                ~PacketTest();

                /**
                * @brief Set the hello magic string (https://www.youtube.com/watch?v=hwSXm8BZvAU)
                *       Max length (excluding terminator) 
                *       is STREAMING_DLOAD_MAGIC_SIZE
                * @param const std::string& magic
                * @throws std::invalid_argument when over max size or empty
                * @return void
                */
                void setMagic(const std::string& magic);

                /**
                * @brief Get the current hello magic (https://www.youtube.com/watch?v=hwSXm8BZvAU)
                * @return std::string
                */
                std::string getMagic();

                /**
                * @brief Set session version
                * @param uint8_t version
                * @return void
                */
                void setVersion(uint8_t version);

                /**
                * @brief Get the current version
                * @return uint8_t
                */
                uint8_t getVersion();

                /**
                * @brief Set session compatible version
                * @param uint8_t compatibleVersion
                * @return void
                */
                void setCompatibleVersion(uint8_t compatibleVersion);
                
                /**
                * @brief Get the current compatible version
                * @return uint8_t
                */
                uint8_t getCompatibleVersion();

                /**
                * @brief Query for features
                * @param uint8_t featureBits
                * @return void
                */
                void setFeatureBits(uint8_t featureBits);

                /**
                * @brief Get the current feature bits
                * @return uint8_t
                */
                uint8_t getFeatureBits();

                void setDtest(std::ifstream& file, size_t amount);
                void setFeatureBits2(uint8_t featureBits2);

                /**
                * @override Packet::unpack()
                */
                void unpack(std::vector<uint8_t>& data) override  {
                    
                }

        };
    }
}
