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

#include "modules/safety_manager/checker/process_checker/proto/process_checker_conf.pb.h"
#include "modules/safety_manager_msgs/safety_manager.pb.h"
#include "modules/statistics_msgs/process_statistic.pb.h"

#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"
#include "modules/safety_manager/exporter/exporter.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

namespace ps = apollo::process_statistic;

struct MetricResult {
    std::set<std::string> dag_set;
    std::set<std::string> process_group_set;
    std::vector<std::string> general_process_list;
};

struct CheckerResult {
    std::vector<std::string> fatal_list;
    std::vector<std::string> error_list;
    std::vector<std::string> warn_list;
    std::map<std::string, std::string> values;
};

class ProcessCheckerComponent : public cyber::TimerComponent {
public:
    bool Init() override;
    bool Proc() override;

private:
    ProcessCheckerConf conf_;
    std::unique_ptr<SafetyExporter> exporter_ = nullptr;

    void GetMetricResult(const std::shared_ptr<ps::ProcessMetrics>& metrics, MetricResult* metric_result);

    // check item
    void CheckItem(
            const ProcessCheckerConf_Item& item,
            const MetricResult& metric_result,
            CheckerResult* checker_result);

    void Report(const CheckerResult& checker_result);

    std::shared_ptr<cyber::Reader<ps::ProcessMetrics>> metric_reader_;
};

CYBER_REGISTER_COMPONENT(ProcessCheckerComponent)

}  // namespace safety_manager
}  // namespace apollo
