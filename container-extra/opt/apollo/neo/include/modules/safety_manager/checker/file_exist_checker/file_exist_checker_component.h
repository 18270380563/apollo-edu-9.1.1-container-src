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
#include <vector>

#include "modules/safety_manager_msgs/safety_manager.pb.h"
#include "modules/safety_manager/checker/file_exist_checker/proto/file_exist_checker_conf.pb.h"

#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"
#include "modules/safety_manager/exporter/exporter.h"
/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

struct CheckerResult {
    std::vector<std::string> fatal_list;
    std::vector<std::string> error_list;
    std::vector<std::string> warn_list;
    std::map<std::string, std::string> values;
};

class FileExistCheckerComponent : public cyber::TimerComponent {
public:
    bool Init() override;
    bool Proc() override;

private:
    /**
     * @brief Report the checker result.
     * @param result Checker result
     */
    void Report(const CheckerResult& result);

    /**
     * @brief Check file existence.
     * @param conf The checker config.
     * @param result The output Checker result
     */
    void CheckFileExistence(const FileExistCheckerConf_Item& conf, CheckerResult* result);

    FileExistCheckerConf conf_;
    std::unique_ptr<SafetyExporter> exporter_ = nullptr;
};

CYBER_REGISTER_COMPONENT(FileExistCheckerComponent)

}  // namespace safety_manager
}  // namespace apollo
