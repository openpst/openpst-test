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
* @file laf_packet.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/14/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "lg/packet/laf_packet.h"

using namespace OpenPST::LG;

LafPacket::LafPacket(PacketEndianess targetEndian) : Packet(targetEndian)
{
	addField("command", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("arg0", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("arg1", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("arg_opt0", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("arg_opt1", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("crc", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("magic", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 2);

	setResponseExpected(true);
}

LafPacket::~LafPacket()
{

}

uint32_t LafPacket::getCommand()
{
    return read<uint32_t>(getFieldOffset("command"));
}
                

void LafPacket::setCommand(uint32_t command)
{
    write<uint32_t>("command", command);
}

uint32_t LafPacket::getArg0()
{
    return read<uint32_t>(getFieldOffset("arg0"));
}
                

void LafPacket::setArg0(uint32_t arg0)
{
    write<uint32_t>("arg0", arg0);
}

uint32_t LafPacket::getArg1()
{
    return read<uint32_t>(getFieldOffset("arg1"));
}
                

void LafPacket::setArg1(uint32_t arg1)
{
    write<uint32_t>("arg1", arg1);
}

uint32_t LafPacket::getArgOpt0()
{
    return read<uint32_t>(getFieldOffset("arg_opt0"));
}
                

void LafPacket::setArgOpt0(uint32_t argOpt0)
{
    write<uint32_t>("arg_opt0", argOpt0);
}

uint32_t LafPacket::getArgOpt1()
{
    return read<uint32_t>(getFieldOffset("arg_opt1"));
}
                

void LafPacket::setArgOpt1(uint32_t argOpt1)
{
    write<uint32_t>("arg_opt1", argOpt1);
}

uint32_t LafPacket::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                

void LafPacket::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

uint32_t LafPacket::getCrc()
{
    return read<uint32_t>(getFieldOffset("crc"));
}
                

void LafPacket::setCrc(uint32_t crc)
{
    write<uint32_t>("crc", crc);
}

uint32_t LafPacket::getMagic()
{
    return read<uint32_t>(getFieldOffset("magic"));
}
                

void LafPacket::setMagic(uint32_t magic)
{
    write<uint32_t>("magic", magic);
}

std::vector<uint8_t> LafPacket::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                

void LafPacket::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void LafPacket::prepareResponse()
{
	if (response == nullptr) {
		LafPacket* resp = new LafPacket();
		response = resp;
	}
}

void LafPacket::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	setCommand(read<uint32_t>(data, getFieldOffset("command")));
	setArg0(read<uint32_t>(data, getFieldOffset("arg0")));
	setArg1(read<uint32_t>(data, getFieldOffset("arg1")));
	setArgOpt0(read<uint32_t>(data, getFieldOffset("arg_opt0")));
	setArgOpt1(read<uint32_t>(data, getFieldOffset("arg_opt1")));
	setSize(read<uint32_t>(data, getFieldOffset("size")));
	setCrc(read<uint32_t>(data, getFieldOffset("crc")));
	setMagic(read<uint32_t>(data, getFieldOffset("magic")));
	//variable
}
