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

#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/safety_manager/checker/collision_checker/proto/collision_checker.pb.h"

#include "modules/common/math/box2d.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

using apollo::common::VehicleStateProvider;

/**
 * @brief Used to generate the auto-driving-car predicting trajectories.
 */
class AdcPredictor {
public:
    /**
     * @brief Load some configuration about strategy.
     */
    void Init(const double& front_extend, const double& back_extended, const double& lateral_extended);

    /**
     * @brief Get trajectory box list by adc velocity info
     */
    bool PredictWithVelocity(
            const VehicleStateProvider& vehicle_state,
            const double& duration_sec,
            const double& interval_sec,
            std::vector<common::math::Box2d>* box_seq);

    bool PredictWithAcceleration(
            const VehicleStateProvider& vehicle_state,
            const double& duration_sec,
            const double& interval_sec,
            const double& accelerate_sec,
            std::vector<common::math::Box2d>* box_seq);

public:
    common::math::Vec2d GetShiftVec2d(const VehicleStateProvider& vehicle_state, const double& interval_sec);

    common::math::Vec2d GetShiftVec2d(
            const double& velocity,
            const double& accelerate,
            const double& heading,
            const double& interval_sec);

    common::math::Box2d GetVehicleBox(const VehicleStateProvider& vehicle_state);

    common::math::Box2d GetVehicleBox(const double& x, const double& y, const double& heading);

    double adc_front_extended_len_;
    double adc_back_extended_len_;
    double adc_lateral_extended_len_;
};

}  // namespace safety_manager
}  // namespace apollo
