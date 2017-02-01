/**
* LICENSE PLACEHOLDER
*
* @file sahara_command_memory_debug64_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_command_memory_debug64_request.h"

using namespace OpenPST::QC;

SaharaCommandMemoryDebug64Request::SaharaCommandMemoryDebug64Request(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint64_t));

	setCommand(kSaharaCommandMemoryRead64);
}

SaharaCommandMemoryDebug64Request::~SaharaCommandMemoryDebug64Request()
{

}

uint64_t SaharaCommandMemoryDebug64Request::getClientCommand()
{
    return read<uint64_t>(getFieldOffset("client_command"));
}
                
void SaharaCommandMemoryDebug64Request::setClientCommand(uint64_t clientCommand)
{
    write<uint64_t>("client_command", clientCommand);
}

void SaharaCommandMemoryDebug64Request::unpack(std::vector<uint8_t>& data)
{
}
