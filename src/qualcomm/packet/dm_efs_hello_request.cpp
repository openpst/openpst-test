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
* @file dm_efs_hello_request.cpp
* @package openpst/libopenpst
* @brief  This file was auto generated on 03/02/2017
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_hello_request.h"

using namespace OpenPST::Qualcomm;

DmEfsHelloRequest::DmEfsHelloRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("target_packet_window_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("target_packet_window_byte_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("host_packet_window_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("host_packet_window_byte_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("dir_iterator_window_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("dir_iterator_window_byte_size", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("max_version", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint32_t));

	setSubsysCommand(kDiagEfsHello);

	setResponseExpected(true);
}

DmEfsHelloRequest::~DmEfsHelloRequest()
{

}

uint32_t DmEfsHelloRequest::getTargetPacketWindowSize()
{
    return read<uint32_t>(getFieldOffset("target_packet_window_size"));
}
                

void DmEfsHelloRequest::setTargetPacketWindowSize(uint32_t targetPacketWindowSize)
{
    write<uint32_t>("target_packet_window_size", targetPacketWindowSize);
}

uint32_t DmEfsHelloRequest::getTargetPacketWindowByteSize()
{
    return read<uint32_t>(getFieldOffset("target_packet_window_byte_size"));
}
                

void DmEfsHelloRequest::setTargetPacketWindowByteSize(uint32_t targetPacketWindowByteSize)
{
    write<uint32_t>("target_packet_window_byte_size", targetPacketWindowByteSize);
}

uint32_t DmEfsHelloRequest::getHostPacketWindowSize()
{
    return read<uint32_t>(getFieldOffset("host_packet_window_size"));
}
                

void DmEfsHelloRequest::setHostPacketWindowSize(uint32_t hostPacketWindowSize)
{
    write<uint32_t>("host_packet_window_size", hostPacketWindowSize);
}

uint32_t DmEfsHelloRequest::getHostPacketWindowByteSize()
{
    return read<uint32_t>(getFieldOffset("host_packet_window_byte_size"));
}
                

void DmEfsHelloRequest::setHostPacketWindowByteSize(uint32_t hostPacketWindowByteSize)
{
    write<uint32_t>("host_packet_window_byte_size", hostPacketWindowByteSize);
}

uint32_t DmEfsHelloRequest::getDirIteratorWindowSize()
{
    return read<uint32_t>(getFieldOffset("dir_iterator_window_size"));
}
                

void DmEfsHelloRequest::setDirIteratorWindowSize(uint32_t dirIteratorWindowSize)
{
    write<uint32_t>("dir_iterator_window_size", dirIteratorWindowSize);
}

uint32_t DmEfsHelloRequest::getDirIteratorWindowByteSize()
{
    return read<uint32_t>(getFieldOffset("dir_iterator_window_byte_size"));
}
                

void DmEfsHelloRequest::setDirIteratorWindowByteSize(uint32_t dirIteratorWindowByteSize)
{
    write<uint32_t>("dir_iterator_window_byte_size", dirIteratorWindowByteSize);
}

uint32_t DmEfsHelloRequest::getVersion()
{
    return read<uint32_t>(getFieldOffset("version"));
}
                

void DmEfsHelloRequest::setVersion(uint32_t version)
{
    write<uint32_t>("version", version);
}

uint32_t DmEfsHelloRequest::getMaxVersion()
{
    return read<uint32_t>(getFieldOffset("max_version"));
}
                

void DmEfsHelloRequest::setMaxVersion(uint32_t maxVersion)
{
    write<uint32_t>("max_version", maxVersion);
}

uint32_t DmEfsHelloRequest::getFeatureBits()
{
    return read<uint32_t>(getFieldOffset("feature_bits"));
}
                

void DmEfsHelloRequest::setFeatureBits(uint32_t featureBits)
{
    write<uint32_t>("feature_bits", featureBits);
}

void DmEfsHelloRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsHelloResponse* resp = new DmEfsHelloResponse();
		response = resp;
	}
}

void DmEfsHelloRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setTargetPacketWindowSize(read<uint32_t>(data, getFieldOffset("target_packet_window_size")));
	setTargetPacketWindowByteSize(read<uint32_t>(data, getFieldOffset("target_packet_window_byte_size")));
	setHostPacketWindowSize(read<uint32_t>(data, getFieldOffset("host_packet_window_size")));
	setHostPacketWindowByteSize(read<uint32_t>(data, getFieldOffset("host_packet_window_byte_size")));
	setDirIteratorWindowSize(read<uint32_t>(data, getFieldOffset("dir_iterator_window_size")));
	setDirIteratorWindowByteSize(read<uint32_t>(data, getFieldOffset("dir_iterator_window_byte_size")));
	setVersion(read<uint32_t>(data, getFieldOffset("version")));
	setMaxVersion(read<uint32_t>(data, getFieldOffset("max_version")));
	setFeatureBits(read<uint32_t>(data, getFieldOffset("feature_bits")));
}
