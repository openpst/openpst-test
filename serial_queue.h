#pragma once

#include <deque>
#include "packet.h"

namespace OpenPST {
    namespace Serial {
        class SerialQueue
        {
        	protected:
        		std::deque<Packet*> queue;
        		Packet* current = nullptr;
            public:
                SerialQueue();
                ~SerialQueue();
                void add(Packet* p);
                bool has(Packet* p);
                int count();

        };
    }
}
