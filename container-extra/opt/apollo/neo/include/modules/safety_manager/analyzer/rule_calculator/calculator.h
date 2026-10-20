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

#include <string>
#include <unordered_map>

#include "modules/safety_manager_msgs/safety_manager.pb.h"

#include "cyber/common/macros.h"
#include "modules/safety_manager/analyzer/rule_calculator/duration_calculator.h"
#include "modules/safety_manager/analyzer/rule_calculator/filter_calculator.h"
#include "modules/safety_manager/analyzer/rule_calculator/timeout_calculator.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

/**
 * @brief RuleCalculator class is used for calculating the real status by
 * SafetyStatus Rule config.
 */
class RuleCalculator {
public:
    /**
     * @brief Add a safety_status into the RuleCalculator instance.
     */
    void Add(const SafetyStatus& safety_status);

    /**
     * @brief Get the highest level status of all the safety_status items.
     */
    SafetyStatus_Status GetStatus();

    /**
     * @brief Get the real status by item name.
     *
     * @param name SafetyStatus item name.
     * @param status Output SafetyStatus instance.
     *
     * @returns Return false if item not found by the name.
     */
    bool GetStatusByName(const std::string& name, SafetyStatus_Status* status);

private:
    void UpdateStatus(const std::string& name, const SafetyStatus_Status& status);
    TimeoutCalculator timeout_calculator_;
    DurationCalculator duration_calculator_;
    FilterCalculator filter_calculator_;

    // duration/filter rule item status map
    std::unordered_map<std::string, SafetyStatus_Status> rule_status_map_;
    // the highest level name and status of rule_status_map_
    std::string highest_item_name;
    SafetyStatus_Status highest_rule_status_ = SafetyStatus_Status_OK;

    std::mutex lock_;

    DECLARE_SINGLETON(RuleCalculator)
};

}  // namespace safety_manager
}  // namespace apollo
