#include "serial/packet.h"

using namespace OpenPST::Serial;

Packet::Packet(size_t maxDataSize) : maxDataSize(maxDataSize)
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
	/*if (e != getHostEndianess()) {
		// flip shorts and larger
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

void Packet::setHostEndianess(PacketEndianess e) {
	endianH = e;
}

PacketEndianess Packet::getHostEndianess() {
	return endianH;
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

