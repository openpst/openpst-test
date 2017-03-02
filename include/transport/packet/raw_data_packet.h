#pragma once

#include "transport/packet.h"

using namespace OpenPST::Transport;

namespace OpenPST {
    namespace Transport {
    	
        class RawDataPacket : public Packet
        {
            public:
                /**
                * @brief Constructor
                */
                RawDataPacket(PacketEndianess targetEndian) : 
                    Packet(targetEndian, getMaxDataSize()) 
                {
                    addField("raw_data", kPacketFieldTypeVariant, 0);
                }
                
                /**
                * @brief Destructor
                */
                ~RawDataPacket()
                {

                }

                std::vector<uint8_t> getRawData()
                {
                    return read(getFieldSize(0), getFieldOffset(0));
                }
                                
                void setRawData(uint8_t* data, size_t size)
                {
                    write("raw_data", data, size);
                }

                void setRawData(std::ifstream& file, size_t size)
                {
                    write("raw_data", file, size);
                }

                void prepare() override {

                }

                void prepareResponse() override {

                }

                void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override {
                    if (this->data.size()) {
                        this->data.empty();
                    }

                    this->data = data;

                    auto field = getField(0);

                    field->size = data.size();
                }

        };
    }
}
