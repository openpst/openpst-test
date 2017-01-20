#pragma once

#include <vector>
#include "packet.h"

using OpenPST::Serial::Packet;

namespace OpenPST {
    namespace Serial {
        class RequestPacket : public Packet
        {
            public:
                RequestPacket() : Packet() {

                }

                ~RequestPacket() {

                }
                
                virtual std::vector<uint8_t> pack() = 0;
        };
    }
}
