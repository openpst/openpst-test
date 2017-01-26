#include "/.h"

SaharaReadDataResponse::SaharaReadDataResponse() : Packet()
{
	addField("data", kPacketFieldTypeVariant, 0);
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
	return read(0, getFieldOffset("data"));
}
                
void SaharaReadDataResponse::setData(std::ifstream& file, size_t size);
{
    write("data", file, size);
}
void SaharaReadDataResponse::setData(uint8_t* data, size_t size);
{
    write("data", data, size);
}
void SaharaReadDataResponse::setData(const std::string& data);
{
    write("data", data);
}
