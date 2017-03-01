#pragma once

#include "transport/packet.h"
#include "qualcomm/streaming_dload.h"

using namespace OpenPST::Transport;

namespace OpenPST {
    namespace Qualcomm {
        
        class StreamingDloadPacket : public Packet
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadPacket(PacketEndianess targetEndian) : 
                	Packet(targetEndian, getMaxDataSize()) 
                {
                   addField("command", kPacketFieldTypePrimitive, sizeof(uint8_t));
                }
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadPacket()
                {

                }

                size_t getMaxDataSize() override {
                    return STREAMING_DLOAD_MAX_RX_SIZE;
                }

                uint8_t getCommand()
                {
                    return read<uint8_t>(getFieldOffset("command")); 
                }

                void setCommand(uint8_t command)
                {
                    write<uint8_t>("command", command);
                }
               
                void unpack(std::vector<uint8_t>& resp, TransportInterface* transport) override {
                    if (!resp.size()) {
                        throw PacketError("No data to unpack");
                    }

                    if (getCommand() && resp[0] != getCommand()) {
                        throw PacketError("Unexpected Response");
                    }
                }

                void prepare() override {

                }
        };
    }
}
