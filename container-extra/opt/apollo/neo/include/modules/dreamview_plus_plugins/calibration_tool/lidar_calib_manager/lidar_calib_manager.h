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
#include <iostream>
#include <string>

#include <yaml-cpp/yaml.h>

#include "modules/dreamview_plus_plugins/calibration_tool/proto/calibration_conf.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/error_code.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/lidar_calib_message.pb.h"

#include "cyber/cyber.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calib_status.h"
#include "modules/dreamview_plus_plugins/calibration_tool/conf_manager/conf_manager.h"
#include "modules/dreamview_plus_plugins/calibration_tool/lidar_calib_manager/lidar_calib_task.h"
#include "modules/dreamview_plus_plugins/calibration_tool/lidar_calib_manager/lidar_collection_task.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class LidarCalibManager
 * @brief Lidar calibration management library
 */
class LidarCalibManager {
public:
    explicit LidarCalibManager(WebSocketHandler* websocket, const CalibConfManager* calib_conf_manager) :
            websocket_(websocket), calib_conf_manager_(calib_conf_manager) {};
    virtual ~LidarCalibManager() = default;

    /**
     * @brief Lidar calibration init.
     */
    void Init();

private:
    /**
     * @brief register websocket handlers
     */
    void RegisterMessageHandlers();

    nlohmann::json OnProgress(const std::string& request_id, const float& progress, const std::string& err_msg);

private:
    CalibStatus status_;
    WebSocketHandler* websocket_;
    std::shared_ptr<cyber::Timer> calib_progress_timer_;
    std::unique_ptr<cyber::Timer> collection_progress_timer_;
    const CalibConfManager* calib_conf_manager_;
    const calibration::LidarCalibConf* lidar_calib_conf_;
    std::string UpdateLidarTargetConf();

    std::shared_ptr<LidarCalibTask> calib_task_;
    std::shared_ptr<LidarCollectionTask> collection_task_;
    std::string task_id_;
    std::string progess_req_id_;
    std::mutex timer_mutex_;
};
}  // namespace dreamview
}  // namespace apollo
