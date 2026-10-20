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

#include <future>
#include <map>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "modules/common_msgs/localization_msgs/gps.pb.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/calibration_conf.pb.h"

#include "cyber/cyber.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calib_status.h"
#include "modules/dreamview_plus_plugins/calibration_tool/lidar_calib_manager/pointcloud_collector.h"
#include "modules/private_common/status_collector/status_collector.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class LidarCollectionTask
 * @brief Lidar collection task
 */
class LidarCollectionTask {
public:
    explicit LidarCollectionTask(const calibration::LidarCalibConf *lidar_calib_conf) :
            lidar_calib_conf_(lidar_calib_conf), node_(cyber::CreateNode("LidarCollection")) {
        status_collector_.reset(new common::StatusCollector(cyber::CreateNode("lidar_status_collector")));
    };
    virtual ~LidarCollectionTask() = default;

    /**
     * @brief Lidar collection task init.
     */
    bool Init();

    /**
     * @brief Get status of lidar collection dependent modules.
     */
    nlohmann::json GetStatus();

    /**
     * @brief Start lidar collection task.
     */
    bool Start(const std::string &task_id);

    using ProgressCallback = std::function<void(const float &, const std::string &)>;

    void SetprogressCallback(const ProgressCallback &progress_callback);

    bool IsCollectionRunning() const {
        return is_start_;
    }

    /**
     * @brief Stop lidar collection task.
     */
    bool Stop();

    /**
     * @brief Get collection task status.
     */
    const CalibStatus *GetCollectionTaskStatus() const {
        return &calib_status_;
    }

    /**
     * @brief Get collection task status message.
     */
    std::string GetCollectionTaskMessage() const {
        return calib_status_.GetMessage();
    }

private:
    /**
     * @brief Create pointcloud collector from lidar calib conf.
     */
    bool CreatePointCloudCollectors();

    /**
     * @brief create cyber readers
     */
    void CreateLocalizationReader();

    void LocalizationCallback(const std::shared_ptr<localization::LocalizationEstimate> &msg);
    bool UpdateValidPose(const std::shared_ptr<localization::LocalizationEstimate> &msg);

    void SavePcdAndPoseInfo(const PoseQueue &pose_queue);

    void ForwardProgress();

    void Reset();

private:
    CalibStatus calib_status_;
    const calibration::LidarCalibConf *lidar_calib_conf_;
    std::shared_ptr<cyber::Node> node_ = nullptr;
    std::unique_ptr<common::StatusCollector> status_collector_ = nullptr;

    std::shared_ptr<PoseQueue> pose_queue_;
    std::shared_ptr<cyber::Reader<localization::LocalizationEstimate>> loc_reader_ = nullptr;
    std::shared_ptr<cyber::Reader<localization::Gps>> odom_reader_ = nullptr;
    std::shared_ptr<localization::LocalizationEstimate> latest_valid_pose_ = nullptr;

    std::future<void> save_pcd_future_;
    std::vector<std::shared_ptr<PointCloudCollector>> pointcloud_collectors_;

    std::atomic_uint32_t processed_num_{0};
    float progress_ = 0.0;
    ProgressCallback progress_callback_ = nullptr;

    bool is_start_ = false;
    std::string task_id_;
    std::mutex mutex_;
    std::atomic_uint32_t total_num_{0};
};
}  // namespace dreamview
}  // namespace apollo
