#pragma once

#include <vector>
#include <stdint.h>

namespace OpenPST {
    namespace Serial {
        class Packet
        {
        	enum PacketEndianess{
        		kPacketEndianessLittle,
        		kPacketEndianessBig
        	};

        	protected:
        		PacketEndianess endianT = kPacketEndianessLittle;
        		PacketEndianess endianH = kPacketEndianessLittle;

            public:
                
                Packet(){

                }
                
                ~Packet(){

                }
                
                void setTargetEndianess(PacketEndianess e) {
                	endianT = e;
                }

                PacketEndianess getTargetEndianess() {
                	return endianT;
                }

                void setHostEndianess(PacketEndianess e) {
                	endianH = e;
                }

                PacketEndianess getHostEndianess() {
                	return endianH;
                }
        };
    }
}
