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
* @file dm_version_response.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/09/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_version_response.h"

using namespace OpenPST::Qualcomm;

DmVersionResponse::DmVersionResponse(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("demod", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("decode", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("interleaver_id", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("esn", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("rm_mode", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("min1", kPacketFieldTypeArray, 8);
	addField("min2", kPacketFieldTypeArray, 8);
	addField("min_index", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("cdma_rm_state", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("cdma_good_frames", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("analog_correct_frames", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("analog_bad_frames", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("analog_word_syncs", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("entry_reason", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("current_channel", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("cdma_code_channel", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("pilot_base", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("sid", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("nid", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("location_id", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("rssi_level", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("power", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kDiagDiagVer);

	setResponseExpected(false);
}

DmVersionResponse::~DmVersionResponse()
{

}

uint8_t DmVersionResponse::getDemod()
{
    return read<uint8_t>(getFieldOffset("demod"));
}
                

void DmVersionResponse::setDemod(uint8_t demod)
{
    write<uint8_t>("demod", demod);
}

uint8_t DmVersionResponse::getDecode()
{
    return read<uint8_t>(getFieldOffset("decode"));
}
                

void DmVersionResponse::setDecode(uint8_t decode)
{
    write<uint8_t>("decode", decode);
}

uint8_t DmVersionResponse::getInterleaverId()
{
    return read<uint8_t>(getFieldOffset("interleaver_id"));
}
                

void DmVersionResponse::setInterleaverId(uint8_t interleaverId)
{
    write<uint8_t>("interleaver_id", interleaverId);
}

uint32_t DmVersionResponse::getEsn()
{
    return read<uint32_t>(getFieldOffset("esn"));
}
                

void DmVersionResponse::setEsn(uint32_t esn)
{
    write<uint32_t>("esn", esn);
}

uint16_t DmVersionResponse::getRmMode()
{
    return read<uint16_t>(getFieldOffset("rm_mode"));
}
                

void DmVersionResponse::setRmMode(uint16_t rmMode)
{
    write<uint16_t>("rm_mode", rmMode);
}

std::vector<uint8_t> DmVersionResponse::getMin1()
{
	return read(getFieldSize("min1"), getFieldOffset("min1"));
}

std::string DmVersionResponse::getMin1()
{
	return getString(8, getFieldOffset("min1"));
}
                

void DmVersionResponse::setMin1(uint8_t* data, size_t size)
{
    write("min1", data, size);
}

void DmVersionResponse::setMin1(const std::string& min1)
{
    write("min1", min1);
}

std::vector<uint8_t> DmVersionResponse::getMin2()
{
	return read(getFieldSize("min2"), getFieldOffset("min2"));
}

std::string DmVersionResponse::getMin2()
{
	return getString(8, getFieldOffset("min2"));
}
                

void DmVersionResponse::setMin2(uint8_t* data, size_t size)
{
    write("min2", data, size);
}

void DmVersionResponse::setMin2(const std::string& min2)
{
    write("min2", min2);
}

uint8_t DmVersionResponse::getMinIndex()
{
    return read<uint8_t>(getFieldOffset("min_index"));
}
                

void DmVersionResponse::setMinIndex(uint8_t minIndex)
{
    write<uint8_t>("min_index", minIndex);
}

uint16_t DmVersionResponse::getCdmaRmState()
{
    return read<uint16_t>(getFieldOffset("cdma_rm_state"));
}
                

void DmVersionResponse::setCdmaRmState(uint16_t cdmaRmState)
{
    write<uint16_t>("cdma_rm_state", cdmaRmState);
}

uint8_t DmVersionResponse::getCdmaGoodFrames()
{
    return read<uint8_t>(getFieldOffset("cdma_good_frames"));
}
                

void DmVersionResponse::setCdmaGoodFrames(uint8_t cdmaGoodFrames)
{
    write<uint8_t>("cdma_good_frames", cdmaGoodFrames);
}

uint16_t DmVersionResponse::getAnalogCorrectFrames()
{
    return read<uint16_t>(getFieldOffset("analog_correct_frames"));
}
                

void DmVersionResponse::setAnalogCorrectFrames(uint16_t analogCorrectFrames)
{
    write<uint16_t>("analog_correct_frames", analogCorrectFrames);
}

uint16_t DmVersionResponse::getAnalogBadFrames()
{
    return read<uint16_t>(getFieldOffset("analog_bad_frames"));
}
                

void DmVersionResponse::setAnalogBadFrames(uint16_t analogBadFrames)
{
    write<uint16_t>("analog_bad_frames", analogBadFrames);
}

uint16_t DmVersionResponse::getAnalogWordSyncs()
{
    return read<uint16_t>(getFieldOffset("analog_word_syncs"));
}
                

void DmVersionResponse::setAnalogWordSyncs(uint16_t analogWordSyncs)
{
    write<uint16_t>("analog_word_syncs", analogWordSyncs);
}

uint16_t DmVersionResponse::getEntryReason()
{
    return read<uint16_t>(getFieldOffset("entry_reason"));
}
                

void DmVersionResponse::setEntryReason(uint16_t entryReason)
{
    write<uint16_t>("entry_reason", entryReason);
}

uint16_t DmVersionResponse::getCurrentChannel()
{
    return read<uint16_t>(getFieldOffset("current_channel"));
}
                

void DmVersionResponse::setCurrentChannel(uint16_t currentChannel)
{
    write<uint16_t>("current_channel", currentChannel);
}

uint8_t DmVersionResponse::getCdmaCodeChannel()
{
    return read<uint8_t>(getFieldOffset("cdma_code_channel"));
}
                

void DmVersionResponse::setCdmaCodeChannel(uint8_t cdmaCodeChannel)
{
    write<uint8_t>("cdma_code_channel", cdmaCodeChannel);
}

uint16_t DmVersionResponse::getPilotBase()
{
    return read<uint16_t>(getFieldOffset("pilot_base"));
}
                

void DmVersionResponse::setPilotBase(uint16_t pilotBase)
{
    write<uint16_t>("pilot_base", pilotBase);
}

uint16_t DmVersionResponse::getSid()
{
    return read<uint16_t>(getFieldOffset("sid"));
}
                

void DmVersionResponse::setSid(uint16_t sid)
{
    write<uint16_t>("sid", sid);
}

uint16_t DmVersionResponse::getNid()
{
    return read<uint16_t>(getFieldOffset("nid"));
}
                

void DmVersionResponse::setNid(uint16_t nid)
{
    write<uint16_t>("nid", nid);
}

uint16_t DmVersionResponse::getLocationId()
{
    return read<uint16_t>(getFieldOffset("location_id"));
}
                

void DmVersionResponse::setLocationId(uint16_t locationId)
{
    write<uint16_t>("location_id", locationId);
}

uint16_t DmVersionResponse::getRssiLevel()
{
    return read<uint16_t>(getFieldOffset("rssi_level"));
}
                

void DmVersionResponse::setRssiLevel(uint16_t rssiLevel)
{
    write<uint16_t>("rssi_level", rssiLevel);
}

uint8_t DmVersionResponse::getPower()
{
    return read<uint8_t>(getFieldOffset("power"));
}
                

void DmVersionResponse::setPower(uint8_t power)
{
    write<uint8_t>("power", power);
}

void DmVersionResponse::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmPacket::unpack(data, transport);
	setDemod(read<uint8_t>(data, getFieldOffset("demod")));
	setDecode(read<uint8_t>(data, getFieldOffset("decode")));
	setInterleaverId(read<uint8_t>(data, getFieldOffset("interleaver_id")));
	setEsn(read<uint32_t>(data, getFieldOffset("esn")));
	setRmMode(read<uint16_t>(data, getFieldOffset("rm_mode")));
	//uint8_t[]
	//uint8_t[]
	setMinIndex(read<uint8_t>(data, getFieldOffset("min_index")));
	setCdmaRmState(read<uint16_t>(data, getFieldOffset("cdma_rm_state")));
	setCdmaGoodFrames(read<uint8_t>(data, getFieldOffset("cdma_good_frames")));
	setAnalogCorrectFrames(read<uint16_t>(data, getFieldOffset("analog_correct_frames")));
	setAnalogBadFrames(read<uint16_t>(data, getFieldOffset("analog_bad_frames")));
	setAnalogWordSyncs(read<uint16_t>(data, getFieldOffset("analog_word_syncs")));
	setEntryReason(read<uint16_t>(data, getFieldOffset("entry_reason")));
	setCurrentChannel(read<uint16_t>(data, getFieldOffset("current_channel")));
	setCdmaCodeChannel(read<uint8_t>(data, getFieldOffset("cdma_code_channel")));
	setPilotBase(read<uint16_t>(data, getFieldOffset("pilot_base")));
	setSid(read<uint16_t>(data, getFieldOffset("sid")));
	setNid(read<uint16_t>(data, getFieldOffset("nid")));
	setLocationId(read<uint16_t>(data, getFieldOffset("location_id")));
	setRssiLevel(read<uint16_t>(data, getFieldOffset("rssi_level")));
	setPower(read<uint8_t>(data, getFieldOffset("power")));
}
