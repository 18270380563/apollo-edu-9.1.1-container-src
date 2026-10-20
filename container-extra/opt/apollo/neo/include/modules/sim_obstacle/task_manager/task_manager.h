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

#include <string>

#include "google/protobuf/util/json_util.h"
#include "nlohmann/json.hpp"

#include "cyber/cyber.h"
#include "modules/common/adapters/adapter_gflags.h"
#include "modules/common_msgs/perception_msgs/traffic_light_detection.pb.h"
#include "modules/sim_obstacle/agent_server_task/agent_server_task.h"
#include "modules/common_msgs/external_command_msgs/command_status.pb.h"
#include "modules/common_msgs/external_command_msgs/lane_follow_command.pb.h"
#include "modules/common_msgs/simulation_msgs/scenario.pb.h"

namespace apollo {
namespace dreamview {
using apollo::localization::LocalizationEstimate;

class TaskManager {
 public:
  explicit TaskManager(std::string map_dir_prefix, std::string scenario_path, std::string is_publish_command);

  // ~TaskManager();
  // use default disconstruct function

  // return exec total time
  double ExecuteNextAgentServerTask();

  apollo::simulation::Scenario scenario_conf_;

 private:
  void Init();

  void InitTimerAndIO();

  bool ConstructScenario(const nlohmann::json& json, apollo::simulation::Scenario* scenario);

  void ReadScenarioConf();

  void CreateAgentServerTask();

  void PublishLocalization();

  void SendLanesFollow();

  void OnPlanningCommand(
      const std::shared_ptr<apollo::planning::PlanningCommand>& planning_command);

  void Reset();

  // agent server task
  std::unique_ptr<AgentServerTask> agent_server_task_;

  std::unique_ptr<cyber::Node> node_;

  std::string map_dir_prefix_;

  std::string scenario_path_;

  bool enabled_ = false;
  
  bool send_command_ = false;

  std::shared_ptr<cyber::Reader<apollo::planning::PlanningCommand>>
      planning_command_reader_;
  std::shared_ptr<
      apollo::cyber::Client<apollo::external_command::LaneFollowCommand,
                            apollo::external_command::CommandStatus>>
      lane_follow_command_client_;
  // basic time for obstacle trigger
  double sim_start_time_;

  std::string is_publish_command_;
};

}  // namespace dreamview
}  // namespace apollo