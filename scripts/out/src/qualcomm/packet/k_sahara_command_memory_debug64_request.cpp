/**
* LICENSE PLACEHOLDER
*
* @file k_sahara_command_memory_debug64_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/k_sahara_command_memory_debug64_request.h"

kSaharaCommandMemoryDebug64Request::kSaharaCommandMemoryDebug64Request() : SaharaPacket()
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint64_t));

	setCommand(kSaharaCommandMemoryRead64);
}

kSaharaCommandMemoryDebug64Request::~kSaharaCommandMemoryDebug64Request()
{

}

uint64_t kSaharaCommandMemoryDebug64Request::getClientCommand()
{
    return read<uint64_t>(getFieldOffset("client_command"));
}
                
void kSaharaCommandMemoryDebug64Request::setClientCommand(uint64_t clientCommand)
{
    write<uint64_t>("client_command", clientCommand);
}

void kSaharaCommandMemoryDebug64Request::unpack(std::vector<uint8_t>& data)
{
	
}