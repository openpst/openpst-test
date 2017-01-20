#pragma once

#include <vector>
#include <stdint.h>
#include <algorithm>

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
                
                /**
                * @brief Set the target endianess
                *
                * @param PacketEndianess e
                * @return void
                */
                void setTargetEndianess(PacketEndianess e) {
                	endianT = e;
                }

                /**
                * @brief Get the target endianess
                *
                * @return PacketEndianess
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

                Packet* getResponse() {
                	return response;
                }

                /**
                *
                */
                //virtual std::vector<uint8_t> pack() = 0;
               
               /**
                *
                */
                //virtual Packet* unpack(std::vector<uint8_t>& data) = 0;

            protected:
            	template <class T> T swap(T i)
            	{
            		// don't flip a byte
            		// don't flip anything greater than uint64_t
            		if (sizeof(T) > sizeof(uint64_t) || sizeof(T) == sizeof(uint8_t)) {
            			return i;
            		}

					T ret = i;

					std::reverse(
						reinterpret_cast<unsigned char*>(&ret), 
						reinterpret_cast<unsigned char*>(&ret) + sizeof(T)
					);
					return ret;
				}
        };
    }
}
