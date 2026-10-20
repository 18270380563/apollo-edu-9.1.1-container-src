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

#include <queue>

#include "modules/sim_obstacle/agent_server/agent/ai_agent.h"
#include "modules/sim_obstacle/agent_server/agent_server.h"
/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
using apollo::planning::ReferenceLine;

namespace apollo {
namespace dreamview {

/**
 * @class MultiAgentServer
 *
 * @brief Agent Server module main class. It reads configuration and scenario
 * files and produces simulated perception obstacles / traffic lights.
 */
struct AgentSequence {
  ReferenceLine path;
  double cruise_speed;
  double max_dec;
  apollo::simulation::AgentConfig agent_config;
  double next_safe_distance;
  std::vector<std::shared_ptr<AiAgent>> agents;
};
class MultiAgentServer : public AgentServer {
 public:
  MultiAgentServer(const apollo::simulation::Scenario* scenario, const double& frequency_ms)
      : AgentServer(scenario, frequency_ms){};
  std::string Name() const;
  void RunOnce(const double& sim_start_time);
  apollo::common::Status Init();

 private:
  double GetRandomDistance(double cruise_speed, double max_dec,
                           double agent_length);
  bool ParseAgents();
  void AddAgent();
  void RemoveAgent();
  void PublishPerceptionObstacles();
  double next_speed_ = rand() / double(RAND_MAX) * 5 + 10;
  std::vector<AgentSequence> agent_sequences_;
  int obs_id_ = 0;
};

}  // namespace dreamview
}  // namespace apollo
