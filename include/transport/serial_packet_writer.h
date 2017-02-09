/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file 
* @package 
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

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

