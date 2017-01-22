#include "serial/packet_test.h"

using namespace OpenPST::Serial;

PacketTest::PacketTest() : 
StreamingDloadPacket()
{
    addField("magic", kPacketFieldTypeArray, STREAMING_DLOAD_MAGIC_SIZE);
    addField("version", kPacketFieldTypePrimitive, sizeof(uint8_t));
    addField("compatible_version", kPacketFieldTypePrimitive, sizeof(uint8_t));
    addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint8_t));
    
    // set the defaults
    setCommand(kStreamingDloadHello);
    setMagic("QCOM fast download protocol host");
    setVersion(0x01);    
    setCompatibleVersion(0x02);    
    setVersion(0x03); 
    setFeatureBits(0x19);
}
 
PacketTest::~PacketTest()
{

}

void PacketTest::setMagic(const std::string& magic)
{
	if (!magic.size()) {
		throw std::invalid_argument("Magic was empty");
	} else if (magic.size() > STREAMING_DLOAD_MAGIC_SIZE) {
		throw std::invalid_argument("Magic exceeds max size");
	}

	size_t offset = getFieldOffset("magic");

	for (int i = 0; i < magic.size(); i++) {
		write<uint8_t>(magic[i], offset + i);
	}
}

std::string PacketTest::getMagic()
{
	std::string ret = "";
	size_t offset = getFieldOffset("magic");
	for (int i = 0; i < STREAMING_DLOAD_MAGIC_SIZE; i++) {
		if (read<uint8_t>(offset + i) == 0x00) break;
		ret += read<uint8_t>(offset + i);
	}

	return ret;
}

void PacketTest::setVersion(uint8_t version)
{
	write<uint8_t>(version, getFieldOffset("version"));
}

uint8_t PacketTest::getVersion()
{
	return read<uint8_t>(getFieldOffset("version"));
}

void PacketTest::setCompatibleVersion(uint8_t compatibleVersion)
{
	write<uint8_t>(compatibleVersion, getFieldOffset("compatible_version"));
}

uint8_t PacketTest::getCompatibleVersion()
{
	return read<uint8_t>(getFieldOffset("compatible_version"));
}

void PacketTest::setFeatureBits(uint8_t featureBits)
{
	write<uint8_t>(featureBits, getFieldOffset("feature_bits"));
}

uint8_t PacketTest::getFeatureBits()
{
	return read<uint8_t>(getFieldOffset("feature_bits"));
}