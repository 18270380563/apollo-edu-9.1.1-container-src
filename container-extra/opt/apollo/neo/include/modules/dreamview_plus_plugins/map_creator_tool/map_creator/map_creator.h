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

#include "modules/drivers/gnss/proto/config.pb.h"

#include "cyber/common/file.h"
#include "cyber/common/time_conversion.h"
#include "cyber/cyber.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/common/map_creator_gflags.h"
#include "modules/private_tools/map_tool/common/map_tool_gflags.h"
#include "modules/private_tools/tile_map_images_creator/common/image_creator_flags.h"
#include "modules/private_tools/tile_map_images_creator/images_creator/images_creator.h"
/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class MapCreator
 * @brief A map creator tool
 */
class MapCreator {
public:
    /**
     * @brief A callback function that feedbacks the map generation progress.
     *
     * @param float Map generation progress.
     * @param string Description of map generation conditions.
     */
    using Callback = std::function<void(const float &, const std::string &)>;
    explicit MapCreator(std::string input_dir, std::string mapping_mode);
    virtual ~MapCreator() = default;

    /**
     * @brief Call the initialization function of the map generation tool.
     */
    bool Init();

    /**
     * @brief Interface for running map generation tools.
     *
     * @param Callback Callback function for map generation status.
     */
    bool Run(const Callback &progress_callback);
    void Stop();

    /**
     * @brief Get Images creator status.
     * @return True if Images creator is running else false.
     */
    bool GetImagesCreatorStatus();

private:
    // map create method
    std::unique_ptr<apollo::tile_map_images_creator::ImagesCreator> images_creator_ = nullptr;
    apollo::tile_map_images_creator::ImagesCreatorConf conf_;
    std::string input_dir_;
    std::string mapping_mode_;
    std::string slam_pose_dir_;
    std::pair<double, double> latitude_range_;
    std::pair<double, double> longitude_range_;
    bool enable_images_creator_ = true;
    bool is_creating_ = false;
    bool LoadImageCreatorConf();
    bool InitImagesCreator();
    void SetMappingModeFilePath();
};
}  // namespace dreamview
}  // namespace apollo
