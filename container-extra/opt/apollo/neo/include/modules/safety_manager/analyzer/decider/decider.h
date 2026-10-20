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

#include "modules/safety_manager_msgs/safety_manager.pb.h"

#include "cyber/cyber.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

/**
 * @brief Decider calculates the final safety level and writes it into the
 * decision channel periodically.
 */
class Decider {
public:
    Decider(const std::shared_ptr<apollo::cyber::Node>& node, const uint32_t& period);

    /**
     * @brief Start the decider timer.
     */
    void Start();

    /**
     * @brief Call the method when a new SafetyStatus arrived.
     */
    void Notify(const SafetyStatus& safety_status);

private:
    void Run();
    void Write();

    std::shared_ptr<apollo::cyber::Node> node_;
    std::shared_ptr<::apollo::cyber::Writer<SafetyDecision>> decision_writer_;

    // Decision message write interval in ms.
    uint32_t period_;
    std::unique_ptr<cyber::Timer> timer_ = nullptr;
    uint64_t last_write_ns_;

    std::mutex lock_;
};

}  // namespace safety_manager
}  // namespace apollo
