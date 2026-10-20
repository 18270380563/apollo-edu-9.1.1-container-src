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

#pragma once

#include <vector>

#include "modules/common_msgs/perception_msgs/perception_obstacle.pb.h"
#include "modules/common_msgs/prediction_msgs/prediction_obstacle.pb.h"

#include "modules/common/math/polygon2d.h"
#include "modules/common/math/vec2d.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

using apollo::perception::PerceptionObstacle;
using apollo::prediction::PredictionObstacle;
using POLYGON2D_SEQ = std::vector<apollo::common::math::Polygon2d>;

class ObstaclePredictor {
public:
    void Init();

    bool PredictWithPrediction(
            const PredictionObstacle& obstacle,
            const double& start_sec,
            const double& duration_sec,
            const double& interval_sec,
            std::vector<std::vector<common::math::Polygon2d>>* polygon_seqs);

    bool PredictWithVelocity(
            const PerceptionObstacle& obstacle,
            const double& start_sec,
            const double& duration_sec,
            const double& interval_sec,
            std::vector<common::math::Polygon2d>* polygon_seq);

    bool PredictWithStationary(
            const PerceptionObstacle& obstacle,
            const double& start_sec,
            const double& duration_sec,
            const double& interval_sec,
            std::vector<common::math::Polygon2d>* polygon_seq);

private:
    common::math::Polygon2d GetObstaclePolygon(const PerceptionObstacle& obstacle);

    common::math::Polygon2d GetObstaclePolygon(const PerceptionObstacle& obstacle, const double& start_sec);

    common::math::Vec2d GetShiftVec2d(const PerceptionObstacle& obstacle, const double& interval_sec);

    common::math::Vec2d GetShiftVec2d(const PerceptionObstacle& obstacle, const double& x, const double& y);

    common::math::Polygon2d GetShiftPolygon(const common::math::Polygon2d& polygon, const common::math::Vec2d& shift);
};

}  // namespace safety_manager
}  // namespace apollo
