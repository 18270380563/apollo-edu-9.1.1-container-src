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

DECLARE_int64(mean_filter_window_size);
DECLARE_double(icp_threshold_change_slam_to_rtk);
DECLARE_double(downsize_interval_distance);
DECLARE_double(nearestk_search_distance_threshold);
DECLARE_double(nearestk_search_angle_threshold);
}  // namespace loam_velodyne
}  // namespace apollo
