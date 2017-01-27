#include "qualcomm/packet/streaming_dload_hello_request.h"

using namespace OpenPST::QC;

StreamingDloadHelloRequest::StreamingDloadHelloRequest() : 
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
    setFeatureBits(
    	STREAMING_DLOAD_FEATURE_BIT_UNCOMPRESSED_DOWNLOAD | STREAMING_DLOAD_FEATURE_BIT_NAND_BOOTABLE_IMAGE | 
		STREAMING_DLOAD_FEATURE_BIT_NAND_BOOT_LOADER | STREAMING_DLOAD_FEATURE_BIT_MULTI_IMAGE |
		STREAMING_DLOAD_FEATURE_BIT_SECTOR_ADDRESSES
	);
}

StreamingDloadHelloRequest::~StreamingDloadHelloRequest()
{

}

void StreamingDloadHelloRequest::setMagic(const std::string& magic)
{
	if (!magic.size()) {
		throw std::invalid_argument("Magic was empty");
	} else if (magic.size() > STREAMING_DLOAD_MAGIC_SIZE) {
		throw std::invalid_argument("Magic exceeds max size");
	}

	write("magic", magic);
}

std::string StreamingDloadHelloRequest::getMagic()
{
	return read(STREAMING_DLOAD_MAGIC_SIZE, getFieldOffset("magic"));
}

void StreamingDloadHelloRequest::setVersion(uint8_t version)
{
	write<uint8_t>("version", version);
}

uint8_t StreamingDloadHelloRequest::getVersion()
{
	return read<uint8_t>(getFieldOffset("version"));
}

void StreamingDloadHelloRequest::setCompatibleVersion(uint8_t compatibleVersion)
{
	write<uint8_t>("compatible_version", compatibleVersion);
}

uint8_t StreamingDloadHelloRequest::getCompatibleVersion()
{
	return read<uint8_t>(getFieldOffset("compatible_version"));
}

void StreamingDloadHelloRequest::setFeatureBits(uint8_t featureBits)
{
	write<uint8_t>("feature_bits", featureBits);
}

uint8_t StreamingDloadHelloRequest::getFeatureBits()
{
	return read<uint8_t>(getFieldOffset("feature_bits"));
}

void StreamingDloadHelloRequest::unpack(std::vector<uint8_t>& data)  {
                    
}