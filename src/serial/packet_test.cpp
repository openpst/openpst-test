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
    setVersion(0x05);    
    setCompatibleVersion(0x02);    
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

	write(magic, getFieldOffset("magic"));
}

std::string PacketTest::getMagic()
{
	return read()
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