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

#include <string>
#include <vector>

#include "gtest/gtest_prod.h"

#include "modules/sim_obstacle/agent_server/traffic_light/traffic_light.h"

namespace apollo {
namespace dreamview {

class CyclicalTrafficLight : public SimTrafficLight {
 public:
  CyclicalTrafficLight(const std::string& signal_id, double red_time,
                       double green_time, double yellow_time);

  void Simulate(
      const double& delta_time,
      const apollo::dreamview::common::AdcStatus& adc_status) override;
  void FillTrafficLight(
      apollo::perception::TrafficLight* trafficlight) override;
  bool IsTriggered() override;

 private:
  double red_time_;
  double green_time_;
  double yellow_time_;

  // Color and time of the current traffic light state
  double tracking_time_;
  apollo::perception::TrafficLight::Color current_color_;

  FRIEND_TEST(CyclicalTrafficLightTest, ColorTest);
};

}  // namespace dreamview
}  // namespace apollo
