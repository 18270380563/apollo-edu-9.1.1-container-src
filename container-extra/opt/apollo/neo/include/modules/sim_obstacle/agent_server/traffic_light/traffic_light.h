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

#include "modules/common_msgs/perception_msgs/traffic_light_detection.pb.h"

#include "modules/sim_obstacle/agent_server/common/common.h"
#include "modules/sim_obstacle/agent_server_common/include_option.h"

namespace apollo {
namespace dreamview {

class SimTrafficLight {
 public:
  SimTrafficLight(const std::string& signal_id) : signal_id_(signal_id){};
  virtual ~SimTrafficLight() = default;

  const std::string& signal_id() const { return signal_id_; }

  virtual void Simulate(const double& delta_time,
                        const common::AdcStatus& adc_status) = 0;
  virtual void FillTrafficLight(
      apollo::perception::TrafficLight* trafficlight) = 0;
  virtual bool IsTriggered() = 0;

 private:
  const std::string signal_id_;
};

}  // namespace dreamview
}  // namespace apollo
