/**
* LICENSE PLACEHOLDER
*
* @file sahara_client_command_execute_data_request.h
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
        
        class SaharaClientCommandExecuteDataRequest : public SaharaPacket
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaClientCommandExecuteDataRequest(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~SaharaClientCommandExecuteDataRequest();

                /**
                * @brief Get client_command
                * @return uint32_t
                */
                uint32_t getClientCommand();
                
                /**
                * @brief Set client_command
                * @param uint32_t clientCommand
                * @return void
                */
                void setClientCommand(uint32_t clientCommand);
				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
