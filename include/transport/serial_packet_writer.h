#pragma once

#include "transport/packet.h"
#include "transport/serial.h"

using OpenPST::Transport::Serial;
using OpenPST::Transport::SerialError;

namespace OpenPST {
    namespace Transport {
        class SerialPacketWriter
        {
        	protected:
                Serial& port;
            public:
                /**
                * Constructor
                */ 
                SerialPacketWriter(Serial& port);
                
                /**
                * Destructor
                */
                ~SerialPacketWriter();
            private:
                    // no copy
                  SerialPacketWriter(const SerialPacketWriter&);

            public:
                /**
                * @brief Get the serial device interface reference
                * @return Port&
                */
                Serial& getPort();

                /**
                * @brief Write a packet to the serial device
                * @param Packet* packet
                * @return void
                */
                void write(Packet* packet);
                
                /**
                * @brief Read from the serial device into a packet
                * @param Packet* packet
                * @param size_t size
                * @return void
                */
                void read(Packet* packet);

        };

        /**
        * @brief PacketOutOfRangeException
        */
		class SerialPacketWriterError : public std::exception
		{
			private:
				const SerialPacketWriterError& operator=(SerialPacketWriterError);
				std::string _what;
			public:
				SerialPacketWriterError(std::string message) : 
					_what(message)  { }
				SerialPacketWriterError(const SerialPacketWriterError& second) : 
					_what(second._what) {}
				virtual ~SerialPacketWriterError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};
    }
}

