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

/**
 * @file
 */

#pragma once

#include <memory>

#include "cyber/common/macros.h"
#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"

#include "modules/common_msgs/chassis_msgs/chassis.pb.h"
#include "modules/common_msgs/control_msgs/control_cmd.pb.h"
#include "modules/common_msgs/guardian_msgs/guardian.pb.h"
#include "modules/common_msgs/monitor_msgs/system_status.pb.h"
#include "modules/safety_manager_msgs/safety_manager.pb.h"
#include "modules/safety_manager/guardian/proto/guardian_conf.pb.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

class SafetyGuardianComponent : public apollo::cyber::TimerComponent {
public:
    bool Init() override;
    bool Proc() override;

private:
    void PassThroughControlCommand();
    void TriggerSafetyMode();

    apollo::safety_manager::GuardianConf guardian_conf_;
    apollo::canbus::Chassis chassis_;
    SafetyDecision decision_;
    apollo::control::ControlCommand control_cmd_;
    apollo::guardian::GuardianCommand guardian_cmd_;

    double last_status_received_s_{};

    std::shared_ptr<apollo::cyber::Reader<apollo::canbus::Chassis>> chassis_reader_;
    std::shared_ptr<apollo::cyber::Reader<apollo::control::ControlCommand>> control_cmd_reader_;
    std::shared_ptr<apollo::cyber::Reader<SafetyDecision>> decision_reader_;
    std::shared_ptr<apollo::cyber::Writer<apollo::guardian::GuardianCommand>> guardian_writer_;

    bool in_rtkplay_mode_ = false;
    std::mutex mutex_;
};

CYBER_REGISTER_COMPONENT(SafetyGuardianComponent)

}  // namespace safety_manager
}  // namespace apollo
