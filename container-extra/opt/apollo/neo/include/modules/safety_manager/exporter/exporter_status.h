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

#include "cyber/common/macros.h"
#include "modules/common/util/message_util.h"

namespace apollo {
namespace safety_manager {

/**
 * @brief Wrapper for apollo::safety_manager::SafetyStatus which defined in
 * saftety_manager.proto, makes it easier to update.
 */
class SafetyStatusWrapper {
public:
    /**
     * @brief Constructs a SafetyStatusWrapper class.
     *
     * @param name The SafetyStatusWrapper name string.
     */
    explicit SafetyStatusWrapper(const std::string& name) {
        safety_status_ = std::make_shared<SafetyStatus>();
        safety_status_->set_name(name);
    }

    /**
     * @brief Fills out the status and message fields of SafetyStatus.
     *
     * @param status Item of SafetyStatus_Status (OK,WARN,ERROR,FATAL).
     * @param message Status description string.
     */
    void Summary(const SafetyStatus_Status& status, const std::string& message) {
        SetStatus(status);
        SetMessage(message);
    }

    /**
     * @brief Set the status field.
     *
     * @param status Item of SafetyStatus_Status (OK,WARN,ERROR,FATAL).
     */
    void SetStatus(const SafetyStatus_Status& status) {
        safety_status_->set_status(status);
    }

    /**
     * @brief Set the message field.
     *
     * @param message Status description string .
     */
    void SetMessage(const std::string& message) {
        safety_status_->set_message(message);
    }

    /**
     * @brief Add values by key and value.
     *
     * @param key Values key string.
     * @param value Values value string.
     */
    void AddValue(const std::string& key, const std::string& value) {
        (*safety_status_->mutable_values())[key] = value;
    }

    /**
     * @brief Set values from a values map.
     *
     * @param values The copied map.
     */
    void SetValues(const std::map<std::string, std::string>& values) {
        safety_status_->mutable_values()->clear();
        for (auto& it : values) {
            (*safety_status_->mutable_values())[it.first] = it.second;
        }
    }

    /**
     * @brief Add a tag.
     *
     * @param tag A new tag string.
     */
    void AddTag(const std::string tag) {
        safety_status_->add_tags(tag);
    }

    /**
     * @brief Set tags from a tag vector.
     *
     * @param tags The copied tag vector.
     */
    void SetTags(const std::vector<std::string>& tags) {
        safety_status_->mutable_tags()->CopyFrom({tags.begin(), tags.end()});
    }

    /**
     * @brief Set the timeout field of status rule.
     *
     * @param secs Seconds of timeout.
     */
    void SetTimeout(const double& secs) {
        safety_status_->mutable_rule()->set_timeout(secs);
    }

    /**
     * @brief Set the duration field of status rule.
     *
     * @param secs Seconds of duration.
     */
    void SetDuration(const double& secs) {
        safety_status_->mutable_rule()->set_duration(secs);
    }

    /**
     * @brief Set the filter info of status rule.
     *
     * @param required_cycles Filter required cycles num.
     * @param total_cycles Filter tatal cycles num.
     */
    bool SetFilter(const uint32_t required_cycles, const uint32_t total_cycles) {
        if (required_cycles > total_cycles) {
            return false;
        }
        auto filter = safety_status_->mutable_rule()->mutable_filter();
        filter->set_required_cycles(required_cycles);
        filter->set_total_cycles(total_cycles);
        return true;
    }

    /**
     * @brief Add default header by module name.
     *
     * @param module_name Usually set as cyber node name.
     */
    void AddHeader(const std::string& module_name) {
        apollo::common::util::FillHeader(module_name, safety_status_.get());
    }

    /**
     * @brief Call safetyStatus clear method to clean all fields.
     */
    void Clear() {
        safety_status_->Clear();
    }

    /**
     * @brief Get the SafetyStatus instance ptr.
     * you should better not to use protobuf methods directly,
     * especially modify the name field.
     *
     * @return The safetyStatus instance shared ptr.
     */
    std::shared_ptr<SafetyStatus> GetSafetyStatus() const {
        return safety_status_;
    }

private:
    std::shared_ptr<SafetyStatus> safety_status_ = nullptr;
    DISALLOW_COPY_AND_ASSIGN(SafetyStatusWrapper);
};

/**
 * @brief Adapter for setting default value of SafetyExporter.
 */
class SafetyExporterStatusAdapter {
public:
    /**
     * @brief Add a default tag.
     *
     * @param tag A dafault tag string.
     */
    void AddDefaultTag(const std::string& tag) {
        tags_.emplace_back(tag);
    }

    /**
     * @brief Set default tags.
     *
     * @param tags The default tag vector.
     */
    void SetDefaultTags(const std::vector<std::string>& tags) {
        tags_ = tags;
    }

    /**
     * @brief Set the default timeout rule.
     *
     * @param timeout the second of timtout.
     */
    void SetDefaultTimeout(const double& timeout) {
        timeout_ = timeout;
    }

    /**
     * @brief Set the default duration rule.
     *
     * @param timeout the second of duration.
     */
    void SetDefaultDuration(const double& duration) {
        duration_ = duration;
    }

    /**
     * @brief Set the default filter rule.
     *
     * @param required_cycles The default required cycles num of filter rule.
     * @param total_cycles The default total cycles num of filter rule.
     */
    void SetDefaultFilter(const uint32_t required_cycles, const uint32_t total_cycles) {
        required_cycles_ = required_cycles;
        total_cycles_ = total_cycles;
    }

protected:
    /**
     * @brief Fills out default values into a StatusWrapper instance,
     * only those fields that hava called SetDefault will be filled in.
     *
     * @param status_wrapper The StatusWrapper instance that need to be filled.
     */
    void FillDefaultValues(SafetyStatusWrapper* status_wrapper) const {
        auto safety_status = status_wrapper->GetSafetyStatus();
        if (tags_.size() > 0 && safety_status->tags_size() == 0) {
            status_wrapper->SetTags(tags_);
        }
        auto rule = safety_status->mutable_rule();
        if (timeout_ > 0 && !rule->has_timeout()) {
            rule->set_timeout(timeout_);
        }
        if (duration_ > 0 && !rule->has_duration()) {
            rule->set_duration(duration_);
        }

        if (required_cycles_ > 0 && (!rule->has_filter() || !rule->filter().has_required_cycles())) {
            auto filter = rule->mutable_filter();
            filter->set_required_cycles(required_cycles_);
            filter->set_total_cycles(total_cycles_);
        }
    }

private:
    std::vector<std::string> tags_;
    double timeout_ = -1;
    double duration_ = -1;
    uint32_t required_cycles_ = 0;
    uint32_t total_cycles_ = 0;
};

}  // namespace safety_manager
}  // namespace apollo
