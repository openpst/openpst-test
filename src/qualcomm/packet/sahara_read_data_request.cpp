/**
* LICENSE PLACEHOLDER
*
* @file sahara_read_data_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_read_data_request.h"

using namespace OpenPST::QC;

SaharaReadDataRequest::SaharaReadDataRequest() : SaharaPacket()
{
	addField("image_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("offset", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

SaharaReadDataRequest::~SaharaReadDataRequest()
{

}

uint32_t SaharaReadDataRequest::getImageId()
{
    return read<uint32_t>(getFieldOffset("image_id"));
}
                
void SaharaReadDataRequest::setImageId(uint32_t imageId)
{
    write<uint32_t>("image_id", imageId);
}
uint32_t SaharaReadDataRequest::getOffset()
{
    return read<uint32_t>(getFieldOffset("offset"));
}
                
void SaharaReadDataRequest::setOffset(uint32_t offset)
{
    write<uint32_t>("offset", offset);
}
uint32_t SaharaReadDataRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaReadDataRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaReadDataRequest::unpack(std::vector<uint8_t>& data)
{
}
void SaharaReadDataRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaReadDataResponse* resp = new SaharaReadDataResponse();
		response = resp;
	}
}
