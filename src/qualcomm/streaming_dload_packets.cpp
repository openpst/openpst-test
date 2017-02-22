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
* @file streaming_dload_read_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_read_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadReadResponse::StreamingDloadReadResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);

	setCommand(kStreamingDloadReadData);
}

StreamingDloadReadResponse::~StreamingDloadReadResponse()
{

}

uint32_t StreamingDloadReadResponse::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadReadResponse::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
std::vector<uint8_t> StreamingDloadReadResponse::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void StreamingDloadReadResponse::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void StreamingDloadReadResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
    
    off_t offset = 0;

    setCommand(read<uint8_t>(data, offset++));

	setAddress(read<uint32_t>(data, offset));

	offset += sizeof(uint32_t);

	setData(&data[offset], data.size() - offset);
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
* @file streaming_dload_security_mode_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_security_mode_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadSecurityModeResponse::StreamingDloadSecurityModeResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadSecurityModeReceived);
}

StreamingDloadSecurityModeResponse::~StreamingDloadSecurityModeResponse()
{

}


void StreamingDloadSecurityModeResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_nop_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_nop_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadNopResponse::StreamingDloadNopResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("identifier", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadNopResponse);
}

StreamingDloadNopResponse::~StreamingDloadNopResponse()
{

}

uint32_t StreamingDloadNopResponse::getIdentifier()
{
    return read<uint32_t>(getFieldOffset("identifier"));
}
                
void StreamingDloadNopResponse::setIdentifier(uint32_t identifier)
{
    write<uint32_t>("identifier", identifier);
}

void StreamingDloadNopResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_security_mode_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_security_mode_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadSecurityModeRequest::StreamingDloadSecurityModeRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadSecurityMode);
}

StreamingDloadSecurityModeRequest::~StreamingDloadSecurityModeRequest()
{

}

uint8_t StreamingDloadSecurityModeRequest::getMode()
{
    return read<uint8_t>(getFieldOffset("mode"));
}
                
void StreamingDloadSecurityModeRequest::setMode(uint8_t mode)
{
    write<uint8_t>("mode", mode);
}

void StreamingDloadSecurityModeRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadSecurityModeRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadSecurityModeResponse* resp = new StreamingDloadSecurityModeResponse();
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
* @file streaming_dload_hello_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_hello_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadHelloRequest::StreamingDloadHelloRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("magic", kPacketFieldTypeArray, STREAMING_DLOAD_MAGIC_SIZE);
	addField("version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("compatible_version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadHello);
	setMagic("QualcommOM fast download protocol host");
	setVersion(0x05);
	setCompatibleVersion(0x02);
	setFeatureBits(0x19);
}

StreamingDloadHelloRequest::~StreamingDloadHelloRequest()
{

}

std::string StreamingDloadHelloRequest::getMagic()
{
	return getString(32, getFieldOffset("magic"));
}
                
void StreamingDloadHelloRequest::setMagic(const std::string& magic)
{
    write("magic", magic);
}
uint8_t StreamingDloadHelloRequest::getVersion()
{
    return read<uint8_t>(getFieldOffset("version"));
}
                
void StreamingDloadHelloRequest::setVersion(uint8_t version)
{
    write<uint8_t>("version", version);
}
uint8_t StreamingDloadHelloRequest::getCompatibleVersion()
{
    return read<uint8_t>(getFieldOffset("compatible_version"));
}
                
void StreamingDloadHelloRequest::setCompatibleVersion(uint8_t compatibleVersion)
{
    write<uint8_t>("compatible_version", compatibleVersion);
}
uint8_t StreamingDloadHelloRequest::getFeatureBits()
{
    return read<uint8_t>(getFieldOffset("feature_bits"));
}
                
void StreamingDloadHelloRequest::setFeatureBits(uint8_t featureBits)
{
    write<uint8_t>("feature_bits", featureBits);
}

void StreamingDloadHelloRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadHelloRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadHelloResponse* resp = new StreamingDloadHelloResponse();
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
* @file streaming_dload_erase_flash_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_erase_flash_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadEraseFlashResponse::StreamingDloadEraseFlashResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadFlashErased);
}

StreamingDloadEraseFlashResponse::~StreamingDloadEraseFlashResponse()
{

}


void StreamingDloadEraseFlashResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_hello_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_hello_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadHelloResponse::StreamingDloadHelloResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("magic", kPacketFieldTypeArray, STREAMING_DLOAD_MAGIC_SIZE);
	addField("version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("compatible_version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("preferred_block_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("base_flash_address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("flash_id_length", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("flash_id", kPacketFieldTypeVariant, 0);
	addField("window_size", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("number_of_sectors", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("sector_sizes", kPacketFieldTypeVariant, 0);
	addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadHelloResponse);
}

StreamingDloadHelloResponse::~StreamingDloadHelloResponse()
{

}

std::string StreamingDloadHelloResponse::getMagic()
{
	return getString(32, getFieldOffset("magic"));
}
                
void StreamingDloadHelloResponse::setMagic(uint8_t* data, size_t size)
{
    write("magic", data, size);
}
uint8_t StreamingDloadHelloResponse::getVersion()
{
    return read<uint8_t>(getFieldOffset("version"));
}
                
void StreamingDloadHelloResponse::setVersion(uint8_t version)
{
    write<uint8_t>("version", version);
}
uint8_t StreamingDloadHelloResponse::getCompatibleVersion()
{
    return read<uint8_t>(getFieldOffset("compatible_version"));
}
                
void StreamingDloadHelloResponse::setCompatibleVersion(uint8_t compatibleVersion)
{
    write<uint8_t>("compatible_version", compatibleVersion);
}
uint32_t StreamingDloadHelloResponse::getPreferredBlockSize()
{
    return read<uint32_t>(getFieldOffset("preferred_block_size"));
}
                
void StreamingDloadHelloResponse::setPreferredBlockSize(uint32_t preferredBlockSize)
{
    write<uint32_t>("preferred_block_size", preferredBlockSize);
}
uint32_t StreamingDloadHelloResponse::getBaseFlashAddress()
{
    return read<uint32_t>(getFieldOffset("base_flash_address"));
}
                
void StreamingDloadHelloResponse::setBaseFlashAddress(uint32_t baseFlashAddress)
{
    write<uint32_t>("base_flash_address", baseFlashAddress);
}
uint8_t StreamingDloadHelloResponse::getFlashIdLength()
{
    return read<uint8_t>(getFieldOffset("flash_id_length"));
}
                
void StreamingDloadHelloResponse::setFlashIdLength(uint8_t flashIdLength)
{
    write<uint8_t>("flash_id_length", flashIdLength);
}
std::string StreamingDloadHelloResponse::getFlashId()
{
	return getString(0, getFieldOffset("flash_id"));
}
                
void StreamingDloadHelloResponse::setFlashId(uint8_t* data, size_t size)
{
    write("flash_id", data, size);
}
uint16_t StreamingDloadHelloResponse::getWindowSize()
{
    return read<uint16_t>(getFieldOffset("window_size"));
}
                
void StreamingDloadHelloResponse::setWindowSize(uint16_t windowSize)
{
    write<uint16_t>("window_size", windowSize);
}
uint16_t StreamingDloadHelloResponse::getNumberOfSectors()
{
    return read<uint16_t>(getFieldOffset("number_of_sectors"));
}
                
void StreamingDloadHelloResponse::setNumberOfSectors(uint16_t numberOfSectors)
{
    write<uint16_t>("number_of_sectors", numberOfSectors);
}
std::vector<uint8_t> StreamingDloadHelloResponse::getSectorSizes()
{
	return read(getFieldSize("sector_sizes"), getFieldOffset("sector_sizes"));
}
                
void StreamingDloadHelloResponse::setSectorSizes(uint8_t* data, size_t size)
{
    write("sector_sizes", data, size);
}
uint8_t StreamingDloadHelloResponse::getFeatureBits()
{
    return read<uint8_t>(getFieldOffset("feature_bits"));
}
                
void StreamingDloadHelloResponse::setFeatureBits(uint8_t featureBits)
{
    write<uint8_t>("feature_bits", featureBits);
}

void StreamingDloadHelloResponse::unpack(std::vector<uint8_t>& data)
{
    StreamingDloadPacket::unpack(data);
    
    size_t ssize = 0;
    off_t offset = 0;

    setCommand(read<uint8_t>(data, offset++));

    setMagic(reinterpret_cast<uint8_t*>(&data[offset]), STREAMING_DLOAD_MAGIC_SIZE);
    offset += STREAMING_DLOAD_MAGIC_SIZE;
    
    setVersion(read<uint8_t>(data, offset++));
    setCompatibleVersion(read<uint8_t>(data, offset++));
    
    setPreferredBlockSize(read<uint32_t>(data, offset));
    offset += sizeof(uint32_t);
    
    setBaseFlashAddress(read<uint32_t>(data, offset));
    offset += sizeof(uint32_t);

    setFlashIdLength(read<uint8_t>(data, offset++));

    setFlashId(reinterpret_cast<uint8_t*>(&data[offset]), getFlashIdLength());

    offset += getFlashIdLength();

    setWindowSize(read<uint16_t>(data, offset));
    offset += sizeof(uint16_t);

    setNumberOfSectors(read<uint16_t>(data, offset));
    offset += sizeof(uint16_t);

    ssize = getNumberOfSectors() * sizeof(uint32_t);

    setSectorSizes(reinterpret_cast<uint8_t*>(&data[offset]), ssize);

    offset += ssize;

    setFeatureBits(read<uint8_t>(data, offset));
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
* @file streaming_dload_power_off_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_power_off_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadPowerOffRequest::StreamingDloadPowerOffRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadPowerOff);
}

StreamingDloadPowerOffRequest::~StreamingDloadPowerOffRequest()
{

}


void StreamingDloadPowerOffRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadPowerOffRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadPowerOffResponse* resp = new StreamingDloadPowerOffResponse();
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
* @file streaming_dload_nop_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_nop_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadNopRequest::StreamingDloadNopRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("identifier", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadNop);
}

StreamingDloadNopRequest::~StreamingDloadNopRequest()
{

}

uint32_t StreamingDloadNopRequest::getIdentifier()
{
    return read<uint32_t>(getFieldOffset("identifier"));
}
                
void StreamingDloadNopRequest::setIdentifier(uint32_t identifier)
{
    write<uint32_t>("identifier", identifier);
}

void StreamingDloadNopRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadNopRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadNopResponse* resp = new StreamingDloadNopResponse();
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
* @file streaming_dload_open_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadOpenResponse::StreamingDloadOpenResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadOpened);
}

StreamingDloadOpenResponse::~StreamingDloadOpenResponse()
{

}


void StreamingDloadOpenResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_open_multi_image_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_multi_image_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadOpenMultiImageResponse::StreamingDloadOpenMultiImageResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadOpenedMultiImage);
}

StreamingDloadOpenMultiImageResponse::~StreamingDloadOpenMultiImageResponse()
{

}

uint8_t StreamingDloadOpenMultiImageResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void StreamingDloadOpenMultiImageResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void StreamingDloadOpenMultiImageResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_get_ecc_state_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_get_ecc_state_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadGetEccStateResponse::StreamingDloadGetEccStateResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadCurrentEccState);
}

StreamingDloadGetEccStateResponse::~StreamingDloadGetEccStateResponse()
{

}

uint8_t StreamingDloadGetEccStateResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void StreamingDloadGetEccStateResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void StreamingDloadGetEccStateResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_open_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadOpenRequest::StreamingDloadOpenRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadOpen);
}

StreamingDloadOpenRequest::~StreamingDloadOpenRequest()
{

}

uint8_t StreamingDloadOpenRequest::getMode()
{
    return read<uint8_t>(getFieldOffset("mode"));
}
                
void StreamingDloadOpenRequest::setMode(uint8_t mode)
{
    write<uint8_t>("mode", mode);
}

void StreamingDloadOpenRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadOpenRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadOpenResponse* resp = new StreamingDloadOpenResponse();
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
* @file streaming_dload_erase_flash_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_erase_flash_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadEraseFlashRequest::StreamingDloadEraseFlashRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadEraseFlash);
}

StreamingDloadEraseFlashRequest::~StreamingDloadEraseFlashRequest()
{

}


void StreamingDloadEraseFlashRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadEraseFlashRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadEraseFlashResponse* resp = new StreamingDloadEraseFlashResponse();
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
* @file streaming_dload_set_ecc_state_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_set_ecc_state_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadSetEccStateResponse::StreamingDloadSetEccStateResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadSetEccResponse);
}

StreamingDloadSetEccStateResponse::~StreamingDloadSetEccStateResponse()
{

}


void StreamingDloadSetEccStateResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_close_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_close_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadCloseRequest::StreamingDloadCloseRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("mode", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadClose);
}

StreamingDloadCloseRequest::~StreamingDloadCloseRequest()
{

}

uint8_t StreamingDloadCloseRequest::getMode()
{
    return read<uint8_t>(getFieldOffset("mode"));
}
                
void StreamingDloadCloseRequest::setMode(uint8_t mode)
{
    write<uint8_t>("mode", mode);
}

void StreamingDloadCloseRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadCloseRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadCloseResponse* resp = new StreamingDloadCloseResponse();
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
* @file streaming_dload_partition_table_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_partition_table_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadPartitionTableResponse::StreamingDloadPartitionTableResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadPartitionTableReceived);
}

StreamingDloadPartitionTableResponse::~StreamingDloadPartitionTableResponse()
{

}

uint8_t StreamingDloadPartitionTableResponse::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void StreamingDloadPartitionTableResponse::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void StreamingDloadPartitionTableResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_get_ecc_state_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_get_ecc_state_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadGetEccStateRequest::StreamingDloadGetEccStateRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadGetEccState);
}

StreamingDloadGetEccStateRequest::~StreamingDloadGetEccStateRequest()
{

}


void StreamingDloadGetEccStateRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadGetEccStateRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadGetEccStateResponse* resp = new StreamingDloadGetEccStateResponse();
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
* @file streaming_dload_stream_write_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_stream_write_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadStreamWriteRequest::StreamingDloadStreamWriteRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);

	setCommand(kStreamingDloadStreamWrite);
}

StreamingDloadStreamWriteRequest::~StreamingDloadStreamWriteRequest()
{

}

uint32_t StreamingDloadStreamWriteRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadStreamWriteRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
std::vector<uint8_t> StreamingDloadStreamWriteRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void StreamingDloadStreamWriteRequest::setData(std::ifstream& file, size_t size)
{
    write("data", file, size);
}
void StreamingDloadStreamWriteRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}
void StreamingDloadStreamWriteRequest::setData(const std::string& data)
{
    write("data", data);
}

void StreamingDloadStreamWriteRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadStreamWriteRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadStreamWriteResponse* resp = new StreamingDloadStreamWriteResponse();
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
* @file streaming_dload_power_off_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_power_off_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadPowerOffResponse::StreamingDloadPowerOffResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadPoweringDown);
}

StreamingDloadPowerOffResponse::~StreamingDloadPowerOffResponse()
{

}

uint32_t StreamingDloadPowerOffResponse::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadPowerOffResponse::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}

void StreamingDloadPowerOffResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_reset_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_reset_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadResetRequest::StreamingDloadResetRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadReset);
}

StreamingDloadResetRequest::~StreamingDloadResetRequest()
{

}


void StreamingDloadResetRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadResetRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadResetResponse* resp = new StreamingDloadResetResponse();
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
* @file streaming_dload_reset_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_reset_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadResetResponse::StreamingDloadResetResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadResetAck);
}

StreamingDloadResetResponse::~StreamingDloadResetResponse()
{

}


void StreamingDloadResetResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_read_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_read_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadReadRequest::StreamingDloadReadRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("length", kPacketFieldTypePrimitive, sizeof(uint16_t));

	setCommand(kStreamingDloadRead);
}

StreamingDloadReadRequest::~StreamingDloadReadRequest()
{

}

uint32_t StreamingDloadReadRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadReadRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint16_t StreamingDloadReadRequest::getLength()
{
    return read<uint16_t>(getFieldOffset("length"));
}
                
void StreamingDloadReadRequest::setLength(uint16_t length)
{
    write<uint16_t>("length", length);
}

void StreamingDloadReadRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadReadRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadReadResponse* resp = new StreamingDloadReadResponse();
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
* @file streaming_dload_unframed_stream_write_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unframed_stream_write_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadUnframedStreamWriteRequest::StreamingDloadUnframedStreamWriteRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("alignment_padding", kPacketFieldTypeArray, 3);
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("length", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("data", kPacketFieldTypeVariant, 0);

	setCommand(kStreamingDloadUnframedStreamWrite);
}

StreamingDloadUnframedStreamWriteRequest::~StreamingDloadUnframedStreamWriteRequest()
{

}

std::vector<uint8_t> StreamingDloadUnframedStreamWriteRequest::getAlignmentPadding()
{
	return read(getFieldSize("alignment_padding"), getFieldOffset("alignment_padding"));
}
                
void StreamingDloadUnframedStreamWriteRequest::setAlignmentPadding(uint8_t* data, size_t size)
{
    write("alignment_padding", data, size);
}
uint32_t StreamingDloadUnframedStreamWriteRequest::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadUnframedStreamWriteRequest::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}
uint32_t StreamingDloadUnframedStreamWriteRequest::getLength()
{
    return read<uint32_t>(getFieldOffset("length"));
}
                
void StreamingDloadUnframedStreamWriteRequest::setLength(uint32_t length)
{
    write<uint32_t>("length", length);
}
std::vector<uint8_t> StreamingDloadUnframedStreamWriteRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void StreamingDloadUnframedStreamWriteRequest::setData(std::ifstream& file, size_t size)
{
    write("data", file, size);
}
void StreamingDloadUnframedStreamWriteRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}
void StreamingDloadUnframedStreamWriteRequest::setData(const std::string& data)
{
    write("data", data);
}

void StreamingDloadUnframedStreamWriteRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadUnframedStreamWriteRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadUnframedStreamWriteResponse* resp = new StreamingDloadUnframedStreamWriteResponse();
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
* @file streaming_dload_set_ecc_state_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_set_ecc_state_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadSetEccStateRequest::StreamingDloadSetEccStateRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("status", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadSetEcc);
}

StreamingDloadSetEccStateRequest::~StreamingDloadSetEccStateRequest()
{

}

uint8_t StreamingDloadSetEccStateRequest::getStatus()
{
    return read<uint8_t>(getFieldOffset("status"));
}
                
void StreamingDloadSetEccStateRequest::setStatus(uint8_t status)
{
    write<uint8_t>("status", status);
}

void StreamingDloadSetEccStateRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadSetEccStateRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadSetEccStateResponse* resp = new StreamingDloadSetEccStateResponse();
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
* @file streaming_dload_stream_write_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_stream_write_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadStreamWriteResponse::StreamingDloadStreamWriteResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadBlockWritten);
}

StreamingDloadStreamWriteResponse::~StreamingDloadStreamWriteResponse()
{

}

uint32_t StreamingDloadStreamWriteResponse::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadStreamWriteResponse::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}

void StreamingDloadStreamWriteResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_open_multi_image_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_multi_image_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadOpenMultiImageRequest::StreamingDloadOpenMultiImageRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("type", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadOpenMultiImage);
}

StreamingDloadOpenMultiImageRequest::~StreamingDloadOpenMultiImageRequest()
{

}

uint8_t StreamingDloadOpenMultiImageRequest::getType()
{
    return read<uint8_t>(getFieldOffset("type"));
}
                
void StreamingDloadOpenMultiImageRequest::setType(uint8_t type)
{
    write<uint8_t>("type", type);
}

void StreamingDloadOpenMultiImageRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadOpenMultiImageRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadOpenMultiImageResponse* resp = new StreamingDloadOpenMultiImageResponse();
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
* @file streaming_dload_unlock_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unlock_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadUnlockResponse::StreamingDloadUnlockResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadUnlocked);
}

StreamingDloadUnlockResponse::~StreamingDloadUnlockResponse()
{

}


void StreamingDloadUnlockResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_partition_table_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_partition_table_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadPartitionTableRequest::StreamingDloadPartitionTableRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("override_existing", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("data", kPacketFieldTypeArray, 512);

	setCommand(kStreamingDloadPartitionTable);
}

StreamingDloadPartitionTableRequest::~StreamingDloadPartitionTableRequest()
{

}

uint8_t StreamingDloadPartitionTableRequest::getOverrideExisting()
{
    return read<uint8_t>(getFieldOffset("override_existing"));
}
                
void StreamingDloadPartitionTableRequest::setOverrideExisting(uint8_t overrideExisting)
{
    write<uint8_t>("override_existing", overrideExisting);
}
std::vector<uint8_t> StreamingDloadPartitionTableRequest::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void StreamingDloadPartitionTableRequest::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void StreamingDloadPartitionTableRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadPartitionTableRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadPartitionTableResponse* resp = new StreamingDloadPartitionTableResponse();
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
* @file streaming_dload_close_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_close_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadCloseResponse::StreamingDloadCloseResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{

	setCommand(kStreamingDloadClosed);
}

StreamingDloadCloseResponse::~StreamingDloadCloseResponse()
{

}


void StreamingDloadCloseResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
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
* @file streaming_dload_open_multi_image_with_payload_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_open_multi_image_with_payload_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadOpenMultiImageWithPayloadRequest::StreamingDloadOpenMultiImageWithPayloadRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("type", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("payload", kPacketFieldTypeVariant, 0);

	setCommand(kStreamingDloadOpenMultiImage);
}

StreamingDloadOpenMultiImageWithPayloadRequest::~StreamingDloadOpenMultiImageWithPayloadRequest()
{

}

uint8_t StreamingDloadOpenMultiImageWithPayloadRequest::getType()
{
    return read<uint8_t>(getFieldOffset("type"));
}
                
void StreamingDloadOpenMultiImageWithPayloadRequest::setType(uint8_t type)
{
    write<uint8_t>("type", type);
}
std::vector<uint8_t> StreamingDloadOpenMultiImageWithPayloadRequest::getPayload()
{
	return read(getFieldSize("payload"), getFieldOffset("payload"));
}
                
void StreamingDloadOpenMultiImageWithPayloadRequest::setPayload(std::ifstream& file, size_t size)
{
    write("payload", file, size);
}
void StreamingDloadOpenMultiImageWithPayloadRequest::setPayload(uint8_t* data, size_t size)
{
    write("payload", data, size);
}
void StreamingDloadOpenMultiImageWithPayloadRequest::setPayload(const std::string& payload)
{
    write("payload", payload);
}

void StreamingDloadOpenMultiImageWithPayloadRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadOpenMultiImageWithPayloadRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadOpenMultiImageResponse* resp = new StreamingDloadOpenMultiImageResponse();
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
* @file streaming_dload_unlock_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unlock_request.h"

using namespace OpenPST::Qualcomm;

StreamingDloadUnlockRequest::StreamingDloadUnlockRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("code", kPacketFieldTypePrimitive, sizeof(uint64_t));

	setCommand(kStreamingDloadUnlock);
}

StreamingDloadUnlockRequest::~StreamingDloadUnlockRequest()
{

}

uint64_t StreamingDloadUnlockRequest::getCode()
{
    return read<uint64_t>(getFieldOffset("code"));
}
                
void StreamingDloadUnlockRequest::setCode(uint64_t code)
{
    write<uint64_t>("code", code);
}

void StreamingDloadUnlockRequest::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
void StreamingDloadUnlockRequest::prepareResponse()
{
	if (response == nullptr) {
		StreamingDloadUnlockResponse* resp = new StreamingDloadUnlockResponse();
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
* @file streaming_dload_unframed_stream_write_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/streaming_dload_unframed_stream_write_response.h"

using namespace OpenPST::Qualcomm;

StreamingDloadUnframedStreamWriteResponse::StreamingDloadUnframedStreamWriteResponse(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("address", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setCommand(kStreamingDloadUnframedStreamWriteResponse);
}

StreamingDloadUnframedStreamWriteResponse::~StreamingDloadUnframedStreamWriteResponse()
{

}

uint32_t StreamingDloadUnframedStreamWriteResponse::getAddress()
{
    return read<uint32_t>(getFieldOffset("address"));
}
                
void StreamingDloadUnframedStreamWriteResponse::setAddress(uint32_t address)
{
    write<uint32_t>("address", address);
}

void StreamingDloadUnframedStreamWriteResponse::unpack(std::vector<uint8_t>& data)
{
	StreamingDloadPacket::unpack(data);
}
