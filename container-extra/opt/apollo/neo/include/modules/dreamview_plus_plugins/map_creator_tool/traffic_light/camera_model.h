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
#include <memory>
#include <string>

#include "Eigen/Core"

#include "cyber/cyber.h"

namespace apollo {
namespace dreamview {
namespace map_tool {
class CameraModel {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    CameraModel() {}
    bool Init(const std::string &yaml_file);

    /**
     * @brief Get camera image height
     *
     * @return Camera height.
     */
    int GetHeight();

    /**
     * @brief Get camera image width.
     *
     * @return Camera width.
     */
    int GetWidth();

    /**
     * @brief Get camera intrinsic params.
     *
     * @return A camera intrinsic matrix.
     */
    Eigen::Matrix3f GetIntrinsicParams();

    /**
     * @brief Project a world 3d point to camera coordinate system
     *
     * @return A 3d point.
     */
    Eigen::Vector2i Project(const Eigen::Vector3f &point3d);

private:
    bool LoadIntrinsic(const std::string &yaml_file);
    void SetParams(const Eigen::VectorXf &params);

private:
    int camera_width_ = 0;
    int camera_height_ = 0;
    Eigen::Matrix3f intrinsic_params_;
    Eigen::Matrix<float, 8, 1> distort_params_;
};

}  // namespace map_tool
}  // namespace dreamview
}  // namespace apollo