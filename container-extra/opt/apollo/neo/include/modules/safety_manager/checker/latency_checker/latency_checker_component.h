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
#include <set>
#include <string>
#include <vector>

#include "modules/safety_manager_msgs/safety_manager.pb.h"
#include "modules/statistics_msgs/latency_statistic.pb.h"
#include "modules/safety_manager/checker/latency_checker/proto/latency_checker_conf.pb.h"

#include "cyber/cyber.h"
#include "modules/safety_manager/exporter/exporter.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

struct MetricResult {
    std::set<std::string> dag_set;
    std::set<std::string> latency_group_set;
    std::vector<std::string> general_latency_list;
};

struct CheckerResult {
    std::vector<std::string> fatal_list;
    std::vector<std::string> error_list;
    std::vector<std::string> warn_list;
    std::map<std::string, std::string> values;
};

class LatencyCheckerComponent : public cyber::Component<latency_statistic::LatencyMetrics> {
public:
    bool Init() override;

    bool Proc(const std::shared_ptr<latency_statistic::LatencyMetrics>& metrics) override;

private:
    LatencyCheckerConf conf_;
    std::unique_ptr<SafetyExporter> exporter_ = nullptr;

    /**
     * @brief Fill item name into CheckResult warn/error/fatal list by item level.
     */
    void FillCheckerResult(const LatencyCheckerConf_Item& item, CheckerResult* checker_result);

    /**
     * @brief Get latency metric by item module and type.
     */
    const latency_statistic::LatencyMetrics_Metric* GetMetric(
            const LatencyCheckerConf_Item& item,
            const latency_statistic::LatencyMetrics& metrics);

    /**
     * @brief Check each latency checker item and fill result into CheckerResult.
     */
    void CheckItem(
            const LatencyCheckerConf_Item& item,
            const latency_statistic::LatencyMetrics& metrics,
            CheckerResult* checker_result);

    void Report(const CheckerResult& checker_result);
};

CYBER_REGISTER_COMPONENT(LatencyCheckerComponent)

}  // namespace safety_manager
}  // namespace apollo
