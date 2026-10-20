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

#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/calibration_conf.pb.h"
#include "modules/dreamview_plus_plugins/calibration_tool/proto/lidar_calib_message.pb.h"
#include "modules/sensor_calibration/proto/lidar_to_imu_calibration_config.pb.h"

#include "cyber/common/file.h"
#include "cyber/cyber.h"
#include "cyber/time/clock.h"
#include "modules/common/util/json_util.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calib_status.h"
#include "modules/sensor_calibration/lidar_to_imu/lidar_to_imu.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class LidarCalibTask
 * @brief Lidar calibration task
 */
class LidarCalibTask {
public:
    explicit LidarCalibTask(const calibration::LidarCalibConf* lidar_calib_conf) :
            lidar_calib_conf_(lidar_calib_conf), node_(cyber::CreateNode("LidarCalib")) {};
    virtual ~LidarCalibTask() {
        if (lidar_to_imu_calib_ != nullptr) {
            lidar_to_imu_calib_.reset();
        }
    }

    /**
     * @brief Lidar calibration init.
     */
    bool Init(std::string* error_message);

    /**
     * @brief Start lidar calibration task.
     */
    bool Start(std::string task_id);

    /**
     * @brief Stop lidar calibration task.
     */
    bool Stop();

    using ProgressCallback = std::function<void(const float&, const std::string&)>;

    void SetprogressCallback(const ProgressCallback& progress_callback);

    bool IsCalibRunning() {
        return is_calib_running_;
    }

    /**
     * @brief Get caliration result.
     */
    bool GetResult(const std::string& lidar_name, calibration::Info* Info);

    std::string BinaryToJson(const std::string& binaryData);

    /**
     * @brief check task id directory exists.
     */
    bool CheckTaskExists();

    std::string GetLidarCalibResultDir() {
        return calib_result_dir_;
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

private:
    CalibStatus calib_status_;
    const calibration::LidarCalibConf* lidar_calib_conf_;
    std::shared_ptr<cyber::Node> node_ = nullptr;
    std::string task_id_;
    std::string task_id_dir_;
    std::string collection_data_dir_;
    std::string result_dir_;
    std::string calib_result_dir_;
    std::shared_ptr<sensor_calibration::LidarToIMUCalibrationConfig> calib_rquired_conf_ = nullptr;
    std::shared_ptr<sensor_calibration::LidarToIMUCalibration> lidar_to_imu_calib_ = nullptr;
    float progress_ = 0.0;
    std::string calib_result_path_;
    std::unique_ptr<std::thread> thread_;
    std::mutex mutex_;
    std::future<bool> calib_future_;
    std::atomic<bool> is_calib_running_{false};
    ProgressCallback progress_callback_ = nullptr;
    std::vector<std::vector<double>> judge_results_;

    /**
     * @brief generate calibration required configuration
     */
    void GenerateRequiredCalibrationConf();

    /**
     * @brief calibration thread
     */
    bool CalibThread();
};
}  // namespace dreamview
}  // namespace apollo
