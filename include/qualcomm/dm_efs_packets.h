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
* @file dm_efs_packets.h
* @package openpst/libopenpst
* @brief 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include "qualcomm/packet/dm_efs_packet.h"
#include "qualcomm/packet/dm_efs_open_dir_response.h"
#include "qualcomm/packet/dm_efs_shred_response.h"
#include "qualcomm/packet/dm_efs_factory_image_read_response.h"
#include "qualcomm/packet/dm_efs_chmod_request.h"
#include "qualcomm/packet/dm_efs_read_link_response.h"
#include "qualcomm/packet/dm_efs_create_link_response.h"
#include "qualcomm/packet/dm_efs_unlink_response.h"
#include "qualcomm/packet/dm_efs_open_dir_request.h"
#include "qualcomm/packet/dm_efs_read_link_request.h"
#include "qualcomm/packet/dm_efs_deltree_response.h"
#include "qualcomm/packet/dm_efs_chown_response.h"
#include "qualcomm/packet/dm_efs_access_response.h"
#include "qualcomm/packet/dm_efs_rmdir_response.h"
#include "qualcomm/packet/dm_efs_write_file_response.h"
#include "qualcomm/packet/dm_efs_factory_image_start_request.h"
#include "qualcomm/packet/dm_efs_statfs_v2_request.h"
#include "qualcomm/packet/dm_efs_close_file_request.h"
#include "qualcomm/packet/dm_efs_unlink_request.h"
#include "qualcomm/packet/dm_efs_factory_image_read_request.h"
#include "qualcomm/packet/dm_efs_query_request.h"
#include "qualcomm/packet/dm_efs_factory_image_start_response.h"
#include "qualcomm/packet/dm_efs_set_quota_request.h"
#include "qualcomm/packet/dm_efs_ftruncate_request.h"
#include "qualcomm/packet/dm_efs_read_dir_response.h"
#include "qualcomm/packet/dm_efs_factory_image_prepare_request.h"
#include "qualcomm/packet/dm_efs_factory_image_end_response.h"
#include "qualcomm/packet/dm_efs_hotplug_format_request.h"
#include "qualcomm/packet/dm_efs_truncate_response.h"
#include "qualcomm/packet/dm_efs_rename_request.h"
#include "qualcomm/packet/dm_efs_md5_sum_request.h"
#include "qualcomm/packet/dm_efs_fstat_request.h"
#include "qualcomm/packet/dm_efs_access_request.h"
#include "qualcomm/packet/dm_efs_truncate_request.h"
#include "qualcomm/packet/dm_efs_statfs_v2_response.h"
#include "qualcomm/packet/dm_efs_factory_image_end_request.h"
#include "qualcomm/packet/dm_efs_device_info_request.h"
#include "qualcomm/packet/dm_efs_read_dir_request.h"
#include "qualcomm/packet/dm_efs_mkdir_request.h"
#include "qualcomm/packet/dm_efs_open_file_request.h"
#include "qualcomm/packet/dm_efs_statfs_response.h"
#include "qualcomm/packet/dm_efs_read_file_request.h"
#include "qualcomm/packet/dm_efs_hello_request.h"
#include "qualcomm/packet/dm_efs_lstat_response.h"
#include "qualcomm/packet/dm_efs_sync_request.h"
#include "qualcomm/packet/dm_efs_sync_response.h"
#include "qualcomm/packet/dm_efs_get_group_info_response.h"
#include "qualcomm/packet/dm_efs_set_quota_response.h"
#include "qualcomm/packet/dm_efs_fstat_response.h"
#include "qualcomm/packet/dm_efs_device_info_response.h"
#include "qualcomm/packet/dm_efs_query_response.h"
#include "qualcomm/packet/dm_efs_rmdir_request.h"
#include "qualcomm/packet/dm_efs_stat_response.h"
#include "qualcomm/packet/dm_efs_mkdir_response.h"
#include "qualcomm/packet/dm_efs_shred_request.h"
#include "qualcomm/packet/dm_efs_lstat_request.h"
#include "qualcomm/packet/dm_efs_rename_response.h"
#include "qualcomm/packet/dm_efs_ftruncate_response.h"
#include "qualcomm/packet/dm_efs_stat_request.h"
#include "qualcomm/packet/dm_efs_statfs_request.h"
#include "qualcomm/packet/dm_efs_chmod_response.h"
#include "qualcomm/packet/dm_efs_get_group_info_request.h"
#include "qualcomm/packet/dm_efs_md5_sum_response.h"
#include "qualcomm/packet/dm_efs_set_reservation_response.h"
#include "qualcomm/packet/dm_efs_factory_image_prepare_response.h"
#include "qualcomm/packet/dm_efs_hotplug_device_info_response.h"
#include "qualcomm/packet/dm_efs_hotplug_device_info_request.h"
#include "qualcomm/packet/dm_efs_deltree_request.h"
#include "qualcomm/packet/dm_efs_hello_response.h"
#include "qualcomm/packet/dm_efs_open_file_response.h"
#include "qualcomm/packet/dm_efs_set_reservation_request.h"
#include "qualcomm/packet/dm_efs_write_file_request.h"
#include "qualcomm/packet/dm_efs_chown_request.h"
#include "qualcomm/packet/dm_efs_create_link_request.h"
#include "qualcomm/packet/dm_efs_close_dir_request.h"
#include "qualcomm/packet/dm_efs_read_file_response.h"
#include "qualcomm/packet/dm_efs_hotplug_format_response.h"
#include "qualcomm/packet/dm_efs_close_file_reponse.h"
#include "qualcomm/packet/dm_efs_close_dir_response.h"
