/**
* LICENSE PLACEHOLDER
*
* @file sahara_command_memory_debug64_request.h
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
        
        class SaharaCommandMemoryDebug64Request : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaCommandMemoryDebug64Request();
                
                /**
                * @brief Destructor
                */
                ~SaharaCommandMemoryDebug64Request();

                /**
                * @brief Get client_command
                * @return uint64_t
                */
                uint64_t getClientCommand();
                
                /**
                * @brief Set client_command
                * @param uint64_t clientCommand
                * @return void
                */
                void setClientCommand(uint64_t clientCommand);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
