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
#include <memory>
#include <queue>
#include <string>

#include "modules/safety_manager_msgs/safety_manager.pb.h"

#include "cyber/cyber.h"
#include "modules/common/monitor_log/monitor_log_buffer.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

/**
 * @brief Aggregator class is used to aggregate all SafetyStatus into an array,
 * and write it into the aggregation channel periodically.
 */
class Aggregator {
public:
    Aggregator(const std::shared_ptr<apollo::cyber::Node>& node, const uint32_t& period, const double& reserved_sec);

    /**
     * @brief Start the aggregation timer.
     */
    void Start();

    /**
     * @brief Call the method when a new SafetyStatus arrived.
     */
    void Notify(const std::shared_ptr<SafetyStatus>& safety_status);

private:
    void Run();
    void Write();
    void WriteMonitorLog(const std::shared_ptr<SafetyStatusAggr>& status_aggr);

    std::shared_ptr<apollo::cyber::Node> node_;
    std::shared_ptr<::apollo::cyber::Writer<SafetyStatusAggr>> aggr_writer_;
    std::unique_ptr<common::monitor::MonitorLogBuffer> monitor_logger_buffer_;

    // Aggregation message write interval in ms.
    uint32_t period_;
    std::unique_ptr<cyber::Timer> timer_ = nullptr;
    // item over this second will be removed from aggregator status array.
    double reserved_sec_;

    std::queue<std::shared_ptr<SafetyStatus>> queue_;
    std::map<std::string, std::pair<double, std::shared_ptr<SafetyStatus>>> status_map_;

    std::mutex lock_;
};

}  // namespace safety_manager
}  // namespace apollo
