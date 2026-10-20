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

#include "gtest/gtest_prod.h"

#include "modules/common_msgs/simulation_msgs/agent.pb.h"
#include "modules/common_msgs/perception_msgs/perception_obstacle.pb.h"

#include "modules/sim_obstacle/agent_server/common/common.h"

namespace apollo {
namespace dreamview {

class Agent {
 public:
  Agent(const apollo::simulation::AgentConfig& agent);
  virtual ~Agent() = default;

  double x() const { return x_; }

  double y() const { return y_; }

  double v() const { return v_; }

  double id() const { return agent_.id(); }

  apollo::simulation::AgentConfig::Type type() const { return agent_.type(); }

  double angle() const { return angle_; }

  bool start_flag() const { return start_flag_; }

  double width() const { return agent_.width(); }
  double length() const { return agent_.length(); }

  void CheckStart(const common::AdcStatus& adc_status, const double& sim_start_time);

  void WriteLog();
  void FillPerceptionObstacle(apollo::perception::PerceptionObstacle* obstacle);

  virtual void Simulate(const double& delta_t,
                        const common::AdcStatus& adc_status) = 0;
  static void ClearAgent() { agents_.clear(); }
  static void AddAgent(std::shared_ptr<Agent> agent) { agents_.emplace_back(agent); }

 protected:
  apollo::simulation::AgentConfig agent_;
  static std::vector<std::shared_ptr<Agent>> agents_;
  double x_;
  double y_;
  double v_;
  double angle_;
  bool start_flag_;

 private:
  void SetStartFlag();

  FRIEND_TEST(TrackedPointAgentTest, ZeroTrackedPoints);
  FRIEND_TEST(TrackedPointAgentTest, ReachEnd);
  FRIEND_TEST(TrackedPointAgentTest, PositiveAcceleration);
  FRIEND_TEST(TrackedPointAgentTest, NegativeAcceleration);
  FRIEND_TEST(TrackedPointAgentTest, ZeroAcceleration);
  FRIEND_TEST(TrackedPointAgentTest, MultipleAcceleration);
  FRIEND_TEST(TrackedPointAgentTest, MoveExactlyAlongTrackedPoints);
};

std::vector<std::shared_ptr<Agent>> Agent::agents_;

}  // namespace dreamview
}  // namespace apollo
