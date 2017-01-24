#include "serial/packet_test.h"
#include "util/hexdump.h"

using namespace OpenPST::Serial;

PacketTest::PacketTest() : 
StreamingDloadPacket()
{
    addField("magic", kPacketFieldTypeArray, STREAMING_DLOAD_MAGIC_SIZE);
    addField("version", kPacketFieldTypePrimitive, sizeof(uint8_t));
    addField("compatible_version", kPacketFieldTypePrimitive, sizeof(uint8_t));
    addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint8_t));
    addField("dtest", kPacketFieldTypeVariant, 0);    
    addField("feature_bits2", kPacketFieldTypePrimitive, sizeof(uint8_t));

	std::cout << "Packet defines the following fields:" << std::endl;

	for (auto &f : getFields()) {
		std::cout << "\t" << f.name << " size: " << f.size << std::endl;
	}

	std::cout << std::endl;

    std::cout << "Dump before values: " << size() << std::endl;
    hexdump((uint8_t*)&data[0], data.size());

    //addField("feature_bits2", kPacketFieldTypePrimitive, sizeof(uint8_t));

    // set the defaults
    setCommand(kStreamingDloadHello);
    setMagic("QCOM fast download protocol host");
    setVersion(0x05);    
    setCompatibleVersion(0x02);    
    setFeatureBits(
    	STREAMING_DLOAD_FEATURE_BIT_UNCOMPRESSED_DOWNLOAD | STREAMING_DLOAD_FEATURE_BIT_NAND_BOOTABLE_IMAGE | 
		STREAMING_DLOAD_FEATURE_BIT_NAND_BOOT_LOADER | STREAMING_DLOAD_FEATURE_BIT_MULTI_IMAGE |
		STREAMING_DLOAD_FEATURE_BIT_SECTOR_ADDRESSES
	);
    setFeatureBits2(0xAA);


    std::cout << "Dump after defaults: " << size() << std::endl;
    hexdump((uint8_t*)&data[0], data.size());
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

	write("magic", magic);
}

std::string PacketTest::getMagic()
{
	return read(STREAMING_DLOAD_MAGIC_SIZE, getFieldOffset("magic"));
}

void PacketTest::setVersion(uint8_t version)
{
	write<uint8_t>("version", version);
}

uint8_t PacketTest::getVersion()
{
	return read<uint8_t>(getFieldOffset("version"));
}

void PacketTest::setCompatibleVersion(uint8_t compatibleVersion)
{
	write<uint8_t>("compatible_version", compatibleVersion);
}

uint8_t PacketTest::getCompatibleVersion()
{
	return read<uint8_t>(getFieldOffset("compatible_version"));
}

void PacketTest::setFeatureBits(uint8_t featureBits)
{
	write<uint8_t>("feature_bits", featureBits);
}

uint8_t PacketTest::getFeatureBits()
{
	return read<uint8_t>(getFieldOffset("feature_bits"));
}

void PacketTest::setDtest(std::ifstream& file, size_t size)
{
    write("dtest", file, size);
}

void PacketTest::setFeatureBits2(uint8_t featureBits2)
{
	write<uint8_t>("feature_bits2", featureBits2);
}
