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
#include "modules/planning/planning_base/reference_line/reference_line.h"
using apollo::planning::ReferenceLine;
namespace apollo {
namespace dreamview {
class AiAgent : public Agent {
 public:
  AiAgent(apollo::simulation::AgentConfig config, ReferenceLine& path, double cruise_speed,
          double max_dec, double safe_distance)
      : Agent(config),
        path_(path),
        cruise_speed_(cruise_speed),
        max_dec_(max_dec),
        safe_distance_(safe_distance){
          v_ = cruise_speed_;
        };

  void SetLastAgent(std::shared_ptr<AiAgent> last);
  void Simulate(const double& delta_t,
                const common::AdcStatus& adc_status) override;
  void CalculateNextParams(const double& delta_t);
  double curr_s = 0;

 private:
  bool IsAdcBlocked(const common::AdcStatus& adc_status, double& adc_s);
  double GetAcceleration(const double& target_x, const double& target_y,
                         const double& target_v);
  void Freeze(const std::string& msg);
  std::shared_ptr<AiAgent> last_agent_ = nullptr;
  ReferenceLine path_;
  double cruise_speed_;
  double max_dec_;
  double safe_distance_;
  double a_ = 0;
};

}  // namespace dreamview
}  // namespace apollo
