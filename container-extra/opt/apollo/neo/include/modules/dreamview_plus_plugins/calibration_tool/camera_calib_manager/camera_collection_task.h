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

#include <map>
#include <mutex>
#include <string>

#include <nlohmann/json.hpp>

#include "opencv2/opencv.hpp"
#include "pcl/point_cloud.h"
#include "pcl/point_types.h"

#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/common_msgs/sensor_msgs/sensor_image.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/calibration_conf.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/camera.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/point_cloud.pb.h"

#include "cyber/common/time_conversion.h"
#include "cyber/cyber.h"
#include "modules/dreamview_plus_plugins/calibration_tool/camera_calib_manager/camera_calib_task.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calib_status.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calibration_gflags.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/pcl_point_type.h"
#include "modules/dreamview_plus_plugins/calibration_tool/conf_manager/conf_manager.h"
#include "modules/private_common/status_collector/status_collector.h"
namespace apollo {
namespace dreamview {

class CameraCollectionTask {
public:
    explicit CameraCollectionTask(const CalibConfManager* calib_conf_manager);
    virtual ~CameraCollectionTask() = default;
    void Init();

    // /**
    //  * @brief Get CameraCollection status.
    //  */
    const CalibStatus* GetStatus() const {
        return &status_;
    }

    /**
     * @brief Capture a pair camera to lidar and keep to disk.
     *
     */
    std::string CaptureCameraPair();

    /**
     * @brief Set curr capture camera.
     */
    void SetCamera(const std::string& camera_name);

    /**
     * @brief Set curr task id and create collection data file dir.
     */
    void SetTaskId(const std::string& task_id);

    /**
     * @brief Get curr subtask id for start a camera calib task.
     */
    const std::string GetCurrSubtaskId() {
        return curr_subtask_id_;
    }

    /**
     * @brief Delete calibration data of a camera calib sub task.
     */
    bool DelCameraCalibData(const std::string& subtask_id);

    /**
     * @brief Get status check json
     */
    nlohmann::json GetStatusResult();

    /**
     * @brief Remove failed data to failed_data dir. Conveniently view the reasons for failure data in a unified manner.
     */
    void RemoveFailedData(const std::string& subtask_id);

private:
    /**
     * @brief Save camera data to png of a camera-lidar pair to disk.
     */
    bool SaveCameraToDisk();

    /**
     * @brief Save pointcloud data to pcd of a camera-lidar pair to disk.
     */
    bool SavePointCloudToDisk();

    void GetImage(const std::shared_ptr<apollo::drivers::Image>& image_ptr);

    void GetPointCloud(const std::shared_ptr<apollo::drivers::PointCloud>& point_cloud_ptr);

private:
    const CalibConfManager* calib_conf_manager_;
    std::unique_ptr<cyber::Node> node_ = nullptr;
    std::shared_ptr<cyber::Node> status_node_ = nullptr;
    std::shared_ptr<cyber::Reader<drivers::Image>> curr_camera_reader_ = nullptr;
    std::shared_ptr<cyber::Reader<drivers::PointCloud>> curr_lidar_reader_ = nullptr;
    std::string calibration_data_path_ = "";
    std::string curr_task_id_ = "";
    std::string curr_subtask_id_ = "";
    std::string curr_task_path_ = "";
    std::string curr_sub_task_path_ = "";
    std::string curr_camera_ = "";
    std::string curr_camera_topic_ = "";
    std::string curr_lidar_topic_ = "";
    CalibStatus status_;
    cv::Mat mat_bgr_;
    pcl::PointCloud<PointTypeXYZIT> pcl_point_cloud_;
    std::unique_ptr<apollo::common::StatusCollector> status_collector_;
    std::mutex pcl_point_cloud_mutex_;
    std::mutex image_mutex_;
    std::string image_collection_time_;
    std::string point_cloud_time_;
};

}  // namespace dreamview
}  // namespace apollo