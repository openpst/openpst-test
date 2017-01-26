/**
* LICENSE PLACEHOLDER
*
* @file dm_spc_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_spc_request.h"

DmSpcRequest::DmSpcRequest() : DmPacket()
{
	addField("spc", kPacketFieldTypePrimitive, sizeof(uint8_t[]));

}

DmSpcRequest::~DmSpcRequest()
{

}

std::vector<uint8_t> DmSpcRequest::getSpc()
{
	return read(getFieldSize("spc"), getFieldOffset("spc"));
}
std::string DmSpcRequest::getSpc()
{
	return read(6, getFieldOffset("spc"));
}
                
void DmSpcRequest::setSpc(uint8_t* data, size_t size);
{
    write("spc", data, size);
}
void DmSpcRequest::setSpc(const std::string& spc);
{
    write("spc", spc);
}

void DmSpcRequest::unpack(std::vector<uint8_t>& data)
{
	
}