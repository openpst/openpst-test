#pragma once

#include <vector>
#include <stdint.h>
#include <algorithm>

namespace OpenPST {
    namespace Serial {
    	
    	enum PacketEndianess{
    		kPacketEndianessLittle,
    		kPacketEndianessBig
    	};

        class Packet
        {
        	protected:
        		PacketEndianess endianT;
        		PacketEndianess endianH;
        		Packet* response = nullptr;
        		bool sent = false;
        		// uint8_t* data = nullptr;
            public:
                
                Packet(PacketEndianess endianT = kPacketEndianessLittle, PacketEndianess endianH = kPacketEndianessLittle);
                
                ~Packet();
                
                /**
                * @brief Set the target endianess
                *
                * @param PacketEndianess e
                * @return void
                */
                void setTargetEndianess(PacketEndianess e);

                /**
                * @brief Get the target endianess
                *
                * @return PacketEndianess
                */
                PacketEndianess getTargetEndianess();

                /**
                * @brief Set the host endianess
                *
                * @param PacketEndianess e
                * @return void
                */
                void setHostEndianess(PacketEndianess e);

                /**
                * @brief Get the host endianess
                *
                * @return PacketEndianess
                */
                PacketEndianess getHostEndianess();

                /**
                *
                */
                bool isSent();

                /**
                *
                */
                void setSent(bool s);



                /*
                uint8_t  read8(uint8_t* src);
                uint16_t read16(uint8_t* src);
                uint32_t read32(uint8_t* src);
                uint64_t read64(uint8_t* src);
                uint64_t read(uint8_t* src, size_t available, uint8_t* dest, size_t amount);

                void write8(uint8_t v, uint8_t* dest);
                void write16(uint16_t v, uint8_t* dest);
                void write32(uint32_t v, uint8_t* dest);
                void write64(uint64_t v, uint8_t* dest);
                void write(uint8_t* src, size_t amount, uint8_t* dest, size_t available);
                

                virtual std::vector<uint8_t> pack() = 0;
     
                virtual Packet* unpack(std::vector<uint8_t>& data) = 0;
*/
                Packet* getResponse();

            protected:
            	template <class T> T swap(T i);
        };
    }
}
