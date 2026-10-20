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

#include <map>
#include <string>
#include <vector>

#include "modules/safety_manager_msgs/safety_manager.pb.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

/**
 * @brief RuleMatcherBuffer class is used for getting SafetyRule
 * by SafetyStatus instance, it loads RuleMatcherList configuration
 * into a buffer map, call the private match method to obtain the result.
 */
class RuleMatcherBuffer {
public:
    /**
     * @brief Init RuleMatcherBuffer by rule_match conf.
     *
     * @param rule_matcher_list RuleMatcherList from rule_matcher_conf.pb.txt.
     */
    void Init(const RuleMatcherList& rule_matcher_list);

    /**
     * @brief Get matched RuleMatcher by safety_statue instance.
     *
     * @param safety_status SafetyStatus instance.
     */
    const SafetyRule* Get(const SafetyStatus& safety_status);

private:
    /**
     * @brief Calculate whether SafetyStatus istance matched with rule matcher
     * conf.
     *
     * @param matcher Matcher conf.
     * @param safety_status SafetyStatus instance.
     *
     * @return Return true if matched.
     */
    bool Match(const Matcher& matcher, const SafetyStatus& safety_status);

    std::vector<RuleMatcher> rule_matcher_list_;
    std::map<std::string, const SafetyRule*> rule_matcher_buff_;
};

}  // namespace safety_manager
}  // namespace apollo
