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

#include <string>
#include <vector>

#include "modules/dreamview_plus_plugins/calibration_tool/proto/calibration_conf.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/error_code.pb.h"

#include "cyber/common/time_conversion.h"
#include "cyber/cyber.h"
#include "modules/common/util/json_util.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/calibration_tool/camera_calib_manager/camera_calib_task.h"
#include "modules/dreamview_plus_plugins/calibration_tool/camera_calib_manager/camera_collection_task.h"
#include "modules/dreamview_plus_plugins/calibration_tool/camera_calib_manager/camera_updater.h"
#include "modules/dreamview_plus_plugins/calibration_tool/camera_calib_manager/lidar_updater.h"
#include "modules/dreamview_plus_plugins/calibration_tool/conf_manager/conf_manager.h"

namespace apollo {
namespace dreamview {

class CameraCalibManager {
public:
    explicit CameraCalibManager(
            WebSocketHandler* websocket,
            WebSocketHandler* camera_stream_websocket,
            WebSocketHandler* lidar_stream_websocket,
            CalibConfManager* calib_conf_manager) :
            websocket_(websocket),
            camera_stream_websocket_(camera_stream_websocket),
            lidar_stream_websocket_(lidar_stream_websocket),
            calib_conf_manager_(calib_conf_manager){};
    virtual ~CameraCalibManager() = default;
    void Init();
    /**
     * @brief Get CameraCalibManager status.
     */
    const CalibStatus* GetStatus() const {
        return &status_;
    }

private:
    void RegisterMessageHandlers();
    /**
     * @brief change camera channel
     */
    bool SetCamera(const std::string& camera_name);

private:
    WebSocketHandler* websocket_;
    WebSocketHandler* camera_stream_websocket_;
    WebSocketHandler* lidar_stream_websocket_;
    const CalibConfManager* calib_conf_manager_;
    std::shared_ptr<CameraCollectionTask> camera_collection_task_;
    std::shared_ptr<CameraCalibTask> camera_calib_task_;
    std::unique_ptr<CameraUpdater> camera_updater_;
    std::unique_ptr<LidarUpdater> lidar_updater_;
    const calibration::CameraCalibConf camera_calib_conf_;
    CalibStatus status_;
    std::string curr_task_id_ = "";
    std::string curr_camera_name_ = "";
    std::string calibration_data_path_ = "";
    std::map<std::string, std::vector<std::string>> task_sub_task_id_map_;
    std::map<std::string, bool> camera_calib_status_;
    std::vector<std::string> camera_name_;

private:
    std::string GetCameraChannelByName(const std::string& camera_name);
    std::string GetLidarChannelByCameraName(const std::string& camera_name);
    void InitCameraCalibStatus();
};
}  // namespace dreamview
}  // namespace apollo