#include "/.h"

DmSpcRequest::DmSpcRequest() : DmPacket()
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
