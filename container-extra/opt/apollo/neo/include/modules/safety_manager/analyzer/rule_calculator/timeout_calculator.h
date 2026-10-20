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

#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

#include "modules/safety_manager_msgs/safety_manager.pb.h"

#include "cyber/common/macros.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

const double DEFAULT_TIMEOUT = 1;
using STATUS_TIMEOUT_PAIR = std::pair<SafetyStatus_Status, uint64_t>;

/**
 * @brief TimeoutCalculator class maintains many items status.
 */
class TimeoutCalculator {
public:
    /**
     * @brief Add by name, status, and timeout.
     *
     * @param name SafetyStatus item name.
     * @param status SafetyStatus status.
     * @param timeout In seconds.
     */
    bool Add(const std::string& name, const SafetyStatus_Status& status, const double& timeout);

    /**
     * @brief Remove a item by name
     *
     * @param name SafetyStatus item name.
     */
    void Remove(const std::string& name);

    /**
     * @brief Get the cuurent status by name.
     */
    const SafetyStatus_Status GetStatus();

    /**
     * @brief Get status and timeout timestamp by name.
     *
     * @param name SafetyStatus item name.
     * @param pair A pair of status and timeout timestamp.
     */
    bool GetStatusTimeoutByname(const std::string& name, STATUS_TIMEOUT_PAIR* pair);

private:
    std::unordered_map<SafetyStatus_Status, double> timeout_map_{
            {SafetyStatus_Status_OK, 0.0},
            {SafetyStatus_Status_WARN, 0.0},
            {SafetyStatus_Status_ERROR, 0.0},
            {SafetyStatus_Status_FATAL, 0.0}};
    std::unordered_map<std::string, STATUS_TIMEOUT_PAIR> item_map_;
    std::mutex lock_;
};

}  // namespace safety_manager
}  // namespace apollo
