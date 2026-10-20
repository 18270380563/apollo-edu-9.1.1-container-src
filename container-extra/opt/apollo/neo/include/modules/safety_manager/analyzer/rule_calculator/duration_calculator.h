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
#include <string>
#include <unordered_map>

#include "modules/safety_manager_msgs/safety_manager.pb.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

/**
 * @brief SingleDurationCalculator class maintains a single item status.
 */
class SingleDurationCalculator {
public:
    /**
     * @brief Add by status and duration.
     *
     * @param status SafetyStatus status.
     * @param duration in seconds.
     */
    bool Add(const SafetyStatus_Status& status, const double& duration);

    /**
     * @brief Get the cuurent status.
     */
    const SafetyStatus_Status& GetStatus() {
        return status_;
    }

private:
    SafetyStatus_Status status_ = SafetyStatus_Status_OK;
    double occurred_at;
    std::mutex lock_;
};

/**
 * @brief DurationCalculator class maintains many items status.
 */
class DurationCalculator {
public:
    /**
     * @brief Add by name, status, and duration.
     *
     * @param name SafetyStatus item name.
     * @param status SafetyStatus status.
     * @param duration in seconds.
     */
    bool Add(const std::string& name, const SafetyStatus_Status& status, const double& duration);

    /**
     * @brief Get the cuurent status by name.
     *
     * @param name SafetyStatus item name.
     * @param status The output SafetyStatus status.
     */
    bool GetStatus(const std::string& name, SafetyStatus_Status* status);

private:
    std::unordered_map<std::string, std::unique_ptr<SingleDurationCalculator>> status_map_;
};

}  // namespace safety_manager
}  // namespace apollo
