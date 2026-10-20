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

/**
 * @file
 */

#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "CivetServer.h"

#include "cyber/plugin_manager/plugin_manager.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus/backend/dv_plugin/dv_plugin_base.h"
#include "modules/dreamview_plus_plugins/calibration_tool/camera_calib_manager/camera_calib_handler.h"
#include "modules/dreamview_plus_plugins/calibration_tool/camera_calib_manager/camera_calib_manager.h"
#include "modules/dreamview_plus_plugins/calibration_tool/conf_manager/conf_manager.h"
#include "modules/dreamview_plus_plugins/calibration_tool/lidar_calib_manager/lidar_calib_manager.h"
#include "modules/dreamview_plus_plugins/calibration_tool/valid_manager/valid_manager.h"
namespace apollo {
namespace dreamview {

/**
 * @class CalibrationPlugin
 *
 * @brief A dreamview plug-in that supports calibration tools functions.
 */
class CalibrationPlugin : public DvPluginBase {
public:
    /**
     * @brief Initialization interface inherited from DvPluginBase in dreamview plus.
     */
    void Init() override;

    /**
     * @brief Instance execution interface inherited from DvPluginBase in dreamview plus
     */
    void Run() override {};

    /**
     * @brief Get the names of all websocket handlers that want to be registered to the dreamview plus server.
     * @return The return value is a map, the key value is uri, and the value is
     * the websocket handler corresponding to uri.
     */
    std::map<std::string, WebSocketHandler *> GetWebSocketHandlers() override;

    /**
     * @brief Get the names of all http handlers that want to be registered to the dreamview plus server.
     * @return The return value is a map, the key value is uri, and the value is
     * the http handler corresponding to uri.
     */
    std::map<std::string, CivetHandler *> GetHandlers() override;

private:
    std::unique_ptr<WebSocketHandler> calibration_websocket_ = nullptr;
    // used to transmit camera streaming information.
    std::unique_ptr<WebSocketHandler> camera_stream_websocket_ = nullptr;
    // used to transmit lidar streaming information.
    std::unique_ptr<WebSocketHandler> lidar_stream_websocket_ = nullptr;
    std::unique_ptr<CameraCalibHandler> camera_calib_handler_ = nullptr;
    std::unique_ptr<CalibConfManager> calib_conf_manager_ = nullptr;
    std::unique_ptr<LidarCalibManager> lidar_calib_manager_ = nullptr;
    std::unique_ptr<CameraCalibManager> camera_calib_manager_ = nullptr;
    std::unique_ptr<ValidManager> valid_manager_ = nullptr;
};

CYBER_PLUGIN_MANAGER_REGISTER_PLUGIN(apollo::dreamview::CalibrationPlugin, apollo::dreamview::DvPluginBase)

}  // namespace dreamview
}  // namespace apollo
