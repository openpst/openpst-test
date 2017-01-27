#pragma once

#include "serial/packet.h"
#include "qualcomm/streaming_dload.h"
#include "qualcomm/hdlc_encoder.h"

using namespace OpenPST::Serial;

namespace OpenPST {
    namespace QC {
    	
        class StreamingDloadPacket : public Packet
        {
            protected:
                HdlcEncoder encoder;

            public:
                /**
                * @brief Constructor
                */
                StreamingDloadPacket() : Packet(getMaxDataSize()) 
                {
                   addField("command", kPacketFieldTypePrimitive, sizeof(uint8_t));
                }
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadPacket() 
                {

                }

                size_t getMaxDataSize() override 
                {
                    return STREAMING_DLOAD_MAX_DATA_SIZE;
                }

                void setCommand(uint8_t command)
                {
                    write<uint8_t>("command", command);
                }

                uint8_t getCommand()
                {
                    return read<uint8_t>(getFieldOffset("command")); 
                }

                void prepare() override {
                    encoder.encode(data);
                }
                
                void unpack(std::vector<uint8_t>& data) override {
                    encoder.decode(data);
                }
        };
    }
}
