/**
* LICENSE PLACEHOLDER
*
* @file dm_efs_close_file_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_close_file_request.h"

using namespace OpenPST::QC;

DmEfsCloseFileRequest::DmEfsCloseFileRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("fp", kPacketFieldTypePrimitive, sizeof(uint32_t));

}

DmEfsCloseFileRequest::~DmEfsCloseFileRequest()
{

}

uint32_t DmEfsCloseFileRequest::getFp()
{
    return read<uint32_t>(getFieldOffset("fp"));
}
                
void DmEfsCloseFileRequest::setFp(uint32_t fp)
{
    write<uint32_t>("fp", fp);
}

void DmEfsCloseFileRequest::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
