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
* @file dm_efs_factory_image_read_request.cpp
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#include "qualcomm/packet/dm_efs_factory_image_read_request.h"

using namespace OpenPST::Qualcomm;

DmEfsFactoryImageReadRequest::DmEfsFactoryImageReadRequest(PacketEndianess targetEndian) : DmEfsPacket(targetEndian)
{
	addField("stream_state", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("info_cluster_sent", kPacketFieldTypePrimitive, sizeof(uint8_t));
	addField("custer_map_sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));
	addField("custer_data_sequence", kPacketFieldTypePrimitive, sizeof(uint16_t));

	setSubsysCommand(kDiagEfsFactoryImageRead);
}

DmEfsFactoryImageReadRequest::~DmEfsFactoryImageReadRequest()
{

}

uint8_t DmEfsFactoryImageReadRequest::getStreamState()
{
    return read<uint8_t>(getFieldOffset("stream_state"));
}
                
void DmEfsFactoryImageReadRequest::setStreamState(uint8_t streamState)
{
    write<uint8_t>("stream_state", streamState);
}
uint8_t DmEfsFactoryImageReadRequest::getInfoClusterSent()
{
    return read<uint8_t>(getFieldOffset("info_cluster_sent"));
}
                
void DmEfsFactoryImageReadRequest::setInfoClusterSent(uint8_t infoClusterSent)
{
    write<uint8_t>("info_cluster_sent", infoClusterSent);
}
uint16_t DmEfsFactoryImageReadRequest::getCusterMapSequence()
{
    return read<uint16_t>(getFieldOffset("custer_map_sequence"));
}
                
void DmEfsFactoryImageReadRequest::setCusterMapSequence(uint16_t custerMapSequence)
{
    write<uint16_t>("custer_map_sequence", custerMapSequence);
}
uint16_t DmEfsFactoryImageReadRequest::getCusterDataSequence()
{
    return read<uint16_t>(getFieldOffset("custer_data_sequence"));
}
                
void DmEfsFactoryImageReadRequest::setCusterDataSequence(uint16_t custerDataSequence)
{
    write<uint16_t>("custer_data_sequence", custerDataSequence);
}

void DmEfsFactoryImageReadRequest::prepareResponse()
{
	if (response == nullptr) {
		DmEfsFactoryImageReadResponse* resp = new DmEfsFactoryImageReadResponse();
		response = resp;
	}
}

void DmEfsFactoryImageReadRequest::unpack(std::vector<uint8_t>& data, TransportInterface* transport)
{
	DmEfsPacket::unpack(data, transport);
	setStreamState(read<uint8_t>(data, getFieldOffset("stream_state")));
	setInfoClusterSent(read<uint8_t>(data, getFieldOffset("info_cluster_sent")));
	setCusterMapSequence(read<uint16_t>(data, getFieldOffset("custer_map_sequence")));
	setCusterDataSequence(read<uint16_t>(data, getFieldOffset("custer_data_sequence")));
}
