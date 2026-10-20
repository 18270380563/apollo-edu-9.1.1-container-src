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

#include "modules/safety_manager/checker/collision_checker/proto/collision_checker.pb.h"

#include "modules/safety_manager/checker/collision_checker/adc_predictor.h"
#include "modules/safety_manager/checker/collision_checker/obstacle_predictor.h"

class Result {};

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

using apollo::perception::PerceptionObstacle;
using apollo::prediction::PredictionObstacle;

using BOX2D_SEQ = std::vector<apollo::common::math::Box2d>;
using POLYGON2D_SEQ = std::vector<apollo::common::math::Polygon2d>;

constexpr double TTC_UNKNOWN = -1;

class TTCCalculator {
public:
    /**
     * @brief Load strategy conf.
     */
    void Init(const StrategyConf& conf);

    /**
     * @brief Calculate ttc seconds.
     *
     * @param vehicle_state Vehicle state message.
     * @param obstacle PerceptionObstacle message.
     * @param duration_sec Trajectory duration seconds.
     * @param interval_sec Trajectory interval seconds.
     * @param ttc_sec Output ttc seconds.
     * @return True if get ttc successed.
     */
    bool GetTTC(
            const VehicleStateProvider& vehicle_state,
            const PredictionObstacle& obstacle,
            const double& duration_sec,
            const double& interval_sec,
            double* ttc_sec);

private:
    /**
     * @brief Get adc boxes list, predict trajectory by acc or not.
     * @param vehicle_state Vehicle state message.
     * @param duration_sec Trajectory duration seconds.
     * @param interval_sec Trajectory interval seconds.
     * @param vec Trajectories vector.
     * @return If get adc boxes list successfully.
     */
    bool GetAdcBoxesList(
            const VehicleStateProvider& vehicle_state,
            const double& duration_sec,
            const double& interval_sec,
            std::vector<BOX2D_SEQ>* vec);

    /**
     * @brief Get obstalce polygons list, predict trajectory by prediction,
     * perception or stationary.
     * @param obstacle Prediction obstacle message.
     * @param start_sec Trajectory start seconds.
     * @param duration_sec Trajectory duration seconds.
     * @param interval_sec Trajectory interval seconds.
     * @param vec Trajectories vector.
     * @return If get obstalce polygons list successfully.
     */
    bool GetObstalcePolygonsList(
            const PredictionObstacle& obstacle,
            const double& start_sec,
            const double& duration_sec,
            const double& interval_sec,
            std::vector<POLYGON2D_SEQ>* vec);

    bool CalculateTTC(
            const std::vector<BOX2D_SEQ>& adc_box_seq_list,
            const std::vector<POLYGON2D_SEQ>& obs_polygon_seq_list,
            size_t* index);

    /**
     * @brief Check if obstacles In range.
     * @param vehicle_state Vehicle state message.
     * @param obstacle Perception obstacle message.
     * @return If obstacle in range return true.
     */
    bool IsObstacleInCheckRange(const VehicleStateProvider& vehicle_state, const PredictionObstacle& obstacle);

    const StrategyConf* conf_;
    AdcPredictor adc_predictor_;
    ObstaclePredictor obs_predictor_;
};

}  // namespace safety_manager
}  // namespace apollo
