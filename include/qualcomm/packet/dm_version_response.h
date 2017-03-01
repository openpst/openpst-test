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
* @file dm_version_response.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_packet.h"

using OpenPST::Qualcomm::DmPacket;

namespace OpenPST {
    namespace Qualcomm {
        
        class DmVersionResponse : public DmPacket
        {
            public:
                /**
                * @brief Constructor
                */
                DmVersionResponse(PacketEndianess targetEndian = kPacketEndianessLittle);
                
                /**
                * @brief Destructor
                */
                ~DmVersionResponse();

                /**
                * @brief Get demod
                * @return uint8_t
                */
                uint8_t getDemod();                
                /**
                * @brief Set demod
                * @param uint8_t demod
                * @return void
                */
                void setDemod(uint8_t demod);                /**
                * @brief Get decode
                * @return uint8_t
                */
                uint8_t getDecode();                
                /**
                * @brief Set decode
                * @param uint8_t decode
                * @return void
                */
                void setDecode(uint8_t decode);                /**
                * @brief Get interleaver_id
                * @return uint8_t
                */
                uint8_t getInterleaverId();                
                /**
                * @brief Set interleaver_id
                * @param uint8_t interleaverId
                * @return void
                */
                void setInterleaverId(uint8_t interleaverId);                /**
                * @brief Get esn
                * @return uint32_t
                */
                uint32_t getEsn();                
                /**
                * @brief Set esn
                * @param uint32_t esn
                * @return void
                */
                void setEsn(uint32_t esn);                /**
                * @brief Get rm_mode
                * @return uint16_t
                */
                uint16_t getRmMode();                
                /**
                * @brief Set rm_mode
                * @param uint16_t rmMode
                * @return void
                */
                void setRmMode(uint16_t rmMode);                /**
                * @brief Get min1
                * @return uint8_t[]
                */
                std::vector<uint8_t> getMin1();                /**
                * @brief Get min1
                * @return std::string
                */
                std::string getMin1();                
                /**
                * @brief Set min1
                * @param uint8_t* min1
                * @param size_t size
                * @return void
                */
                void setMin1(uint8_t* data, size_t size);                /**
                * @brief Set min1
                * @param const std::string& min1
                * @return void
                */
                void setMin1(const std::string& min1);                /**
                * @brief Get min2
                * @return uint8_t[]
                */
                std::vector<uint8_t> getMin2();                /**
                * @brief Get min2
                * @return std::string
                */
                std::string getMin2();                
                /**
                * @brief Set min2
                * @param uint8_t* min2
                * @param size_t size
                * @return void
                */
                void setMin2(uint8_t* data, size_t size);                /**
                * @brief Set min2
                * @param const std::string& min2
                * @return void
                */
                void setMin2(const std::string& min2);                /**
                * @brief Get min_index
                * @return uint8_t
                */
                uint8_t getMinIndex();                
                /**
                * @brief Set min_index
                * @param uint8_t minIndex
                * @return void
                */
                void setMinIndex(uint8_t minIndex);                /**
                * @brief Get cdma_rm_state
                * @return uint16_t
                */
                uint16_t getCdmaRmState();                
                /**
                * @brief Set cdma_rm_state
                * @param uint16_t cdmaRmState
                * @return void
                */
                void setCdmaRmState(uint16_t cdmaRmState);                /**
                * @brief Get cdma_good_frames
                * @return uint8_t
                */
                uint8_t getCdmaGoodFrames();                
                /**
                * @brief Set cdma_good_frames
                * @param uint8_t cdmaGoodFrames
                * @return void
                */
                void setCdmaGoodFrames(uint8_t cdmaGoodFrames);                /**
                * @brief Get analog_correct_frames
                * @return uint16_t
                */
                uint16_t getAnalogCorrectFrames();                
                /**
                * @brief Set analog_correct_frames
                * @param uint16_t analogCorrectFrames
                * @return void
                */
                void setAnalogCorrectFrames(uint16_t analogCorrectFrames);                /**
                * @brief Get analog_bad_frames
                * @return uint16_t
                */
                uint16_t getAnalogBadFrames();                
                /**
                * @brief Set analog_bad_frames
                * @param uint16_t analogBadFrames
                * @return void
                */
                void setAnalogBadFrames(uint16_t analogBadFrames);                /**
                * @brief Get analog_word_syncs
                * @return uint16_t
                */
                uint16_t getAnalogWordSyncs();                
                /**
                * @brief Set analog_word_syncs
                * @param uint16_t analogWordSyncs
                * @return void
                */
                void setAnalogWordSyncs(uint16_t analogWordSyncs);                /**
                * @brief Get entry_reason
                * @return uint16_t
                */
                uint16_t getEntryReason();                
                /**
                * @brief Set entry_reason
                * @param uint16_t entryReason
                * @return void
                */
                void setEntryReason(uint16_t entryReason);                /**
                * @brief Get current_channel
                * @return uint16_t
                */
                uint16_t getCurrentChannel();                
                /**
                * @brief Set current_channel
                * @param uint16_t currentChannel
                * @return void
                */
                void setCurrentChannel(uint16_t currentChannel);                /**
                * @brief Get cdma_code_channel
                * @return uint8_t
                */
                uint8_t getCdmaCodeChannel();                
                /**
                * @brief Set cdma_code_channel
                * @param uint8_t cdmaCodeChannel
                * @return void
                */
                void setCdmaCodeChannel(uint8_t cdmaCodeChannel);                /**
                * @brief Get pilot_base
                * @return uint16_t
                */
                uint16_t getPilotBase();                
                /**
                * @brief Set pilot_base
                * @param uint16_t pilotBase
                * @return void
                */
                void setPilotBase(uint16_t pilotBase);                /**
                * @brief Get sid
                * @return uint16_t
                */
                uint16_t getSid();                
                /**
                * @brief Set sid
                * @param uint16_t sid
                * @return void
                */
                void setSid(uint16_t sid);                /**
                * @brief Get nid
                * @return uint16_t
                */
                uint16_t getNid();                
                /**
                * @brief Set nid
                * @param uint16_t nid
                * @return void
                */
                void setNid(uint16_t nid);                /**
                * @brief Get location_id
                * @return uint16_t
                */
                uint16_t getLocationId();                
                /**
                * @brief Set location_id
                * @param uint16_t locationId
                * @return void
                */
                void setLocationId(uint16_t locationId);                /**
                * @brief Get rssi_level
                * @return uint16_t
                */
                uint16_t getRssiLevel();                
                /**
                * @brief Set rssi_level
                * @param uint16_t rssiLevel
                * @return void
                */
                void setRssiLevel(uint16_t rssiLevel);                /**
                * @brief Get power
                * @return uint8_t
                */
                uint8_t getPower();                
                /**
                * @brief Set power
                * @param uint8_t power
                * @return void
                */
                void setPower(uint8_t power);				/**
				* @overload Packet::unpack
				*/
	            void unpack(std::vector<uint8_t>& data, TransportInterface* transport) override;

        };
    }
}
