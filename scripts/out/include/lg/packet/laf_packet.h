/**
* LICENSE PLACEHOLDER
*
* @file laf_packet.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "serial/packet.h"

using OpenPST::Serial::Packet;

namespace OpenPST {
    namespace LG {
        
        class LafPacket : public Packet
        {
            public:
                /**
                * @brief Constructor
                */
                LafPacket();
                
                /**
                * @brief Destructor
                */
                ~LafPacket();

                /**
                * @brief Get command
                * @return uint32_t
                */
                uint32_t getCommand();
                
                /**
                * @brief Set command
                * @param uint32_t command
                * @return void
                */
                void setCommand(uint32_t command);
                /**
                * @brief Get arg0
                * @return uint32_t
                */
                uint32_t getArg0();
                
                /**
                * @brief Set arg0
                * @param uint32_t arg0
                * @return void
                */
                void setArg0(uint32_t arg0);
                /**
                * @brief Get arg1
                * @return uint32_t
                */
                uint32_t getArg1();
                
                /**
                * @brief Set arg1
                * @param uint32_t arg1
                * @return void
                */
                void setArg1(uint32_t arg1);
                /**
                * @brief Get arg_opt0
                * @return uint32_t
                */
                uint32_t getArgOpt0();
                
                /**
                * @brief Set arg_opt0
                * @param uint32_t argOpt0
                * @return void
                */
                void setArgOpt0(uint32_t argOpt0);
                /**
                * @brief Get arg_opt1
                * @return uint32_t
                */
                uint32_t getArgOpt1();
                
                /**
                * @brief Set arg_opt1
                * @param uint32_t argOpt1
                * @return void
                */
                void setArgOpt1(uint32_t argOpt1);
                /**
                * @brief Get size
                * @return uint32_t
                */
                uint32_t getSize();
                
                /**
                * @brief Set size
                * @param uint32_t size
                * @return void
                */
                void setSize(uint32_t size);
                /**
                * @brief Get crc
                * @return uint32_t
                */
                uint32_t getCrc();
                
                /**
                * @brief Set crc
                * @param uint32_t crc
                * @return void
                */
                void setCrc(uint32_t crc);
                /**
                * @brief Get magic
                * @return uint32_t
                */
                uint32_t getMagic();
                
                /**
                * @brief Set magic
                * @param uint32_t magic
                * @return void
                */
                void setMagic(uint32_t magic);
                /**
                * @brief Get data
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getData();
                
                /**
                * @brief Set data
                * @param uint8_t* data
                * @param size_t data
                * @return void
                */
                void setData(uint8_t* data, size_t size);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
