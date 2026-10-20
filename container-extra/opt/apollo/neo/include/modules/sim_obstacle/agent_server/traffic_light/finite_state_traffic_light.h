/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

#include "modules/common_msgs/simulation_msgs/scenario.pb.h"
#include "modules/common_msgs/perception_msgs/traffic_light_detection.pb.h"

#include "modules/sim_obstacle/agent_server/common/common.h"
#include "modules/sim_obstacle/agent_server/traffic_light/traffic_light.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

class FiniteStateTrafficLight : public SimTrafficLight {
 public:
  FiniteStateTrafficLight(const std::string& signal_id,
                          const apollo::simulation::Scenario::TL& traffic_light_config)
      : SimTrafficLight(signal_id),
        config_(traffic_light_config),
        triggered_(false),
        current_state_(traffic_light_config.initial_state()),
        current_state_index_(-1),
        time_in_current_state_(0) {}

  void Simulate(const double& delta_time,
                const common::AdcStatus& adc_status) override;
  void FillTrafficLight(
      apollo::perception::TrafficLight* traffic_light) override;

  bool IsTriggered() override;

 private:
  void MoveToNextState();

  const apollo::simulation::Scenario::TL config_;

  bool triggered_;
  apollo::simulation::Scenario::TL::State current_state_;
  int current_state_index_;
  double time_in_current_state_;
};

}  // namespace dreamview
}  // namespace apollo
