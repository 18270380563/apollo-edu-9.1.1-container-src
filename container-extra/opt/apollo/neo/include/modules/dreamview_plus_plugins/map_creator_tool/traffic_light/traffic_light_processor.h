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

#include <unordered_map>

#include "Eigen/Core"
#include "opencv2/opencv.hpp"

#include "modules/common_msgs/basic_msgs/geometry.pb.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/sensor_msgs/sensor_image.pb.h"
#include "modules/private_tools/map_tool/proto/editor_map.pb.h"
#include "modules/private_tools/tile_map_images_creator/proto/images_creator_conf.pb.h"

#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common/math/line_segment2d.h"
#include "modules/common/util/json_util.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/common/map_creator_gflags.h"
#include "modules/dreamview_plus_plugins/map_creator_tool/traffic_light/camera_model.h"
#include "modules/private_tools/map_tool/common/map_tool_gflags.h"
#include "modules/private_tools/map_tool/converter.h"
#include "modules/private_tools/tile_map_images_creator/common/image_creator_flags.h"
#include "modules/transform/buffer.h"

namespace apollo {
namespace dreamview {
namespace map_tool {

struct CarInfo {
    double heading = 0;
    common::PointENU pose;
};

/**
 * @struct TrafficLight
 * @brief A struct to store traffic light info.
 */
struct TrafficLight {
    apollo::common::math::LineSegment2d stop_line;
    std::vector<common::PointENU> polygon;
    TrafficLight(const apollo::hdmap::Signal& signal) {
        polygon.assign(signal.boundary().point().begin(), signal.boundary().point().end());
        const auto& line_segment = signal.stop_line(0).segment(0).line_segment();
        apollo::common::math::LineSegment2d segment(
                {line_segment.point(0).x(), line_segment.point(0).y()},
                {line_segment.point(1).x(), line_segment.point(1).y()});
        stop_line = std::move(segment);
    }
};

}  // namespace  map_tool

/**
 * @class TrafficLightProcessor class
 * @brief Designed for calculating the coordinate of traffic light.
 */
class TrafficLightProcessor {
public:
    TrafficLightProcessor() : node_(apollo::cyber::CreateNode("map_tf_processor")) {}

    bool Init();

    /**
     * @brief Create a camera model with a camera intrinsic yaml.
     *
     * @param camera_intrinsic_yaml camera intrinsic yaml file path.
     *
     * @return true if create camera model success.
     */
    bool CreateCameraModel(const std::string& camera_intrinsic_yaml);

    /**
     * @brief Get traffic light proc image.
     *
     * @param image the proj image
     * @param pose the transformation matrix of camera2world.
     *
     * @return Return true if project image calculate success.
     */
    bool GetProjImage(
            cv::Mat& image,
            const Eigen::Matrix4d& pose,
            const std::vector<common::PointENU>& points,
            const std::string& path);

    /**
     * @brief Save camera image, car pose, camera2world pose at the same time.
     *
     * @param res the output response json with all be captured data path.
     *
     * @return Return true if capture a frame data success.
     */
    bool CaptureFrameData(nlohmann::json* res);

    /**
     * @brief Find all project image
     *
     * @param map_json a map json include a traffic info.
     * @param res the output response json include all valid project image paths.
     *
     * @return Return true if search project image success.
     */
    bool SearchProjectImage(const nlohmann::json& map_json, nlohmann::json* res);

    /**
     * @brief Create all car pose table when base map be changed.
     */
    static void CreatePoseTable();

private:
    bool CaptureImage();
    bool CaptureCarPose(const localization::LocalizationEstimate& loc);
    bool CaptureC2WPose();
    bool CreateDir();
    bool LoadConfig();
    /**
     *@brief Calculate the difference between angle from and to
     *@param heading_1 form
     *@param heading_2 to
     *@return The difference between from and to. The range is between [0, PI).
     */
    double CalculateHeadingDeltaAngle(const double& heading_1, const double& heading_2);
    std::vector<std::string> FindRelationImage(const map_tool::TrafficLight& traffic_light);
    void SetCurrImagePrt(std::shared_ptr<drivers::Image>& image_ptr);

private:
    apollo::transform::Buffer* tf_buffer = apollo::transform::Buffer::Instance();
    std::mutex image_mutex_;
    std::shared_ptr<apollo::cyber::Reader<drivers::Image>> camera_reader_ = nullptr;
    std::shared_ptr<apollo::cyber::Reader<localization::LocalizationEstimate>> loc_pose_reader_ = nullptr;
    std::string curr_sub_file_dir_ = "";
    std::unique_ptr<cyber::Node> node_ = nullptr;
    std::unique_ptr<map_tool::CameraModel> camera_model_ = nullptr;
    std::vector<std::string> sub_dirs_;
    std::vector<uint8_t> image_buffer_;
    tile_map_images_creator::ImagesCreatorConf conf_;
    double car2stopline_max_distance_ = 5;
    double car2stopline_max_rad_ = M_PI / 4;
    std::shared_ptr<drivers::Image> curr_image_ptr_;
};

}  // namespace dreamview
}  // namespace apollo