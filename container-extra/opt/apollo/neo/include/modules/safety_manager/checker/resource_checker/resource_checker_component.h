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
#include <string>
#include <unordered_map>
#include <vector>

#include "modules/safety_manager_msgs/safety_manager.pb.h"
#include "modules/statistics_msgs/resource_statistic.pb.h"
#include "modules/safety_manager/checker/resource_checker/proto/resource_checker_conf.pb.h"

#include "cyber/cyber.h"
#include "modules/safety_manager/exporter/exporter.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

namespace rs = apollo::resource_statistic;
using METRIC_MAP = std::unordered_map<std::string, const rs::DiskMetric_Metric*>;

struct CheckerResult {
    std::vector<std::string> fatal_list;
    std::vector<std::string> error_list;
    std::vector<std::string> warn_list;
    std::map<std::string, std::string> values;
};

class ResourceCheckerComponent : public cyber::Component<rs::ResourceMetrics> {
public:
    bool Init() override;

    bool Proc(const std::shared_ptr<rs::ResourceMetrics>& metrics) override;

private:
    /**
     * @brief Check cpu usage and temperature.
     * @param metrics ResourceMetrics proto message
     */
    void CheckCpu(const rs::ResourceMetrics& metrics);

    /**
     * @brief Check memory.
     * @param metrics ResourceMetrics proto message
     */
    void CheckMemory(const rs::ResourceMetrics& metrics);

    /**
     * @brief Check disk usage and I/O.
     * @param metrics ResourceMetrics proto message
     */
    void CheckDisk(const rs::ResourceMetrics& metrics);

    /**
     * @brief Check one disk.
     * @param conf Disk conf peoto message
     * @param metric_map Metric map
     */
    void CheckOneDisk(const ResourceCheckerConf_Disk& conf, const METRIC_MAP& metric_map);

    /**
     * @brief Check gpu usage and temperature.
     * @param metrics ResourceMetrics proto message
     */
    void CheckGpu(const rs::ResourceMetrics& metrics);

    /**
     * @brief Report the checker result.
     * @param result Checker result
     */
    void Report(const std::string name, const CheckerResult& result);

    ResourceCheckerConf conf_;
    std::unique_ptr<SafetyExporter> exporter_ = nullptr;
};

CYBER_REGISTER_COMPONENT(ResourceCheckerComponent)

}  // namespace safety_manager
}  // namespace apollo
