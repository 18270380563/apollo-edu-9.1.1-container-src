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

#include <map>
#include <memory>
#include <string>

#include "modules/common_msgs/chassis_msgs/chassis.pb.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/perception_msgs/perception_obstacle.pb.h"
#include "modules/safety_manager_msgs/safety_manager.pb.h"
#include "modules/safety_manager/checker/collision_checker/proto/collision_checker.pb.h"

#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"
#include "modules/common/vehicle_state/vehicle_state_provider.h"
#include "modules/safety_manager/checker/collision_checker/ttc_calculator.h"
#include "modules/safety_manager/exporter/exporter.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

using apollo::canbus::Chassis;
using apollo::common::VehicleStateProvider;
using apollo::localization::LocalizationEstimate;
using apollo::perception::PerceptionObstacles;
using apollo::prediction::PredictionObstacles;

class CollisionCheckerComponent : public cyber::TimerComponent {
public:
    bool Init() override;

    bool Proc() override;

private:
    void CreateReaders();
    bool IsExpired(const double& msg_sec, const double& now_sec);
    const StrategyConf& GetStrategyConf();
    SafetyStatus_Status GetSafetyStatus(const double& ttc);

    // collision check
    void CollisionCheck(const std::shared_ptr<PredictionObstacles>& obstacles);

    std::shared_ptr<cyber::Reader<LocalizationEstimate>> localization_reader_;
    std::shared_ptr<cyber::Reader<Chassis>> chassis_reader_;
    std::shared_ptr<cyber::Reader<PredictionObstacles>> obstacles_reader_;

    std::mutex lock_;

    CollisionCheckerConf conf_;
    std::unique_ptr<SafetyExporter> exporter_ = nullptr;
    std::shared_ptr<cyber::Writer<TTCResult>> ttc_writer_;

    VehicleStateProvider vehicle_state_;
    TTCCalculator ttc_calculator_;
};

CYBER_REGISTER_COMPONENT(CollisionCheckerComponent)

}  // namespace safety_manager
}  // namespace apollo
