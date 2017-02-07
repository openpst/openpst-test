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

using namespace OpenPST::QC;

DmSpcRequest::DmSpcRequest(PacketEndianess targetEndian) : DmPacket(targetEndian)
{
	addField("spc", kPacketFieldTypeArray, DIAG_SPC_LENGTH);

}

DmSpcRequest::~DmSpcRequest()
{

}

std::vector<uint8_t> DmSpcRequest::getSpc()
{
	return read(getFieldSize("spc"), getFieldOffset("spc"));
}
                
void DmSpcRequest::setSpc(uint8_t* data, size_t size)
{
    write("spc", data, size);
}

void DmSpcRequest::unpack(std::vector<uint8_t>& data)
{
	DmPacket::unpack(data);
}
void DmSpcRequest::prepareResponse()
{
	if (response == nullptr) {
		DmSpcResponse* resp = new DmSpcResponse();
		response = resp;
	}
}
