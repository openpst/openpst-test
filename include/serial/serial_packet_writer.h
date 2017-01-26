#pragma once

#include "serial/packet.h"
#include "serial/generic_serial.h"

namespace OpenPST {
    namespace Serial {
        class SerialPacketWriter
        {
        	protected:
                GenericSerial port;
            public:

                /**
                * Constructor
                */
                SerialPacketWriter(const std::string& port, int baudRate = 115200, int timeout = 1000);
                
                /**
                * Destructor
                */
                ~SerialPacketWriter();
                
                /**
                * @brief Get the serial device interface
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
                void read(Packet* packet, size_t size)

        };
    }
}
