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
* @file dm_efs_factory_image_read_response.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_factory_image_read_response.h"

using namespace OpenPST::Qualcomm;

DmEfsFactoryImageReadResponse::DmEfsFactoryImageReadResponse(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("error", kPacketFieldTypePrimitive, sizeof(uint32_t));
	addField("stream_state", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("info_cluster_sent", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("custer_map_sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("custer_data_sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("data", kPacketFieldTypeVariant, 0);

	setSubsysCommand(kDiagEfsFactoryImageRead);
}

DmEfsFactoryImageReadResponse::~DmEfsFactoryImageReadResponse()
{

}

uint32_t DmEfsFactoryImageReadResponse::getError()
{
    return read<uint32_t>(getFieldOffset("error"));
}
                
void DmEfsFactoryImageReadResponse::setError(uint32_t error)
{
    write<uint32_t>("error", error);
}
uint8_t DmEfsFactoryImageReadResponse::getStreamState()
{
    return read<uint8_t>(getFieldOffset("stream_state"));
}
                
void DmEfsFactoryImageReadResponse::setStreamState(uint8_t streamState)
{
    write<uint8_t>("stream_state", streamState);
}
uint8_t DmEfsFactoryImageReadResponse::getInfoClusterSent()
{
    return read<uint8_t>(getFieldOffset("info_cluster_sent"));
}
                
void DmEfsFactoryImageReadResponse::setInfoClusterSent(uint8_t infoClusterSent)
{
    write<uint8_t>("info_cluster_sent", infoClusterSent);
}
uint16_t DmEfsFactoryImageReadResponse::getCusterMapSequence()
{
    return read<uint16_t>(getFieldOffset("custer_map_sequence"));
}
                
void DmEfsFactoryImageReadResponse::setCusterMapSequence(uint16_t custerMapSequence)
{
    write<uint16_t>("custer_map_sequence", custerMapSequence);
}
uint16_t DmEfsFactoryImageReadResponse::getCusterDataSequence()
{
    return read<uint16_t>(getFieldOffset("custer_data_sequence"));
}
                
void DmEfsFactoryImageReadResponse::setCusterDataSequence(uint16_t custerDataSequence)
{
    write<uint16_t>("custer_data_sequence", custerDataSequence);
}
std::vector<uint8_t> DmEfsFactoryImageReadResponse::getData()
{
	return read(getFieldSize("data"), getFieldOffset("data"));
}
                
void DmEfsFactoryImageReadResponse::setData(uint8_t* data, size_t size)
{
    write("data", data, size);
}

void DmEfsFactoryImageReadResponse::unpack(std::vector<uint8_t>& data)
{
	DmEfsPacket::unpack(data);
}
