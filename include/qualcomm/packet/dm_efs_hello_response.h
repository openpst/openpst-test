/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_hello_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"

using OpenPST::QC::DmEfsPacket;

namespace OpenPST {
    namespace QC {
        
        class DmEfsHelloResponse : public DmEfsPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmEfsHelloResponse(PacketEndianess targetEndian);
                
                /**
                * @brief Destructor
                */
                ~DmEfsHelloResponse();

                /**
                * @brief Get target_packet_window_size
                * @return uint32_t
                */
                uint32_t getTargetPacketWindowSize();
                
                /**
                * @brief Set target_packet_window_size
                * @param uint32_t targetPacketWindowSize
                * @return void
                */
                void setTargetPacketWindowSize(uint32_t targetPacketWindowSize);
                /**
                * @brief Get target_packet_window_byte_size
                * @return uint32_t
                */
                uint32_t getTargetPacketWindowByteSize();
                
                /**
                * @brief Set target_packet_window_byte_size
                * @param uint32_t targetPacketWindowByteSize
                * @return void
                */
                void setTargetPacketWindowByteSize(uint32_t targetPacketWindowByteSize);
                /**
                * @brief Get host_packet_window_size
                * @return uint32_t
                */
                uint32_t getHostPacketWindowSize();
                
                /**
                * @brief Set host_packet_window_size
                * @param uint32_t hostPacketWindowSize
                * @return void
                */
                void setHostPacketWindowSize(uint32_t hostPacketWindowSize);
                /**
                * @brief Get host_packet_window_byte_size
                * @return uint32_t
                */
                uint32_t getHostPacketWindowByteSize();
                
                /**
                * @brief Set host_packet_window_byte_size
                * @param uint32_t hostPacketWindowByteSize
                * @return void
                */
                void setHostPacketWindowByteSize(uint32_t hostPacketWindowByteSize);
                /**
                * @brief Get dir_iterator_window_size
                * @return uint32_t
                */
                uint32_t getDirIteratorWindowSize();
                
                /**
                * @brief Set dir_iterator_window_size
                * @param uint32_t dirIteratorWindowSize
                * @return void
                */
                void setDirIteratorWindowSize(uint32_t dirIteratorWindowSize);
                /**
                * @brief Get dir_iterator_window_byte_size
                * @return uint32_t
                */
                uint32_t getDirIteratorWindowByteSize();
                
                /**
                * @brief Set dir_iterator_window_byte_size
                * @param uint32_t dirIteratorWindowByteSize
                * @return void
                */
                void setDirIteratorWindowByteSize(uint32_t dirIteratorWindowByteSize);
                /**
                * @brief Get version
                * @return uint32_t
                */
                uint32_t getVersion();
                
                /**
                * @brief Set version
                * @param uint32_t version
                * @return void
                */
                void setVersion(uint32_t version);
                /**
                * @brief Get max_version
                * @return uint32_t
                */
                uint32_t getMaxVersion();
                
                /**
                * @brief Set max_version
                * @param uint32_t maxVersion
                * @return void
                */
                void setMaxVersion(uint32_t maxVersion);
                /**
                * @brief Get feature_bits
                * @return uint32_t
                */
                uint32_t getFeatureBits();
                
                /**
                * @brief Set feature_bits
                * @param uint32_t featureBits
                * @return void
                */
                void setFeatureBits(uint32_t featureBits);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
