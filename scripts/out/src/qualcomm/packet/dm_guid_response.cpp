#include "/.h"

DmGuidResponse::DmGuidResponse() : DmPacket()
{
	addField("guid", kPacketFieldTypeArray, 16);
}

DmGuidResponse::~DmGuidResponse()
{

}

std::vector<uint8_t> DmGuidResponse::getGuid()
{
	return read(getFieldSize("guid"), getFieldOffset("guid"));
}
std::string DmGuidResponse::getGuid()
{
	return read(16, getFieldOffset("guid"));
}
                
void DmGuidResponse::setGuid(uint8_t* data, size_t size);
{
    write("guid", data, size);
}
void DmGuidResponse::setGuid(const std::string& guid);
{
    write("guid", guid);
}
