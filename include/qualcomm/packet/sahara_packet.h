#pragma once

#include "transport/packet.h"
#include "qualcomm/sahara.h"


using namespace OpenPST::Serial;

namespace OpenPST {
    namespace QC {
    	
        class SaharaPacket : public Packet
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaPacket(PacketEndianess targetEndian) : Packet(targetEndian, getMaxDataSize()) 
                {
                   addField("command", kPacketFieldTypePrimitive, sizeof(uint32_t));
                   addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
                }
                
                /**
                * @brief Destructor
                */
                ~SaharaPacket()
                {

                }

                size_t getMaxDataSize() override 
                {
                    return SAHARA_MAX_PACKET_SIZE;
                }

                uint32_t getCommand()
                {
                    return read<uint32_t>(getFieldOffset("command")); 
                }

                void setCommand(uint32_t command)
                {
                    write<uint32_t>("command", command);
                }

                uint32_t getSize()
                {
                    return read<uint32_t>(getFieldOffset("size")); 
                }

                void setSize(uint32_t size)
                {
                    write<uint32_t>("size", size);
                }

                void prepare() override {
                    setSize(data.size());
                }

        };
    }
}
