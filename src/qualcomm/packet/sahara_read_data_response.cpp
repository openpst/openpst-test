/**
* LICENSE PLACEHOLDER
*
* @file sahara_read_data_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_read_data_response.h"

using namespace OpenPST::QC;

SaharaReadDataResponse::SaharaReadDataResponse() : Packet()
{
	addField("data", kPacketFieldTypeVariant, 0);

	setCommand(kSaharaCommandReadData);
}

SaharaReadDataResponse::~SaharaReadDataResponse()
{

}

std::vector<uint8_t> SaharaReadDataResponse::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
std::string SaharaReadDataResponse::getData()
{
	return getString(0, getFieldOffset("data"));
}
                
void SaharaReadDataResponse::setData(std::ifstream& file, size_t size)
{
    write("data", file, size);
}
void SaharaReadDataResponse::setData(uint8_t* data, size_t size);
{
    write("data", data, size);
}
void SaharaReadDataResponse::setData(const std::string& data)
{
    write("data", data);
}

void SaharaReadDataResponse::unpack(std::vector<uint8_t>& data)
{
}
