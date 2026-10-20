/******************************************************************************
 * Copyright 2023 The Apollo Authors. All Rights Reserved.
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

#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/safety_manager_msgs/safety_manager.pb.h"
#include "modules/slam_local/proto/odometry.pb.h"

#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"
#include "modules/safety_manager/checker/localization_checker/localization_checker_gflags.h"
#include "modules/safety_manager/exporter/exporter.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

class LocalizationCheckerComponent : public cyber::TimerComponent {
public:
    bool Init() override;
    bool Proc() override;

private:
    /**
     * @brief Create LocalizationStatus reader
     */
    void CreateReaders();

    /**
     * @brief Check localization measure status and convert to safety status
     */
    void CheckMsfStatus();

    /**
     * @brief Check  slam localization status and convert to safety status
     */
    void CheckSlamStatus();

    /**
     * @brief Set safety status error or fatal.
     * @param status_level Numbers range 1 to 3
     * @return return fatal when level is above threshold, otherwise return error
     */
    SafetyStatus_Status SetErrorOrFatalStatus(uint32_t status_level);

    std::unique_ptr<SafetyExporter> exporter_ = nullptr;
    std::shared_ptr<apollo::localization::LocalizationStatus> localization_status_ = nullptr;
    std::mutex msf_lock_;
    std::shared_ptr<apollo::slam_local::SlamOdometry> slam_odometry_ = nullptr;
    std::mutex slam_lock_;
};

CYBER_REGISTER_COMPONENT(LocalizationCheckerComponent)

}  // namespace safety_manager
}  // namespace apollo
