#pragma once

#include "transport/packet.h"
#include "qualcomm/dm.h"
#include "qualcomm/hdlc_encoder.h"

using namespace OpenPST::Transport;

namespace OpenPST {
    namespace QC {
    	
        class DmEfsPacket : public Packet
        {
            protected:
                HdlcEncoder encoder;

            public:
                /**
                * @brief Constructor
                */
                DmEfsPacket(PacketEndianess targetEndian) : Packet(targetEndian, getMaxDataSize()) 
                {
                   addField("command", kPacketFieldTypePrimitive, sizeof(uint8_t));
                   addField("subsys_id", kPacketFieldTypePrimitive, sizeof(uint8_t));
                   addField("subsys_command", kPacketFieldTypePrimitive, sizeof(uint16_t));

                   setCommand(kDiagSubsysCmd);
                   setSubsysId(kDiagSubsysEfs);
                }
                
                /**
                * @brief Destructor
                */
                ~DmEfsPacket()
                {
                    
                }

                size_t getMaxDataSize() override 
                {
                    return DIAG_MAX_PACKET_DATA_SIZE;
                }

                void setCommand(uint8_t command)
                {
                    write<uint8_t>("command", command);
                }

                uint8_t getCommand()
                {
                    return read<uint8_t>(getFieldOffset("command"));
                }

                void setSubsysId(uint8_t subsysId)
                {
                    write<uint8_t>("subsys_id", subsysId);
                }

                uint8_t getSubsysId()
                {
                    return read<uint8_t>(getFieldOffset("subsys_id"));
                }

                void setSubsysCommand(uint16_t command)
                {
                    write<uint16_t>("subsys_command", command);
                }

                uint16_t getSubsysCommand()
                {
                    return read<uint16_t>(getFieldOffset("subsys_command"));
                }
                
                void unpack(std::vector<uint8_t>& resp) override {
                    if (!resp.size()) {
                        throw PacketError("No data to unpack");
                    }

                    encoder.decode(resp);

                    if (resp[0] != getCommand()) {
                        throw PacketError("Unexpected Response");
                    }
                }

                void prepare() override {
                    encoder.encode(data);
                }

        };
    }
}
