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
 ******************************************************************************/

#pragma once

#include <atomic>
#include <future>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/calib_result.pb.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/vehicle_calibration_conf.pb.h"

#include "cyber/common/file.h"
#include "cyber/cyber.h"
#include "cyber/time/clock.h"
#include "modules/common/util/json_util.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/common/calib_status.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class CalibTask
 * @brief Vehicle calibration task
 */
class VehicleCalibTask {
public:
    explicit VehicleCalibTask(const vehicle_calibration::VehicleCalibConf* vehicle_calib_conf) :
            vehicle_calib_conf_(vehicle_calib_conf), node_(cyber::CreateNode("VehicleCalib")){};
    virtual ~VehicleCalibTask() {}

    /**
     * @brief Dynamics calibration init.
     */
    bool Init(std::string* error_message);

    /**
     * @brief Start Dynamics calibration task.
     */
    bool Start(std::string task_id);

    /**
     * @brief Stop Dynamics calibration task.
     */
    bool Stop();

    using ProgressCallback = std::function<void(const std::string&, const float&)>;

    void SetprogressCallback(const ProgressCallback& progress_callback);

    bool IsCalibRunning() {
        return is_calib_running_;
    }

    /**
     * @brief Get caliration result.
     */
    nlohmann::json GetResult();

    /**
     * @brief check task id directory exists.
     */
    bool CheckTaskExists();

    std::string GetDynamicsCalibResultDir() {
        return result_dir_;
    }

    /**
     * @brief Get calib task status.
     */
    const CalibStatus* GetCalibTaskStatus() const {
        return &calib_status_;
    }

    /**
     * @brief Get calib task status message.
     */
    std::string GetCalibTaskMessage() const {
        return calib_status_.GetMessage();
    }

    /**
     * @brief Get calib task judge results.
     */
    std::vector<std::vector<double>> GetJudgeResults() {
        return judge_results_;
    }

    /**
     * @brief Get calib task progress.
     */
    void GetProgress();

private:
    std::vector<int> histogram(const std::vector<double>& data, int num_bins);

private:
    CalibStatus calib_status_;
    const vehicle_calibration::VehicleCalibConf* vehicle_calib_conf_;
    std::shared_ptr<cyber::Node> node_ = nullptr;
    std::string task_id_;
    std::string task_id_dir_;
    std::string collection_data_dir_;
    std::string result_dir_;
    float progress_ = 0.0;
    std::string calib_result_path_;
    std::unique_ptr<std::thread> thread_;
    std::mutex mutex_;
    std::future<bool> calib_future_;
    std::atomic<bool> is_calib_running_{false};
    ProgressCallback progress_callback_ = nullptr;
    std::vector<std::vector<double>> judge_results_;
    std::map<int, std::string> cali_input_index = {{0, "speed"}, {1, "acceleration"}, {2, "control command"}};
};
}  // namespace dreamview
}  // namespace apollo
