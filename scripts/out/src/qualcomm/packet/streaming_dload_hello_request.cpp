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

using namespace OpenPST::QC;

StreamingDloadHelloRequest::StreamingDloadHelloRequest(PacketEndianess targetEndian) : StreamingDloadPacket(targetEndian)
{
	addField("magic", kPacketFieldTypeArray, STREAMING_DLOAD_MAGIC_SIZE);
	addField("version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("compatible_version", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("feature_bits", kPacketFieldTypePrimitive, sizeof(uint8_t));

	setCommand(kStreamingDloadHello);
	setMagic("QCOM fast download protocol host");
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
