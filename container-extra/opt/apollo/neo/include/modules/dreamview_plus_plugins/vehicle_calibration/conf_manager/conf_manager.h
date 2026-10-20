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

#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/calibration_table_conf.pb.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/error_code.pb.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/vehicle_calibration_conf.pb.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/vehicle_param.pb.h"

#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/common/calib_status.h"
/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class VehicleCalibConfManager
 * @brief Calibration config management library
 */
class VehicleCalibConfManager {
public:
    explicit VehicleCalibConfManager(WebSocketHandler* websocket) : websocket_(websocket){};
    virtual ~VehicleCalibConfManager() = default;

    /**
     * @brief Load calib conf and register websocket handlers.
     */
    void Init();

    /**
     * @brief Get VehicleCalibConfManager status.
     */
    const CalibStatus* GetStatus() const {
        return &status_;
    }

    /**
     * @brief Get Dynamics calib conf
     */
    const vehicle_calibration::VehicleCalibConf* GetCalibConf() const {
        return &calib_conf_;
    };

    const vehicle_calibration::VehicleParamConf* GetParamConf() const {
        return &param_conf_;
    };

private:
    /**
     * @brief load conf
     */
    void LoadConf();

    /**
     * @brief load conf from local file
     */
    void LoadConfFromLocal();

    /**
     * @brief load conf from cloud
     */
    void LoadConfFromCloud();

    /**
     * @brief register websocket handlers
     */
    void RegisterMessageHandlers();

    /**
     * @brief GenDynamicsConf json
     */
    nlohmann::json GenDynamicsConf(
            vehicle_calibration::VehicleCalibConf conf,
            vehicle_calibration::VehicleParamConf param_conf);

private:
    CalibStatus status_;
    WebSocketHandler* websocket_;
    vehicle_calibration::VehicleCalibConf calib_conf_;
    vehicle_calibration::VehicleParamConf param_conf_;
};
}  // namespace dreamview
}  // namespace apollo
