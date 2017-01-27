#pragma once

#include "serial/packet.h"
#include "serial/generic_serial.h"

namespace OpenPST {
    namespace Serial {
        class SerialPacketWriter
        {
        	protected:
                GenericSerial& port;
            public:
                /**
                * Constructor
                */ 
                SerialPacketWriter(GenericSerial& port);
                
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
                * @return GenericSerial&
                */
                GenericSerial& getPort();

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

