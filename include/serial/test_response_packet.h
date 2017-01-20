#pragma once

#include <vector>
#include "serial/response_packet.h"

using OpenPST::Serial::ResponsePacket;

namespace OpenPST {
    namespace Serial {
        class TestResponsePacket : public ResponsePacket
        {
            public:
                TestResponsePacket();
                ~TestResponsePacket();
                void unpack(std::vector<uint8_t>& data);
        };
    }
}
