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

#include "transport/packet.h"

using namespace OpenPST::Transport;

Packet::Packet(size_t maxDataSize) : maxDataSize(maxDataSize)
{
	if (maxDataSize > 0) {
		data.reserve(maxDataSize);
	}
}

Packet::Packet(PacketEndianess targetEndianess, size_t maxDataSize) : endianT(targetEndianess), maxDataSize(maxDataSize)
{
	if (maxDataSize > 0) {
		data.reserve(maxDataSize);
	}
}


Packet::~Packet(){
	if (response != nullptr) {
		delete response;
	}
}

void Packet::setTargetEndianess(PacketEndianess e) {
	/*if (e != endianT && e != getHostEndianess()) {
		// flip shorts and larger but not arrays or dynamic sized data
		for (auto &field : fieldMeta) {
			if (field.type == kPacketFieldTypePrimitive && field.size > sizeof(uint8_t)) {
				write(field, )
			}
		}
	}*/
	endianT = e;
}

PacketEndianess Packet::getTargetEndianess() {
	return endianT;
}


PacketEndianess Packet::getHostEndianess() {
	uint16_t test = 0x0102;
	return reinterpret_cast<uint8_t*>(&test)[0] == 0x02 ? 
		kPacketEndianessLittle : kPacketEndianessBig;
}

PacketTargetArch Packet::getTargetArch()
{
	return archT;
}

void Packet::setTargetArch(PacketTargetArch arch)
{
	archT = arch;
}

bool Packet::isResponseExpected()
{
	return responseExpected;
}

void Packet::setResponseExpected(bool v)
{
	responseExpected = v;
}

Packet* Packet::getResponse() {
	return response;
}

size_t Packet::getMaxDataSize()
{
	return 0;
}

void Packet::addField(const std::string& name, PacketFieldType type, size_t size)
{
	PacketFieldMeta field;
	field.type   = type;
	field.name   = name;
	field.size   = size;
	
	addField(field);
}

bool Packet::hasField(const std::string& name)
{
	for (auto &f : fieldMeta) {
		if (f.name.compare(name) == 0) {
			return true;
		}
	}

	return false;
}

bool Packet::hasField(int index)
{
	int i = 0;
	for (auto &f : fieldMeta) {
		if (i == index) {
			return true;
		}
		i++;
	}

	return false;
}


PacketFieldMeta* Packet::getField(const std::string& name)
{
	for (auto &f : fieldMeta) {
		if (f.name.compare(name) == 0) {
			return &f;
		}
	}
	
	throw PacketInvalidArgument("Field not found");
}

PacketFieldMeta* Packet::getField(int index)
{
	int i = 0;
	for (auto &f : fieldMeta) {
		if (i == index) {
			return &f;
		}
		i++;
	}
	
	throw PacketInvalidArgument("Field not found");
}

void Packet::addField(PacketFieldMeta field)
{
	if (!field.size && field.type != kPacketFieldTypeVariant) {
		throw PacketInvalidArgument("Invalid field size");
	} else if ( kPacketFieldTypeLast <= field.type) {
		throw PacketInvalidArgument("Invalid field type");
	} else if (!field.name.size()) {
		throw PacketInvalidArgument("Field name must be set");
	} else if(hasField(field.name)) {
		throw PacketInvalidArgument("Field already exists");
	}
	
	if (field.size > 0) {
        // fill in zero'ed data
        data.insert(data.begin() + getFieldMetaSize(), field.size, 0x00);
    }
	
	fieldMeta.push_back(field);
}

const std::vector<PacketFieldMeta>& Packet::getFields()
{
	return fieldMeta;
}

size_t Packet::size()
{
	return data.size();
}

size_t Packet::getFieldMetaSize()
{
	size_t ret = 0;
	for (auto &f : fieldMeta) {
		ret += f.size;
	}
	return ret;
}

std::vector<uint8_t>& Packet::getData()
{
	return data;
}

