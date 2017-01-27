#pragma once

#include "serial/packet.h"
#include "serial/mock_serial.h"

namespace OpenPST {
    namespace Serial {
        class MockSerialPacketWriter
        {
        	protected:
                MockSerial& port;
            public:
                /**
                * Constructor
                */ 
                MockSerialPacketWriter(MockSerial& port);
                
                /**
                * Destructor
                */
                ~MockSerialPacketWriter();
            private:
                    // no copy
                  MockSerialPacketWriter(const MockSerialPacketWriter&);

            public:
                /**
                * @brief Get the serial device interface reference
                * @return GenericSerial&
                */
                MockSerial& getPort();

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
		class MockSerialPacketWriterError : public std::exception
		{
			private:
				const MockSerialPacketWriterError& operator=(MockSerialPacketWriterError);
				std::string _what;
			public:
				MockSerialPacketWriterError(std::string message) : 
					_what(message)  { }
				MockSerialPacketWriterError(const MockSerialPacketWriterError& second) : 
					_what(second._what) {}
				virtual ~MockSerialPacketWriterError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};
    }
}

