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
* @file packet_transporter.h
* @package openpst/libopenpst
* @brief Writes and reads packet objects over a TransportInterface
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "transport/packet.h"
#include "transport/transport_interface.h"

namespace OpenPST {
    namespace Transport {
        class PacketTransporter
        {
        	protected:
                TransportInterface& transport;

            public:
                /**
                * Constructor
                */ 
                PacketTransporter(TransportInterface& transport);
                
                /**
                * Destructor
                */
                ~PacketTransporter();
            private:
                  // no copy
                  PacketTransporter(const PacketTransporter&);

            public:

                /**
                * @brief Get the transport interface pointer
                * @return TransportInterface&
                */
                TransportInterface* getTransport();

                /**
                * @brief Set the transport interface
                * @return void
                */
                void setTransport(TransportInterface& transport);

                /**
                * @brief Write a packet to the serial device
                * @param Packet* packet
                * @param bool andWrite - If the packet isResponseExpected() and true, will read
                * 						 the packets response packet. Defaults true
                * @return void
                */
                void write(Packet* packet, bool andRead = true);
                
                /**
                * @brief Read from the serial device into a packet
                * @param Packet* packet
                * @param bool andWrite - If the packet isResponseExpected() and true, will write
                * 						 the packets response packet. Defaults true
                * @return void
                */
                void read(Packet* packet, bool andWrite = true);

        };

        /**
        * @brief PacketOutOfRangeException
        */
		class PacketTransporterError : public std::exception
		{
			private:
				const PacketTransporterError& operator=(PacketTransporterError);
				std::string _what;
			public:
				PacketTransporterError(std::string message) : 
					_what(message)  { }
				PacketTransporterError(const PacketTransporterError& second) : 
					_what(second._what) {}
				virtual ~PacketTransporterError() throw() {}
				virtual const char* what() const throw () {
					return _what.c_str();
				}
				virtual const std::string& what() {
					return _what;
				}
		};
    }
}

