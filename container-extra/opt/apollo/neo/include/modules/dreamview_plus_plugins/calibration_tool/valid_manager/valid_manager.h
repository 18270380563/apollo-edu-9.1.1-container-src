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

#include "modules/dreamview/proto/dv_plugin_msg.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/error_code.pb.h"

#include "cyber/cyber.h"
#include "modules/common/util/json_util.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calib_status.h"

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
class ValidManager {
public:
    explicit ValidManager(WebSocketHandler* websocket);
    virtual ~ValidManager() = default;

    /**
     * @brief Lidar calibration init.
     */
    void Init();
    enum StatusCode : int {
        OK = 0,
        AGENT_CONNECT_FAIL = 7,
        AGENT_START_FAIL = 451,
        AGENT_AUTH_START_FAIL = 452,
        AGENT_CONNECT_CLOUD_FAIL = 453,
        VEHICLE_UNREGISTERED = 460,
        VEHICLE_CERT_IN_APPLICATION = 461,
        VEHICLE_CERT_APPLICATION_DENIED = 462,
        VEHICLE_CERT_UNACTIVE = 463,
        VEHICLE_CERT_ACTIVE = 464,
        VEHICLE_CERT_ACTIVE_FAIL = 465,
        VEHICLE_CERT_EXPIRED = 466,
        VEHICLE_CERT_TO_BE_UPDATED = 467,
        PRODUCT_UNAUTH = 470,
        PRODUCT_UNACTIVE = 471,
        PRODUCT_AUTH_EXPIRED = 472,
        PRODUCT_INS_EXCEEDED = 501,
        PRODUCT_AUTH_CHANGE_OR_UNAUTH = 502,
        PRODUCT_AUTH_EXPIRED_S = 503,
        ASYNC_AUTH_UNSTART = 504,
        QPS_EXCEEDED = 505,
        PRODUCT_UNREGISTERED = 508,
        SIGNATURE_CHANGED = 509,
        // 其他状态码...
    };
    enum StatusForFrontEnd {
        FUEL_NORMAL = 0,
        FUEL_NOTOPENED = 1,
        FUEL_NOT_ACTIVED = 2,
        FUEL_EXPIRED = 3,
        DEVICE_NORMAL = 4,
        DEVICE_NOT_REGISTERD = 5,
        DEVICE_NOT_ACTIVED = 6,
        DEVICE_LIMIT_EXCEEDED = 7,
        AUCA_SERVICE_ERROR = 8,
    };
    std::map<StatusCode, std::string> status_code_msg_ = {
            {StatusCode::AGENT_CONNECT_FAIL, "连接鉴权服务失败"},
            {StatusCode::AGENT_START_FAIL, "鉴权agent服务未启动"},
            {StatusCode::AGENT_AUTH_START_FAIL, "鉴权agent服务的鉴权功能未启动"},
            {StatusCode::AGENT_CONNECT_CLOUD_FAIL, "鉴权agent向云端请求失败"},
            {StatusCode::PRODUCT_INS_EXCEEDED, "实例超限"},
            {StatusCode::ASYNC_AUTH_UNSTART, "异步鉴权未开启"},
            {StatusCode::QPS_EXCEEDED, "qps超限"},
            {StatusCode::PRODUCT_UNREGISTERED, "产品未注册"},
    };

private:
    /**
     * @brief register websocket handlers
     */
    void RegisterMessageHandlers();
    nlohmann::json ParseAucaResponse(int& valid);

private:
    CalibStatus status_;
    WebSocketHandler* websocket_;
};
}  // namespace dreamview
}  // namespace apollo
