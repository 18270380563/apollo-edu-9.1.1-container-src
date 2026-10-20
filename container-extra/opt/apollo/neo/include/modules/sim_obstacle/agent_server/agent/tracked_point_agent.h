/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

#include "modules/sim_obstacle/agent_server/agent/agent.h"
#include "modules/sim_obstacle/agent_server_common/map/map_util.h"
namespace apollo {
namespace dreamview {

class TrackedPointAgent : public Agent {
 public:
  TrackedPointAgent(const apollo::simulation::AgentConfig& agent);

  void Simulate(const double& delta_t,
                const common::AdcStatus& adc_status) override;
  void CalculateNextParams(const double& delta_t);

 private:
  double GetAcceleration(const double& target_x, const double& target_y,
                         const double& target_v);
  bool IsNearCar(const common::AdcStatus& adc_status);
  bool IsNearCrosswalk();
  bool IsBehind(const common::AdcStatus& adc_status,
                const double region_length = 50.0, const double region_width = 15.0);
  void Freeze(const std::string& msg);

  int current_point_index_;
  bool is_near_car_ = false;
  bool is_near_crosswalk_ = false;
};

}  // namespace dreamview
}  // namespace apollo
