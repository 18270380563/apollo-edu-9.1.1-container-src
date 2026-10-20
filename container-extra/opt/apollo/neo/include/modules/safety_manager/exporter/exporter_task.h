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

#include <functional>
#include <list>
#include <map>
#include <mutex>
#include <string>

#include "modules/safety_manager/exporter/exporter_status.h"

namespace apollo {
namespace safety_manager {

using TaskFunction = std::function<void(SafetyStatusWrapper*)>;

/**
 * @brief SafetyExporterTask is used to collect data by executing
 * a callback function.
 */
class SafetyExporterTask {
public:
    /**
     * @brief Constructs a SafetyExporterTask class.
     *
     * @param name The task name string.
     * @param func The task callback function.
     */
    SafetyExporterTask(const std::string& name, TaskFunction func) : name_(name), func_(func) {}

    /**
     * @brief Get the SafetyExporterTask name.
     *
     * @return The task name string.
     */
    std::string GetName() {
        return name_;
    }

    /**
     * @brief Call the callback function
     *
     * @param status_wrapper SafetyStatusWrapper instance point,
     * status data will be filled into the instance.
     */
    void Run(SafetyStatusWrapper* status_wrapper) {
        func_(status_wrapper);
    }

private:
    std::string name_;
    TaskFunction func_;
};

}  // namespace safety_manager
}  // namespace apollo
