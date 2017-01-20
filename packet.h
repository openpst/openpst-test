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
        		PacketEndianess endianT;
        		PacketEndianess endianH;
        		Packet* response = nullptr;
        		bool sent = false;
            public:
                
                Packet(PacketEndianess endianT = kPacketEndianessLittle, PacketEndianess endianH = kPacketEndianessLittle) : 
                	endianT(endianT), 
                	endianH(endianH) 
                {

                }
                
                ~Packet(){
                	if (response != nullptr) {
                		delete response;
                	}
                }
                
                void setTargetEndianess(PacketEndianess e) {
                	endianT = e;
                }

                /**
                *
                */
                PacketEndianess getTargetEndianess() {
                	return endianT;
                }

                /**
                * @brief Set the host endianess
                *
                * @param PacketEndianess e
                * @return void
                */
                void setHostEndianess(PacketEndianess e) {
                	endianH = e;
                }

                /**
                * @brief Get the host endianess
                *
                * @return PacketEndianess
                */
                PacketEndianess getHostEndianess() {
                	return endianH;
                }

                /**
                *
                */
                bool isSent() {
                	return sent;
                }

                /**
                *
                */
                void setSent(bool s) {
                	sent = s;
                }

                u16 flip(uint16_t i);
                u32 flip(uint32_t i);
                u64 flip(uint64_t i);
                /**
                *
                */
                //virtual std::vector<uint8_t> pack() = 0;
               
               /**
                *
                */
                //virtual Packet* unpack(std::vector<uint8_t>& data) = 0;
 
        };
    }
}
