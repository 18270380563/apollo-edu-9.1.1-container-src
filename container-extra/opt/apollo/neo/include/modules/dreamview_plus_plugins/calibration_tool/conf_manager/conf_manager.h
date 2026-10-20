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

#include "modules/dreamview_plus/proto/data_handler.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/calibration_conf.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/error_code.pb.h"

#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calib_status.h"
/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class CalibConfManager
 * @brief Calibration config management library
 */
class CalibConfManager {
public:
    explicit CalibConfManager(WebSocketHandler* websocket) : websocket_(websocket){};
    virtual ~CalibConfManager() = default;

    /**
     * @brief Load calib conf and register websocket handlers.
     */
    void Init();

    /**
     * @brief Get CalibConfManager status.
     */
    const CalibStatus* GetStatus() const {
        return &status_;
    }

    /**
     * @brief Get Lidar calib conf
     */
    const calibration::LidarCalibConf* GetLidarCalibConf() const;

    /**
     * @brief Get Camera calib conf
     */
    const calibration::CameraCalibConf* GetCameraCalibConf() const;

    /**
     * @brief Get camera channel by camera name.
     */
    const std::string GetCameraChannelByName(const std::string& camera_name) const;

    /**
     * @brief Get lidar channel by camera name.
     */
    const std::string GetLidarChannelByCameraName(const std::string& camera_name) const;

    /**
     * @brief Get lidar list json
     */
    const nlohmann::json GetLidarList() const;

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
     * @brief GenLidarConf json
     */
    nlohmann::json GenLidarConf(calibration::CalibConf conf);

    /**
     * @brief GenCameraConf json
     */
    nlohmann::json GenCameraConf(calibration::CalibConf conf);

    /**
     * @brief Create camera algorithm needed params files
     *
     * @param string task_id
     */
    void CreateCameraConfigs(const std::string task_id);

private:
    CalibStatus status_;
    WebSocketHandler* websocket_;
    calibration::CalibConf calib_conf_;
    calibration::LidarCalibConf lidar_calib_conf_;
    calibration::CameraCalibConf camera_calib_conf_;
    DataHandlerConf data_handler_conf_;
    std::map<const std::string, std::string> camera_channel_name_map_;

private:
    /**
     * @brief load hander info.
     */
    nlohmann::json LoadHandlerInfo();

    /**
     *  @brief Create the camera intrin that calibration algorithm need.
     */
    void GenCalibCameraIntrin(const std::string task_id);

    /**
     *  @brief Create the camera intrin that calibration algorithm need.
     */
    void GenCalibCameraExtrinsic(const std::string task_id);

    /**
     *  @brief Get camera channel name map, key is camera name, value is camera channel.
     */
    void GetCameraChannelNameMap();
};
}  // namespace dreamview
}  // namespace apollo
