#pragma once

#include "serial/packet.h"
#include "qualcomm/dm.h"
#include "qualcomm/hdlc_encoder.h"

using namespace OpenPST::Serial;

namespace OpenPST {
    namespace QC {
    	
        class DmPacket : public Packet
        {
            protected:
                HdlcEncoder encoder;

            public:
                /**
                * @brief Constructor
                */
                DmPacket() : Packet(getMaxDataSize()) 
                {
                   addField("command", kPacketFieldTypePrimitive, sizeof(uint8_t));
                }
                
                /**
                * @brief Destructor
                */
                ~DmPacket()
                {
                    
                }

                size_t getMaxDataSize() override 
                {
                    return DIAG_MAX_PACKET_DATA_SIZE;
                }

                void setCommand(uint8_t command)
                {
                    write<uint8_t>(command, getFieldOffset("command"));
                }

                uint8_t getCommand()
                {
                    return read<uint8_t>(getFieldOffset("command")); 
                }

                void prepare() override {
                    encoder.encode(data);
                }

        };
    }
}
