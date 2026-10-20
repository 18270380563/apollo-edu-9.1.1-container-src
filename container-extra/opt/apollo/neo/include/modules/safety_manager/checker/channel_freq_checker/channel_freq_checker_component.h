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
#include "modules/safety_manager/checker/channel_freq_checker/proto/channel_freq_checker_conf.pb.h"

#include "cyber/cyber.h"
#include "cyber/data/cache_buffer.h"
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

using CacheQueue = cyber::data::CacheBuffer<uint64_t>;

class ChannelFreqCheckerComponent : public cyber::Component<> {
public:
    bool Init() override;

protected:
    virtual void Report(SafetyStatusWrapper* status_wrapper);

private:
    ChannelFreqCheckerConf conf_;
    std::unique_ptr<SafetyExporter> exporter_ = nullptr;
    std::unordered_map<std::string, CacheQueue> channel_queue_map_;

    void InitChannelQueues();

    void CreateReaders();
    void ReadCallback(const std::string& channel_name);

    void CheckItem(const ChannelFreqCheckerConf_Item& item, const uint64_t& now, CheckerResult* result);
    double GetFreq(const std::string& channel_name, const uint64_t& now);
};

CYBER_REGISTER_COMPONENT(ChannelFreqCheckerComponent)

}  // namespace safety_manager
}  // namespace apollo
