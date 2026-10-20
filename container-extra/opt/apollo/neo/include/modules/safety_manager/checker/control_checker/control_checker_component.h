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

#include "modules/common_msgs/chassis_msgs/chassis.pb.h"
#include "modules/common_msgs/control_msgs/control_cmd.pb.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/planning_msgs/planning.pb.h"
#include "modules/safety_manager_msgs/safety_manager.pb.h"
#include "modules/safety_manager/checker/control_checker/proto/control_checker_conf.pb.h"

#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"
// #include "modules/control/common/trajectory_analyzer.h"
#include "modules/control/control_component/controller_task_base/common/trajectory_analyzer.h"
#include "modules/safety_manager/exporter/exporter.h"

/**
 * @namespace apollo::safety_manager
 * @brief apollo::safety_manager
 */
namespace apollo {
namespace safety_manager {

using apollo::canbus::Chassis;
using apollo::common::TrajectoryPoint;
using apollo::control::ControlCommand;
using apollo::localization::LocalizationEstimate;
using apollo::planning::ADCTrajectory;

struct CheckerResult {
    std::vector<std::string> fatal_list;
    std::vector<std::string> error_list;
    std::vector<std::string> warn_list;
    std::map<std::string, std::string> values;
};

class ControlCheckerComponent : public cyber::TimerComponent {
public:
    bool Init() override;

    bool Proc() override;

private:
    /**
     * @brief Create all control checker needed readers:
     * chassis, control_cmd, trajectory, localization.
     */
    void CreateReaders();

    /**
     * @brief Report the checker result to exporter.
     * @param result Checker result
     */
    void Report(const CheckerResult& result);

    /**
     * @brief Check gear location consistency.
     *
     * @param control_cmd Control issued gear location.
     * @param chassis Get chassis gear message.
     * @param result Check result which contains message list and values.
     */
    void CheckGear(
            const std::shared_ptr<ControlCommand>& control_cmd,
            const std::shared_ptr<Chassis>& chassis,
            CheckerResult* result);

    /**
     * @brief Check throttle consistency.
     *
     * @param control_cmd Control issued throttle percentage.
     * @param chassis Get chassis throttle percentage.
     * @param result Check result which contains message list and values.
     */
    void CheckThrottle(
            const std::shared_ptr<ControlCommand>& control_cmd,
            const std::shared_ptr<Chassis>& chassis,
            CheckerResult* result);

    /**
     * @brief Check brake consistency.
     *
     * @param control_cmd Control issued brake percentage.
     * @param chassis Get chassis brake percentage.
     * @param result Check result which contains message list and values.
     */
    void CheckBrake(
            const std::shared_ptr<ControlCommand>& control_cmd,
            const std::shared_ptr<Chassis>& chassis,
            CheckerResult* result);

    /**
     * @brief Check steer consistency.
     *
     * @param control_cmd Control issued steer percentage.
     * @param chassis Get chassis steer percentage.
     * @param result Check result which contains message list and values.
     */
    void CheckSteer(
            const std::shared_ptr<ControlCommand>& control_cmd,
            const std::shared_ptr<Chassis>& chassis,
            CheckerResult* result);

    /**
     * @brief Check sliding accident when gear location is neutral
     * and speed is above limit.
     *
     * @param chassis Get chassis gear location and chassis speed.
     * @param result Check result which contains message list and values.
     */
    void CheckSliding(const std::shared_ptr<Chassis>& chassis, CheckerResult* result);

    /**
     * @brief Check speed consistency in absolute value or percentage.
     *
     * @param trajectory Get planning speed from the point of trajectory which is
     * closest to the current time.
     * @param localization Get localization estimate speed.
     * @param result Check result which contains message list and values.
     */
    void CheckSpeed(
            const std::shared_ptr<ADCTrajectory>& trajectory,
            const std::shared_ptr<LocalizationEstimate>& localization,
            CheckerResult* result);

    /**
     * @brief Set inconsistency start time by check item's name.
     *
     * @param name Check item's name.
     * @param consistency Consistency at this moment.
     * @param result Inconsistency time threshold.
     */
    void SetInconsistencyStartTime(const std::string& name, bool consistency);
    /**
     * @brief Get consistency status.
     * @param name Item's name.
     * @param time_threshold Inconsistency time threshold.
     * @return Return true if consistency.
     */
    bool IsConsistency(const std::string& name, const double time_threshold);

    /**
     * @brief Save the message to the result by the risk level.
     *
     * @param message Checker result message.
     * @param level Risk level.
     * @param result Check result which contains message list and values.
     */
    void SaveCheckResultByLevel(
            const std::string&& message,
            const ControlCheckerConf_Level level,
            CheckerResult* result);

    /**
     * @brief Query a trajectory point closest in the give time.
     *
     * @param time Absoulute time.
     * @param trajectory planning trajectory message.
     * @return a point of trajectory.
     */
    TrajectoryPoint GetPointByAbsoluteTime(const double time, const std::shared_ptr<ADCTrajectory>& trajectory);

    std::shared_ptr<cyber::Reader<Chassis>> chassis_reader_;
    std::shared_ptr<cyber::Reader<ControlCommand>> control_cmd_reader_;
    std::shared_ptr<cyber::Reader<LocalizationEstimate>> localization_reader_;
    std::shared_ptr<cyber::Reader<ADCTrajectory>> trajectory_reader_;
    std::unique_ptr<apollo::control::TrajectoryAnalyzer> trajectory_analyzer_;

    std::unique_ptr<SafetyExporter> exporter_ = nullptr;
    std::unordered_map<std::string, double> inconsistency_start_time_map;
    ControlCheckerConf conf_;
};

CYBER_REGISTER_COMPONENT(ControlCheckerComponent)

}  // namespace safety_manager
}  // namespace apollo
