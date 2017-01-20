#pragma once

#include <vector>
#include "request_packet.h"

using OpenPST::Serial::RequestPacket;

namespace OpenPST {
    namespace Serial {
        class TestRequestPacket : public RequestPacket
        {
            public:
                TestRequestPacket();
                ~TestRequestPacket();
                std::vector<uint8_t> pack();
        };
    }
}
