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
 *****************************************************************************/

/**
 * @file
 */

#pragma once

#include <memory>
#include <regex>
#include <string>
#include <vector>

#include "CivetServer.h"

#include "cyber/common/log.h"
#include "cyber/cyber.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/common/map_creator_gflags.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/map_creator/map_creator_service.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/traffic_light/traffic_light_processor.h"
#include "modules/private_tools/map_tool/common/map_tool_gflags.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */

namespace apollo {
namespace dreamview {

/**
 * @class
 * @brief The class of MapCreatorHandler. Build on top of CiveHandler.
 */
class MapCreatorHandler : public CivetHandler {
public:
    MapCreatorHandler();

    /**
     * @brief Callback method for map creator handler HTTP GET request.
     *
     * @param server The calling server.
     * @param conn The connection information.
     *
     * @return True if implemented, false otherwise.
     */
    bool handleGet(CivetServer *server, struct mg_connection *conn) override;

private:
    std::string base_map_root_path_;
    void InitHandler();

    bool HandlePng(struct mg_connection *conn, std::string request_params, bool if_traffic_light = false);
    bool HandleJson(struct mg_connection *conn, std::string request_params, char *mode_str);

    /**
     * @brief Get params from a http request.
     * @param pattern The pattern to extract params.
     * @param request_params The params string to be extracted.
     * @param request_uri The uri to extract params.
     * @return If extract params successfully, return true.
     */
    bool GetUriParams(std::regex pattern, std::string &request_params, const char *request_uri);
};

}  // namespace dreamview
}  // namespace apollo
