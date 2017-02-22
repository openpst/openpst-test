#pragma once

#include "transport/packet.h"

using namespace OpenPST::Transport;

namespace OpenPST {
    namespace Transport {
    	
        class RawDataPacket : public Packet
        {
            public:
                /**
                * @brief Constructor
                */
                RawDataPacket(PacketEndianess targetEndian) : Packet(targetEndian, getMaxDataSize()) 
                {
                    addField("data", kPacketFieldTypeVariant, 0);
                }
                
                /**
                * @brief Destructor
                */
                ~RawDataPacket()
                {

                }

                std::vector<uint8_t> getData()
                {
                    return read(getFieldSize("data"), getFieldOffset("data"));
                }
                                
                void setData(uint8_t* data, size_t size)
                {
                    write("data", data, size);
                }

        };
    }
}
