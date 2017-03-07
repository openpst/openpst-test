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

                    uint8_t expected = (getCommand() > 0) ? getCommand() : 0;
                    uint8_t received = resp[0];

                    if (expected && received != expected) {
                    	if (received == kStreamingDloadError) {
                    		throw PacketError("Unexpected Response: Error Response");
                    	} else if (received == kStreamingDloadLog) {
                    		throw PacketError("Unexpected Response: Log Response");
                    	} else {
                    		throw PacketError("Unexpected Response");
                    	}
                    }

                    setCommand(read<uint8_t>(data, getFieldOffset("command")));
                }

                void prepare() override {

                }
        };
    }
}
