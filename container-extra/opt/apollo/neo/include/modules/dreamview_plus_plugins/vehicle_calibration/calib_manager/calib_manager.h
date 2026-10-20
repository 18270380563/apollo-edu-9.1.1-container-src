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

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>

#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/calibration_table_conf.pb.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/error_code.pb.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/vehicle_calibration_conf.pb.h"

#include "cyber/cyber.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/calib_manager/calib_task.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/calib_manager/collection_task.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/common/calib_status.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/conf_manager/conf_manager.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class CalibManager
 * @brief Vehicle calibration management library
 */
class CalibManager {
public:
    explicit CalibManager(WebSocketHandler* websocket, const VehicleCalibConfManager* calib_conf_manager) :
            websocket_(websocket), calib_conf_manager_(calib_conf_manager){};
    virtual ~CalibManager() = default;

    /**
     * @brief Vehicle calibration init.
     */
    void Init();

private:
    /**
     * @brief register websocket handlers
     */
    void RegisterMessageHandlers();

    nlohmann::json OnCollectionProgress(
            const std::string& request_id,
            const std::string& type,
            const int& loc_x,
            const int& loc_y,
            const float& progress,
            const float& progress_global);

    nlohmann::json OnCalibProgress(const std::string& request_id, const std::string& type, const int& progress);

    std::string UpdateDynamicsTargetConf();

private:
    CalibStatus status_;
    WebSocketHandler* websocket_;
    const vehicle_calibration::VehicleCalibConf* vehicle_calib_conf_;
    vehicle_calibration::CalibrationTableConf calib_table_conf_;
    std::shared_ptr<VehicleCalibTask> calib_task_;
    std::shared_ptr<CollectionTask> collection_task_;
    const VehicleCalibConfManager* calib_conf_manager_;
    std::string task_id_;
    std::string progess_req_id_;
    std::mutex timer_mutex_;
};
}  // namespace dreamview
}  // namespace apollo
