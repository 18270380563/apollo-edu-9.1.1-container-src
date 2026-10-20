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
#include <mutex>

#include "pcl/point_cloud.h"
#include "pcl/point_types.h"

#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/dreamview_plus/proto/data_handler.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/point_cloud.pb.h"

#include "cyber/cyber.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calib_status.h"
namespace apollo {
namespace dreamview {

class LidarUpdater {
public:
    explicit LidarUpdater(WebSocketHandler* camera_stream_websocket) :
            websocket_(camera_stream_websocket), node_(cyber::CreateNode("CameraCalib_LidarUpdater")){};

    /**
     * @brief Subscribe the camera channel info.
     *
     * @param time_interval_ms The data sending frequency required by the front end.
     * @param channel_name The subscribe lidar channel name.
     */
    bool SubscribeChannel(const double& time_interval_ms, const std::string& channel_name = "");
    bool UnSubscribeChannel();
    void PublishMessage();
    const CalibStatus* GetStatus() const {
        return &status_;
    }

private:
    WebSocketHandler* websocket_;
    std::unique_ptr<cyber::Timer> timer_;
    CalibStatus status_;
    std::string curr_channel_name_ = "";
    std::unique_ptr<cyber::Node> node_;
    std::shared_ptr<cyber::Reader<drivers::PointCloud>> curr_lidar_reader_;
    pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_ptr_;
    std::mutex point_cloud_mutex_;

private:
    void GetPointCloud(const std::shared_ptr<drivers::PointCloud>& point_cloud_ptr);
    pcl::PointCloud<pcl::PointXYZ>::Ptr ConvertPcl(const std::shared_ptr<drivers::PointCloud>& point_cloud);
    void FilterPointCloudStr(std::string* to_send);
};

}  // namespace dreamview
}  // namespace apollo