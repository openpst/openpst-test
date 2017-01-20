#pragma once

#include <vector>
#include "packet.h"

using OpenPST::Serial::Packet;

namespace OpenPST {
    namespace Serial {
        class ResponsePacket : public Packet
        {
            public:
                ResponsePacket() : Packet() {

                }

                ~ResponsePacket() {

                }
                virtual void unpack(std::vector<uint8_t>& data) = 0;
        };
    }
}
