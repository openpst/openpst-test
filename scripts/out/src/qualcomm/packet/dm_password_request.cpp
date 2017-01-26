#include "/.h"

DmPasswordRequest::DmPasswordRequest() : DmPacket()
{
	addField("password", kPacketFieldTypeArray, DIAG_PASSWORD_LENGTH);
}

DmPasswordRequest::~DmPasswordRequest()
{

}

std::vector<uint8_t> DmPasswordRequest::getPassword()
{
	return read(getFieldSize("password"), getFieldOffset("password"));
}
std::string DmPasswordRequest::getPassword()
{
	return read(8, getFieldOffset("password"));
}
                
void DmPasswordRequest::setPassword(uint8_t* data, size_t size);
{
    write("password", data, size);
}
void DmPasswordRequest::setPassword(const std::string& password);
{
    write("password", password);
}
