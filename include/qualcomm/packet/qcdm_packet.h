#pragma once

#include <vector>
#include <stdint.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "qualcomm/streaming_dload.h"
#include "qualcomm/dm.h"
#include "serial/packet.h"
#include "util/hexdump.h"

using namespace OpenPST::Serial;

namespace OpenPST {
    namespace QC {
    	
        class QcdmPacket : public Packet
        {
            protected:
                HdlcEncoder encoder;

            public:
                /**
                * @brief Constructor
                */
                QcdmPacket() : Packet(getMaxDataSize()) 
                {
                   addField("command", kPacketFieldTypePrimitive, sizeof(uint8_t));
                }
                
                /**
                * @brief Destructor
                */
                ~QcdmPacket() 
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
