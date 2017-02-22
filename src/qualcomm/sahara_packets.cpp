/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_client_command_execute_data_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_client_command_execute_data_request.h"

using namespace OpenPST::Qualcomm;

SaharaClientCommandExecuteDataRequest::SaharaClientCommandExecuteDataRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandExecuteData);
}

SaharaClientCommandExecuteDataRequest::~SaharaClientCommandExecuteDataRequest()
{

}

uint32_t SaharaClientCommandExecuteDataRequest::getClientCommand()
{
    return read<uint32_t>(getFieldOffset("client_command"));
}
                
void SaharaClientCommandExecuteDataRequest::setClientCommand(uint32_t clientCommand)
{
    write<uint32_t>("client_command", clientCommand);
}

void SaharaClientCommandExecuteDataRequest::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_reset_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_reset_response.h"

using namespace OpenPST::Qualcomm;

SaharaResetResponse::SaharaResetResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{

	setCommand(kSaharaCommandResetResponse);
}

SaharaResetResponse::~SaharaResetResponse()
{

}


void SaharaResetResponse::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_read_data_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_read_data_request.h"

using namespace OpenPST::Qualcomm;

SaharaReadDataRequest::SaharaReadDataRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
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

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_switch_mode_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_switch_mode_request.h"

using namespace OpenPST::Qualcomm;

SaharaSwitchModeRequest::SaharaSwitchModeRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandSwitchMode);
}

SaharaSwitchModeRequest::~SaharaSwitchModeRequest()
{

}

uint32_t SaharaSwitchModeRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void SaharaSwitchModeRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}

void SaharaSwitchModeRequest::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_read_data_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_read_data_response.h"

using namespace OpenPST::Qualcomm;

SaharaReadDataResponse::SaharaReadDataResponse(PacketEndianess targetEndian) : Packet(targetEndian)
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
void SaharaReadDataResponse::setData(uint8_t* data, size_t size)
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

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_end_image_transfer_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_end_image_transfer_response.h"

using namespace OpenPST::Qualcomm;

SaharaEndImageTransferResponse::SaharaEndImageTransferResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("image_id", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("status", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandEndImageTransfer);
}

SaharaEndImageTransferResponse::~SaharaEndImageTransferResponse()
{

}

uint32_t SaharaEndImageTransferResponse::getImageId()
{
    return read<uint32_t>(getFieldOffset("image_id"));
}
                
void SaharaEndImageTransferResponse::setImageId(uint32_t imageId)
{
    write<uint32_t>("image_id", imageId);
}
uint32_t SaharaEndImageTransferResponse::getStatus()
{
    return read<uint32_t>(getFieldOffset("status"));
}
                
void SaharaEndImageTransferResponse::setStatus(uint32_t status)
{
    write<uint32_t>("status", status);
}

void SaharaEndImageTransferResponse::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_done_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_done_response.h"

using namespace OpenPST::Qualcomm;

SaharaDoneResponse::SaharaDoneResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{

	setCommand(kSaharaCommandDoneResponse);
}

SaharaDoneResponse::~SaharaDoneResponse()
{

}


void SaharaDoneResponse::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_memory_debug64_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_debug64_request.h"

using namespace OpenPST::Qualcomm;

SaharaMemoryDebug64Request::SaharaMemoryDebug64Request(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandMemoryDebug64Request);
}

SaharaMemoryDebug64Request::~SaharaMemoryDebug64Request()
{

}

uint32_t SaharaMemoryDebug64Request::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void SaharaMemoryDebug64Request::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint32_t SaharaMemoryDebug64Request::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaMemoryDebug64Request::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaMemoryDebug64Request::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_done_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_done_request.h"

using namespace OpenPST::Qualcomm;

SaharaDoneRequest::SaharaDoneRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{

	setCommand(kSaharaCommandDone);
}

SaharaDoneRequest::~SaharaDoneRequest()
{

}


void SaharaDoneRequest::unpack(std::vector<uint8_t>& data)
{
}
void SaharaDoneRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaDoneResponse* resp = new SaharaDoneResponse();
		response = resp;
	}
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_memory_read_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_read_request.h"

using namespace OpenPST::Qualcomm;

SaharaMemoryReadRequest::SaharaMemoryReadRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandMemoryRead);
}

SaharaMemoryReadRequest::~SaharaMemoryReadRequest()
{

}

uint32_t SaharaMemoryReadRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void SaharaMemoryReadRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint32_t SaharaMemoryReadRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaMemoryReadRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaMemoryReadRequest::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_memory_debug_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_debug_request.h"

using namespace OpenPST::Qualcomm;

SaharaMemoryDebugRequest::SaharaMemoryDebugRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandMemoryDebug);
}

SaharaMemoryDebugRequest::~SaharaMemoryDebugRequest()
{

}

uint32_t SaharaMemoryDebugRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void SaharaMemoryDebugRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint32_t SaharaMemoryDebugRequest::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaMemoryDebugRequest::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaMemoryDebugRequest::unpack(std::vector<uint8_t>& data)
{
}
void SaharaMemoryDebugRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaMemoryReadRequest* resp = new SaharaMemoryReadRequest();
		response = resp;
	}
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_command_ready_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_command_ready_response.h"

using namespace OpenPST::Qualcomm;

SaharaCommandReadyResponse::SaharaCommandReadyResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("image_tx_status", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandReady);
}

SaharaCommandReadyResponse::~SaharaCommandReadyResponse()
{

}

uint32_t SaharaCommandReadyResponse::getImageTxStatus()
{
    return read<uint32_t>(getFieldOffset("image_tx_status"));
}
                
void SaharaCommandReadyResponse::setImageTxStatus(uint32_t imageTxStatus)
{
    write<uint32_t>("image_tx_status", imageTxStatus);
}

void SaharaCommandReadyResponse::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_client_command_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_client_command_request.h"

using namespace OpenPST::Qualcomm;

SaharaClientCommandRequest::SaharaClientCommandRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandExecute);
}

SaharaClientCommandRequest::~SaharaClientCommandRequest()
{

}

uint32_t SaharaClientCommandRequest::getClientCommand()
{
    return read<uint32_t>(getFieldOffset("client_command"));
}
                
void SaharaClientCommandRequest::setClientCommand(uint32_t clientCommand)
{
    write<uint32_t>("client_command", clientCommand);
}

void SaharaClientCommandRequest::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_reset_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_reset_request.h"

using namespace OpenPST::Qualcomm;

SaharaResetRequest::SaharaResetRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{

	setCommand(kSaharaCommandReset);
}

SaharaResetRequest::~SaharaResetRequest()
{

}


void SaharaResetRequest::unpack(std::vector<uint8_t>& data)
{
}
void SaharaResetRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaResetResponse* resp = new SaharaResetResponse();
		response = resp;
	}
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_client_command_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_client_command_response.h"

using namespace OpenPST::Qualcomm;

SaharaClientCommandResponse::SaharaClientCommandResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("client_command", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandExecuteResponse);
}

SaharaClientCommandResponse::~SaharaClientCommandResponse()
{

}

uint32_t SaharaClientCommandResponse::getClientCommand()
{
    return read<uint32_t>(getFieldOffset("client_command"));
}
                
void SaharaClientCommandResponse::setClientCommand(uint32_t clientCommand)
{
    write<uint32_t>("client_command", clientCommand);
}
uint32_t SaharaClientCommandResponse::getSize()
{
    return read<uint32_t>(getFieldOffset("size"));
}
                
void SaharaClientCommandResponse::setSize(uint32_t size)
{
    write<uint32_t>("size", size);
}

void SaharaClientCommandResponse::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_command_memory_debug64_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_command_memory_debug64_request.h"

using namespace OpenPST::Qualcomm;

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

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_hello_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_hello_response.h"

using namespace OpenPST::Qualcomm;

SaharaHelloResponse::SaharaHelloResponse(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("min_version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_command_packet_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("status", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("reserved", kPacketFieldTypeArray, 24);
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandHelloResponse);
}

SaharaHelloResponse::~SaharaHelloResponse()
{

}

uint32_t SaharaHelloResponse::getVersion()
{
    return read<uint32_t>(getFieldOffset("version"));
}
                
void SaharaHelloResponse::setVersion(uint32_t version)
{
    write<uint32_t>("version", version);
}
uint32_t SaharaHelloResponse::getMinVersion()
{
    return read<uint32_t>(getFieldOffset("min_version"));
}
                
void SaharaHelloResponse::setMinVersion(uint32_t minVersion)
{
    write<uint32_t>("min_version", minVersion);
}
uint32_t SaharaHelloResponse::getMaxCommandPacketSize()
{
    return read<uint32_t>(getFieldOffset("max_command_packet_size"));
}
                
void SaharaHelloResponse::setMaxCommandPacketSize(uint32_t maxCommandPacketSize)
{
    write<uint32_t>("max_command_packet_size", maxCommandPacketSize);
}
uint32_t SaharaHelloResponse::getStatus()
{
    return read<uint32_t>(getFieldOffset("status"));
}
                
void SaharaHelloResponse::setStatus(uint32_t status)
{
    write<uint32_t>("status", status);
}
std::vector<uint8_t> SaharaHelloResponse::getReserved()
{
	return read(getFieldSize("reserved"), getFieldOffset("reserved"));
}
                
void SaharaHelloResponse::setReserved(uint8_t* data, size_t size)
{
    write("reserved", data, size);
}
uint32_t SaharaHelloResponse::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void SaharaHelloResponse::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}

void SaharaHelloResponse::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_memory_read64_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_memory_read64_request.h"

using namespace OpenPST::Qualcomm;

SaharaMemoryRead64Request::SaharaMemoryRead64Request(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint64_t));
	addField("size", kPacketFieldTypePrimitive, sizeof(uint64_t));

	setCommand(kSaharaCommandMemoryDebug64);
}

SaharaMemoryRead64Request::~SaharaMemoryRead64Request()
{

}

uint64_t SaharaMemoryRead64Request::getAddress()
{
    return read<uint64_t>(getFieldOffset("address"));
}
                
void SaharaMemoryRead64Request::setAddress(uint64_t address)
{
    write<uint64_t>("address", address);
}
uint64_t SaharaMemoryRead64Request::getSize()
{
    return read<uint64_t>(getFieldOffset("size"));
}
                
void SaharaMemoryRead64Request::setSize(uint64_t size)
{
    write<uint64_t>("size", size);
}

void SaharaMemoryRead64Request::unpack(std::vector<uint8_t>& data)
{
}

/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file sahara_hello_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/sahara_hello_request.h"

using namespace OpenPST::Qualcomm;

SaharaHelloRequest::SaharaHelloRequest(PacketEndianess targetEndian) : SaharaPacket(targetEndian)
{
	addField("version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("min_version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_command_packet_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("status", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("reserved", kPacketFieldTypeArray, 24);
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kSaharaCommandHello);
}

SaharaHelloRequest::~SaharaHelloRequest()
{

}

uint32_t SaharaHelloRequest::getVersion()
{
    return read<uint32_t>(getFieldOffset("version"));
}
                
void SaharaHelloRequest::setVersion(uint32_t version)
{
    write<uint32_t>("version", version);
}
uint32_t SaharaHelloRequest::getMinVersion()
{
    return read<uint32_t>(getFieldOffset("min_version"));
}
                
void SaharaHelloRequest::setMinVersion(uint32_t minVersion)
{
    write<uint32_t>("min_version", minVersion);
}
uint32_t SaharaHelloRequest::getMaxCommandPacketSize()
{
    return read<uint32_t>(getFieldOffset("max_command_packet_size"));
}
                
void SaharaHelloRequest::setMaxCommandPacketSize(uint32_t maxCommandPacketSize)
{
    write<uint32_t>("max_command_packet_size", maxCommandPacketSize);
}
uint32_t SaharaHelloRequest::getStatus()
{
    return read<uint32_t>(getFieldOffset("status"));
}
                
void SaharaHelloRequest::setStatus(uint32_t status)
{
    write<uint32_t>("status", status);
}
std::vector<uint8_t> SaharaHelloRequest::getReserved()
{
	return read(getFieldSize("reserved"), getFieldOffset("reserved"));
}
                
void SaharaHelloRequest::setReserved(uint8_t* data, size_t size)
{
    write("reserved", data, size);
}
uint32_t SaharaHelloRequest::getMode()
{
    return read<uint32_t>(getFieldOffset("mode"));
}
                
void SaharaHelloRequest::setMode(uint32_t mode)
{
    write<uint32_t>("mode", mode);
}

void SaharaHelloRequest::unpack(std::vector<uint8_t>& data)
{
}
void SaharaHelloRequest::prepareResponse()
{
	if (response == nullptr) {
		SaharaHelloResponse* resp = new SaharaHelloResponse();
		response = resp;
	}
}
