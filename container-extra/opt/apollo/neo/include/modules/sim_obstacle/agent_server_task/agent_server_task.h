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

#include <memory>

#include "modules/sim_obstacle/agent_server/agent_server.h"
#include "modules/sim_obstacle/agent_server/multi_agent_server.h"
#include "modules/common_msgs/simulation_msgs/scenario.pb.h"

namespace apollo {
namespace dreamview {

class AgentServerTask {
 public:
  AgentServerTask(const apollo::simulation::Scenario* scenario_conf);

  std::string Name() const { return "AgentServer"; }

  apollo::common::Status Init();

  apollo::common::Status RunOnce(const double& sim_start_time);

 private:
  const double frequency_ms_ = 100;

  const apollo::simulation::Scenario* scenario_conf_;
  std::unique_ptr<AgentServer> agent_server_;
  std::unique_ptr<MultiAgentServer> multi_agent_server_;
  bool multi_agent_mode_ = false;
};

}  // namespace dreamview
}  // namespace apollo
