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
#include <string>
#include <unordered_map>
#include <vector>

#include "modules/common_msgs/simulation_msgs/scenario.pb.h"

#include "cyber/cyber.h"
#include "modules/common/status/status.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/perception_msgs/traffic_light_detection.pb.h"
#include "modules/sim_obstacle/agent_server/agent/agent.h"
#include "modules/sim_obstacle/agent_server/common/common.h"
#include "modules/sim_obstacle/agent_server/traffic_light/traffic_light.h"
#include "modules/map/hdmap/hdmap.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

using apollo::simulation::Scenario;

/**
 * @class AgentServer
 *
 * @brief Agent Server module main class. It reads configuration and scenario
 * files and produces simulated perception obstacles / traffic lights.
 */
class AgentServer {
 public:
  AgentServer(const apollo::simulation::Scenario* scenario, const double& frequency_ms)
      : scenario_(scenario),
        frequency_ms_(frequency_ms),
        node_(cyber::CreateNode("agent_server")) {};
  std::string Name() const;
  apollo::common::Status Init();
  void RunOnce(const double& sim_start_time);

 protected:
  void OnLocalization(
      const apollo::localization::LocalizationEstimate& localization);
  const apollo::simulation::Scenario::TL* MatchTrafficLight(
      const apollo::hdmap::SignalInfoConstPtr& signal);
  bool ParseAgents();
  bool ParseTrafficLights();
  void PublishPerceptionObstacles();
  void PublishTrafficLightDetection();
  void InitReadersAndWriters();

  const apollo::simulation::Scenario* scenario_;
  const double frequency_ms_;
  std::vector<std::shared_ptr<Agent>> agents_;
  std::unordered_map<std::string, std::unique_ptr<SimTrafficLight>>
      traffic_lights_;
  common::AdcStatus adc_status_;

  std::unique_ptr<cyber::Node> node_;
  std::shared_ptr<cyber::Reader<apollo::localization::LocalizationEstimate>>
      localization_reader_;
  std::shared_ptr<
      apollo::cyber::Writer<apollo::perception::TrafficLightDetection>>
      traffic_light_detection_writer_;
  std::shared_ptr<
      apollo::cyber::Writer<apollo::perception::PerceptionObstacles>>
      perception_obstacles_writer_;
};

}  // namespace dreamview
}  // namespace apollo
