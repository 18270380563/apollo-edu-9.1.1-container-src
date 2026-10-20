/******************************************************************************
 * Copyright 2024 The Apollo Authors. All Rights Reserved.
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

#include "modules/dreamview_plus_plugins/map_creator_tool/proto/error_code.pb.h"

#include "modules/common/util/json_util.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/traffic_light/traffic_light_processor.h"

namespace apollo {
namespace dreamview {
class TrafficLightService {
public:
    explicit TrafficLightService(WebSocketHandler *websocket) : websocket_(websocket) {
        RegisterMessageHandlers();
        Init();
    };
    void Init();

    /**
     * @brief Register websocket handlers.
     */
    void RegisterMessageHandlers();

private:
    WebSocketHandler *websocket_ = nullptr;
    std::unique_ptr<TrafficLightProcessor> tl_processor_ptr_ = nullptr;
};

}  // namespace dreamview
}  // namespace apollo
