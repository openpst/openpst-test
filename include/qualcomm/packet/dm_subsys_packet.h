#pragma once

#include "serial/packet.h"
#include "qualcomm/dm.h"
#include "qualcomm/hdlc_encoder.h"

using namespace OpenPST::Serial;

namespace OpenPST {
    namespace QC {
    	
        class DmSubsysPacket : public Packet
        {
            protected:
                HdlcEncoder encoder;

            public:
                /**
                * @brief Constructor
                */
                DmSubsysPacket() : Packet(getMaxDataSize()) 
                {
                   addField("command", kPacketFieldTypePrimitive, sizeof(uint8_t));
                   addField("subsys_id", kPacketFieldTypePrimitive, sizeof(uint8_t));
                   addField("subsys_command", kPacketFieldTypePrimitive, sizeof(uint16_t));
                }
                
                /**
                * @brief Destructor
                */
                ~DmSubsysPacket()
                {

                }

                size_t getMaxDataSize() override 
                {
                    return DIAG_MAX_PACKET_DATA_SIZE;
                }

                uint8_t getCommand()
                {
                    return read<uint8_t>(getFieldOffset("command")); 
                }

                void setCommand(uint8_t command)
                {
                    write<uint8_t>(command, getFieldOffset("command"));
                }

                uint8_t getSubsysId()
                {
                    return read<uint8_t>(getFieldOffset("subsys_id")); 
                }

                void setSubsysId(uint8_t subsysId)
                {
                    write<uint8_t>(subsysId, getFieldOffset("subsys_id"));
                }

                uint16_t getSubsysCommand()
                {
                    return read<uint16_t>(getFieldOffset("subsys_command")); 
                }

                void setSubsysCommand(uint16_t subsysCommand)
                {
                    write<uint16_t>(subsysCommand, getFieldOffset("subsys_command"));
                }

                void prepare() override {
                    encoder.encode(data);
                }

        };
    }
}
