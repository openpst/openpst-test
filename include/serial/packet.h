#pragma once

#include <vector>
#include <stdint.h>
#include <algorithm>
#include <stdexcept>

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
        		std::vector<uint8_t> data;
        		bool responseExpected = true;
        		Packet* response 	  = nullptr;

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
                * @brief Get the flag that this packet will require a response
                * @return bool
                */
                bool getResponseExpected();

                /**
                * @brief Set the flag that this packet will require a response
                * @param bool 
                * @return void
                */
                void setResponseExpected(bool v);

                /**
                * @brief Get ther response packet, if it has been unpacked
                */
                Packet* getResponse();

                /**
                * @brief Read primitive type T from the data buffer at offset
                * @throws std::out_of_range 
                * @return T
                */
                template <class T> T read(int offset);

                /**
                * @brief Write primitive type T into the data buffer at offset
                * @return void
                */
                template <class T> void write(T value, int offset);
                
                /**
                * @brief Write specified amount of bytes from src into the data buffer at offset
                * @return void
                */
                void write(uint8_t* src, size_t amount, int offset);

                /**
                * @brief Validate the data in the packet buffer
                */
                //virtual void validate();

                /**
                * @brief Prepare the data before sending, making and final adjustments
                */
                //virtual void prepare();

                /**
                * @brief Unpack the response buffer into a response Packet
                */
                //virtual void unpack(std::vector<uint8_t>& data) = 0;

            protected:
            	/**
            	* @brief Byte swap primititve type T
            	* @return T
            	*/
            	template <class T> T swap(T i);
        };
    }
}
