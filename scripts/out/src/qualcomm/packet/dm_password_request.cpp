/**
* LICENSE PLACEHOLDER
*
* @file dm_password_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_password_request.h"

using namespace OpenPST::QC;

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
	return readString(8, getFieldOffset("password"));
}
                
void DmPasswordRequest::setPassword(uint8_t* data, size_t size)
{
    write("password", data, size);
}
void DmPasswordRequest::setPassword(const std::string& password)
{
    write("password", password);
}

void DmPasswordRequest::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}

