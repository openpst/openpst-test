/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_partition_table_request.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/streaming_dload_packet.h"

using OpenPST::QC::StreamingDloadPacket;

namespace OpenPST {
    namespace QC {
        
        class StreamingDloadPartitionTableRequest : public StreamingDloadPacket
        {
            public:
                /**
                * @brief Constructor
                */
                StreamingDloadPartitionTableRequest();
                
                /**
                * @brief Destructor
                */
                ~StreamingDloadPartitionTableRequest();

                /**
                * @brief Get override_existing
                * @return uint8_t
                */
                uint8_t getOverrideExisting();
                
                /**
                * @brief Set override_existing
                * @param uint8_t overrideExisting
                * @return void
                */
                void setOverrideExisting(uint8_t overrideExisting);
                /**
                * @brief Get data
                * @return std::vector<uint8_t>
                */
                std::vector<uint8_t> getData();
                
                /**
                * @brief Set data
                * @param uint8_t* data
                * @param size_t size
                * @return void
                */
                void setData(uint8_t* data, size_t size);

            void unpack(std::vector<uint8_t>& data) override;

        };
    }
}
