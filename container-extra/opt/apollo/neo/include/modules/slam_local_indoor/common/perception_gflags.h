/******************************************************************************
 * Copyright 2024 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include "gflags/gflags.h"

namespace apollo {
namespace loam_velodyne {

DECLARE_bool(enable_slam_debug_flag);

DECLARE_string(pose_path);

// map files path
DECLARE_string(threeTracePath);
DECLARE_string(sixTracePath);
DECLARE_string(surfFilePath);
DECLARE_string(offsetFile);

// trajectory log path
DECLARE_string(trajectory_slam);
DECLARE_string(trajectory_slam_local);
DECLARE_string(trajectory_rtk);

DECLARE_string(slam_pose_result);

DECLARE_double(imu_gps_translation_x);
DECLARE_double(imu_gps_translation_y);
DECLARE_double(imu_gps_translation_z);
DECLARE_bool(local_map_downsize);
DECLARE_double(downsize_interval_distance);
DECLARE_double(nearestk_search_distance_threshold);
DECLARE_double(nearestk_search_angle_threshold);
DECLARE_int64(mean_filter_window_size);

// for indoor slam
DECLARE_double(map_offset_x);
DECLARE_double(map_offset_y);
DECLARE_double(map_offset_z);

DECLARE_double(slam_indoor_init_x);
DECLARE_double(slam_indoor_init_y);

DECLARE_bool(init_yaw_auto_change);
DECLARE_double(init_status_icp_threshold);
DECLARE_string(init_DV_position_channel);

// use croped pointcloud to match local map
DECLARE_bool(crop_range_for_pointcloud);
DECLARE_double(x_left_boundary);
DECLARE_double(x_right_boundary);
DECLARE_double(y_back_boundary);
DECLARE_double(y_front_boundary);

}  // namespace loam_velodyne
}  // namespace apollo
