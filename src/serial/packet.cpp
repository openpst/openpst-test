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

bool Packet::getResponseExpected()
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

void Packet::write(uint8_t* src, size_t amount, size_t offset)
{
    if (data.size() < offset + amount) {
        data.resize(data.size() + (data.size() - offset) + amount);
        std::cout << "NEW SIZE (raw): " << data.size() << std::endl;
    }
    
    data.insert(data.begin() + offset, src, src + amount);
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

PacketFieldMeta* Packet::getField(const std::string& name)
{
	for (auto &f : fieldMeta) {
		if (f.name.compare(name) == 0) {
			return &f;
		}
	}
	
	throw std::invalid_argument("Field not found");
}

void Packet::addField(PacketFieldMeta field)
{
	if (!field.size) {
		throw std::invalid_argument("Invalid field size");
	} else if ( kPacketFieldTypeLast <= field.type) {
		throw std::invalid_argument("Invalid field type");
	} else if (!field.name.size()) {
		throw std::invalid_argument("Field name must be set");
	}

	data.resize(data.size() + field.size, 0);

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

 const std::vector<uint8_t>& Packet::getData()
 {
 	return data;
 }
