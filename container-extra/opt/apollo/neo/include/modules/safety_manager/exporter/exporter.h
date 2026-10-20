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

#include <list>
#include <map>
#include <memory>
#include <string>

#include "cyber/cyber.h"
#include "modules/safety_manager/exporter/exporter_status.h"
#include "modules/safety_manager/exporter/exporter_task.h"

// topic name
#define SAFETY_EXPORTER_TOPIC "/apollo/safety/status"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

// in milliseconds
constexpr uint32_t DEFAULT_PERIOD = 1000;

/**
 * @brief The main class of the exporter library,
 * it provides two calling interface:
 * 1. Call the Report function to send status data directly
 * 2. Call the Add function to add a periodic SafetyExporterTask,
 * the default period is 1 second, you can specify the period in
 * constructor function, or call SetPeriod set the period.
 *
 * All SafetyStatus message will be written into
 * "/apollo/safety/status" topic finally.
 */
class SafetyExporter : public SafetyExporterStatusAdapter {
public:
    /**
     * @brief Constructs a SafetyExporter class.
     *
     * @param node A cyber node shared point.
     * @param period The cyber::Timer period for managing the exporter tasks,
     * using DEFAULT_PERIOD as default value.
     */
    explicit SafetyExporter(const std::shared_ptr<apollo::cyber::Node>& node, const uint32_t period = DEFAULT_PERIOD);

    /**
     * @brief Get the period value.
     *
     * @return Period value in milliseconds.
     */
    uint32_t GetPeriod() const {
        return period_;
    }

    /**
     * @brief Set the period value.
     *
     * @param period Period value in milliseconds.
     */
    void SetPeriod(const uint32_t& period);

    /**
     * @brief Write safety status by name,status,message.
     *
     * @param name Filled into the SafetyStatus name field.
     * @param status Filled into the SafetyStatus status field.
     * @param message Filled into the SafetyStatus message field.
     *
     * @return Return true if report successfully.
     */
    bool Report(const std::string& name, const SafetyStatus_Status& status, const std::string& message) {
        return Report(name, status, message, {});
    }

    /**
     * @brief Write safety status by name,status,message and values.
     *
     * @param name Filled into the SafetyStatus name field.
     * @param status Filled into the SafetyStatus status field.
     * @param message Filled into the SafetyStatus message field.
     * @param values Filled into the SafetyStatus values field.
     *
     * @return Return true if report successfully.
     */
    bool Report(
            const std::string& name,
            const SafetyStatus_Status& status,
            const std::string& message,
            const std::map<std::string, std::string>& values);

    /**
     * @brief Write safety status by SafetyStatus instance.
     *
     * @param status A SafetyStatus instance.
     *
     * @return Return true if report successfully.
     */
    bool Report(const SafetyStatus& status) {
        return status_writer_->Write(status);
    }

    /**
     * @brief Write safety status by SafetyStatus shared point.
     *
     * @param status A SafetyStatus shared point.
     *
     * @return Return true if report successfully.
     */
    bool Report(const std::shared_ptr<SafetyStatus>& status) {
        return status_writer_->Write(status);
    }

    /**
     * @brief Write safety status by SafetyStatusWrapper instance.
     *
     * @param status A SafetyStatusWrapper instance.
     *
     * @return Return true if report successfully.
     */
    bool Report(const SafetyStatusWrapper& status_wrapper) {
        return status_writer_->Write(status_wrapper.GetSafetyStatus());
    }

    /**
     * @brief Write safety status by SafetyStatusWrapper shared point.
     *
     * @param status_wrapper A StattusWrapper shared point.
     *
     * @return Return true if report successfully.
     */
    bool Report(const std::shared_ptr<SafetyStatusWrapper>& status_wrapper) {
        return status_writer_->Write(status_wrapper->GetSafetyStatus());
    }

    /**
     * @brief Add a exporter task into task list
     *
     * @param task A SafetyExporterTask instance.
     */
    void Add(const SafetyExporterTask& task);

    /**
     * @brief Add a task by name and function.
     *
     * @param name The task name.
     * @param func The task callback function.
     */
    void Add(const std::string& name, TaskFunction func);

    /**
     * @brief Add a exporter task by name, class instance and callback function.
     *
     * @param name The task name.
     * @param ins Class instance of the callack function.
     * @param func The task callback function.
     */
    template <class T>
    void Add(const std::string& name, T* ins, void (T::*func)(SafetyStatusWrapper*)) {
        Add(SafetyExporterTask(name, std::bind(func, ins, std::placeholders::_1)));
    }

    /**
     * @brief Remove a exporter task by name
     *
     * @param name The task name to be removed.
     *
     * @return Return false if task not found.
     */
    bool Remove(const std::string& name);

private:
    /**
     * @brief Init the cyber node writer.
     */
    void InitWriter();

    /**
     * @brief Reset the cyber timer.
     */
    void ResetTimer() {
        timer_.reset(new cyber::Timer(
                period_, [this]() { this->Export(); }, false));
    }

    /**
     * @brief Write status data generated by each SafetyExporterTask.
     */
    void Export();

    /**
     * @brief Remove a exporter task by name, called by Remove method.
     */
    bool RemoveByName(const std::string& name);

    std::shared_ptr<apollo::cyber::Node> node_;
    std::shared_ptr<::apollo::cyber::Writer<SafetyStatus>> status_writer_;

    uint32_t period_;
    std::unique_ptr<cyber::Timer> timer_ = nullptr;

    std::list<SafetyExporterTask> task_list_;
    std::mutex lock_;
};

}  // namespace safety_manager
}  // namespace apollo
