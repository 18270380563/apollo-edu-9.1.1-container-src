/******************************************************************************
 * Copyright 2023 The Apollo Authors. All Rights Reserved.
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
 ******************************************************************************/

#pragma once

#include <fstream>
#include <string>

#include "modules/common_msgs/basic_msgs/geometry.pb.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"

#include "cyber/cyber.h"
#include "cyber/data/cache_buffer.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calib_status.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

using PoseQueue = cyber::data::CacheBuffer<std::shared_ptr<localization::LocalizationEstimate>>;

/**
 * @class PointCloudCollector
 * @brief save pcd and pose info
 */
class PointCloudCollector {
public:
    explicit PointCloudCollector(
            const std::string& channel_name,
            const std::string& pcd_dir,
            const std::shared_ptr<cyber::Node>& node);
    ~PointCloudCollector();

    bool Init();

    /**
     * @brief Find matched point cloud of every lidar
     */
    bool FindPointCloud(const PoseQueue& pose_queue);

    /**
     * @brief save cloud into pcd file and save pose into pose.txt. for every lidar
     */
    bool DumpPointCloud(const PoseQueue& pose_queue);

    const CalibStatus* GetStatus() const {
        return &calib_status_;
    }

private:
    void GenerateID();

    double GetPoseTime(const std::shared_ptr<localization::LocalizationEstimate>& pose);

    bool SavePcdFile(const std::shared_ptr<drivers::PointCloud>& point_cloud);
    bool WritePoseInfo(const PoseQueue& pose_queue, const double& lidar_time);

    void WriteSinglePoseInfo(const std::shared_ptr<localization::LocalizationEstimate>& pose);

private:
    std::string channel_name_;
    std::string pcd_dir_;
    std::ofstream pose_file_fs_;
    std::string id_str_;

    std::shared_ptr<cyber::Reader<drivers::PointCloud>> reader_ = nullptr;
    std::shared_ptr<cyber::Node> node_ = nullptr;

    std::unique_ptr<common::PointENU> offset_point_ = nullptr;

    CalibStatus calib_status_;

    int cur_num_ = 0;
    std::shared_ptr<drivers::PointCloud> _pcd_buffer = nullptr;
};
}  // namespace dreamview
}  // namespace apollo
