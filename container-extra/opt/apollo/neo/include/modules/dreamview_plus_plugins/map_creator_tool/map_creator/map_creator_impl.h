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

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "modules/dreamview_plus_plugins/map_creator_tool/proto/error_code.pb.h"

#include "cyber/common/file.h"
#include "modules/common/math/vec2d.h"
#include "modules/common/util/json_util.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/common/map_creator_gflags.h"
#include "modules/private_tools/map_tool/common/common.h"
#include "modules/private_tools/map_tool/converter.h"
namespace apollo {
namespace dreamview {

/**
 * @brief Get all editor map files.
 *
 * @param json output json with file list.
 *
 * @return true if success.
 */
bool GetMapFileList(nlohmann::json &json);

/**
 * @brief Get base map directory.
 *
 * @param json output json with base map directory.
 *
 * @return true if success.
 */
bool GetBaseMapDir(nlohmann::json &json);

/**
 * @brief Release apollo map from json.
 *
 * @param json input json with map data.
 * @param file_name output map file name.
 *
 * @return The status code.
 */
apollo::dreamview::maptool::ErrorCode ReleaseApolloMap(
        const nlohmann::json &json,
        const std::string &file_name,
        nlohmann::json *error_message);

/**
 * @brief Save editor map from json.
 *
 * @param file_name output map file name.
 * @param json input json with map data.
 */
bool SaveEditorMap(const std::string &file_name, const nlohmann::json &json);

/**
 * @brief Load editor map from file.
 *
 * @param file_name input map file name.
 * @param json output json with map data.
 *
 * @return true if success.
 */
bool LoadEditorMap(const std::string &file_name, nlohmann::json &json);

/**
 * @brief Check map file if has same file at local.
 *
 * @param file_type file_type File types that will be checked. File types
 * include editor map and hdmap.
 * @param file_name input map file name.
 *
 * @return true if has same file.
 */
bool CheckFileIfDuplicated(const std::string file_type, const std::string &file_name);

/**
 * @brief File directory processing function, sort the file directory and filter
 * out hidden files.
 *
 * @param file_list Input file list.
 *
 * @return Processed file directory list.
 */
std::vector<std::string> ProcessFileDirectories(std::vector<std::string> &file_list);

/**
 * @brief Execute system commands.
 *
 * @param cmd The system command.
 *
 * @return Return true if executed successfully, otherwise, false.
 */
bool System(std::string &cmd);

/**
 * @brief Check if the process is running normally
 *
 * @return True if process is running.
 */
bool CheckProcessIfRunning(std::string &process_name);

/**
 * @brief Get account info from the studio_connector(Dv login plug-in).
 *
 * @param service_name service name, such as "mapTool"
 * @param account_info A json object containing all user information
 *
 * @return Return true if get account info success from shm.
 */
bool GetShmAccountInfo(const char *service_name, const uint64_t &info_size, nlohmann::json *res);

}  // namespace dreamview
}  // namespace apollo
