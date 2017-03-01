#pragma once

#include "transport/packet.h"
#include "qualcomm/sahara.h"

using namespace OpenPST::Transport;

namespace OpenPST {
    namespace Qualcomm {
    	
        class SaharaPacket : public Packet
        {
            public:
                /**
                * @brief Constructor
                */
                SaharaPacket(PacketEndianess targetEndian) : 
                	Packet(targetEndian, getMaxDataSize()) 
                {
                   addField("command", kPacketFieldTypePrimitive, sizeof(uint32_t));
                   addField("packet_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
                }
                
                /**
                * @brief Destructor
                */
                ~SaharaPacket()
                {

                }

                size_t getMaxDataSize() override 
                {
                    return SAHARA_MAX_PACKET_SIZE;
                }

                uint32_t getCommand()
                {
                    return read<uint32_t>(getFieldOffset("command")); 
                }

                void setCommand(uint32_t command)
                {
                    write<uint32_t>("command", command);
                }

                uint32_t getPacketSize()
                {
                    return read<uint32_t>(getFieldOffset("packet_size")); 
                }

                void setPacketSize(uint32_t size)
                {
                    write<uint32_t>("packet_size", size);
                }

                void prepare() override {
                    setPacketSize(data.size());
                }

                void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override {
                    if (!data.size()) {
                        return;
                    }

                    setCommand(read<uint32_t>(data, getFieldOffset("command")));
                    setPacketSize(read<uint32_t>(data, getFieldOffset("packet_size")));
                    
                    if (getCommand() == kSaharaCommandEndImageTransfer) {
                        uint32_t status = read<uint32_t>(data, 12);

                        if (status) {
                            throw PacketError("Device Sent Error Response: " + getCodeMessage(status));
                        }
                    }
                }

                const std::string getCodeMessage(uint32_t code)
                {
                    switch (code) {
                        case kSaharaStatusSuccess:                      return "Success";
                        case kSaharaStatusInvalidCmd:                   return "Invalid Command";
                        case kSaharaStatusProtocolMismatch:             return "Protocol Mismatch";
                        case kSaharaStatusInvalidTargetProtocol:        return "Invalid Target Protocol";
                        case kSaharaStatusInvalidHostProtocol:          return "Invalid Host Protocol";
                        case kSaharaStatusInvalidPacketSize:            return "Invalid Packet Size";
                        case kSaharaStatusUnexpectedImageId:            return "Unexpected Image ID";
                        case kSaharaStatusInvalidHeaderSize:            return "Invalid Header Size";
                        case kSaharaStatusInvalidDataSize:              return "Invalid Data Size";
                        case kSaharaStatusInvalidImageType:             return "Invalid Image Type";
                        case kSaharaStatusInvalidTxLength:              return "Invalid TX Length";
                        case kSaharaStatusInvalidRxLength:              return "Invalid RX Length";
                        case kSaharaStatusTxRxError:                    return "General TX RX Error";
                        case kSaharaStatusUnsupportedNumPhdrs:          return "Cannot receive specified number of program headers";
                        case kSaharaStatusInvalidPhdrSize:              return "Invalid data length received for program headers";
                        case kSaharaStatusMultipleSharedSeg:            return "Multiple shared segments found in ELF image";
                        case kSaharaStatusUninitPhdrLoc:                return "Uninitialized program header location";
                        case kSaharaStatusInvalidDestAddress:           return "Invalid destination address";
                        case kSaharaStatusInvalidImageHeaderSize:       return "Invalid data size receieved in image header";
                        case kSaharaStatusInvalidElfHeader:             return "Invalid ELF header received";
                        case kSaharaStatusUnknownError:                 return "Unknown Host Error";
                        case kSaharaStatusTimeoutRx:                    return "RX Timeout";
                        case kSaharaStatusTimeoutTx:                    return "TX Timeout";
                        case kSaharaStatusInvalidMode:                  return "Invalid Host Mode";
                        case kSaharaStatusInvalidMemoryRead:            return "Invalid Memory Read";
                        case kSaharaStatusInvalidDataSizeRequest:       return "Invalid Data Size Request";
                        case kSaharaStatusMemoryDebugNotSupported:      return "Memory Debug Not Supported";
                        case kSaharaStatusInvalidModeSwitch:            return "Invalid Mode Switch";
                        case kSaharaStatusExecFailure:                  return "Command Execute Failure";
                        case kSaharaStatusExecCmdInvalidParam:          return "Invalid Command Parameter";
                        case kSaharaStatusExecCmdUnsupported:           return "Command Unsupported";
                        case kSaharaStatusExecDataInvalid:              return "Invalid Client Command";
                        case kSaharaStatusHashTableAuthFailure:         return "Hash Table Auth Failure";
                        case kSaharaStatusHashVerificationFailure:      return "Hash Table Verification Failure";
                        case kSaharaStatusHashTableNotFound:            return "Hash Table Not Found";
                        case kSaharaStatusTargetInitFailure:            return "Target Init Failure";
                        case kSaharaStatusImageAuthFailure:             return "Image Auth Failure";
                        case kSaharaStatusInvalidImgHashTableSize:      return "Invalid ELF Hash Table Size";
                        default:                                        return "Unknown";
                    }
                }
        };
    }
}
