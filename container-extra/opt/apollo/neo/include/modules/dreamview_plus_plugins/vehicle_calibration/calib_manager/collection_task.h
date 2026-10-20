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

#include <future>
#include <map>
#include <random>
#include <string>
#include <vector>

#include <hdf5/serial/H5Cpp.h>
#include <hdf5/serial/hdf5.h>
#include <nlohmann/json.hpp>

#include "modules/common_msgs/chassis_msgs/chassis.pb.h"
#include "modules/common_msgs/localization_msgs/gps.pb.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/calibration_table_conf.pb.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/proto/vehicle_calibration_conf.pb.h"

#include "cyber/common/file.h"
#include "cyber/cyber.h"
#include "modules/common/math/math_utils.h"
#include "modules/dreamview/backend/common/handlers/websocket_handler.h"
#include "modules/dreamview_plus_plugins/vehicle_calibration/common/calib_status.h"
#include "modules/private_common/status_collector/status_collector.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class CollectionTask
 * @brief Collection task
 */
class CollectionTask {
public:
    explicit CollectionTask(
            const vehicle_calibration::VehicleCalibConf *calib_conf,
            vehicle_calibration::CalibrationTableConf calib_table_conf) :
            vehicle_calib_conf_(calib_conf),
            node_(cyber::CreateNode("Collection")),
            calib_table_conf_(calib_table_conf) {
        status_collector_.reset(new common::StatusCollector(cyber::CreateNode("vehicle_calib_collector")));
    };
    virtual ~CollectionTask() = default;

    /**
     * @brief Collection task init.
     */
    bool Init();

    /**
     * @brief Get status of collection dependent modules.
     */
    nlohmann::json GetStatus();

    /**
     * @brief Start collection task.
     */
    bool Start(const std::string &task_id);

    using ProgressCallback
            = std::function<void(const std::string &, const int &, const int &, const float &, const float &)>;

    void SetprogressCallback(const ProgressCallback &progress_callback);

    bool IsCollectionRunning() const {
        return is_start_;
    }

    /**
     * @brief Stop collection task.
     */
    bool Stop();

    /**
     * @brief Get collection task status.
     */
    const CalibStatus *GetCollectionTaskStatus() const {
        return &calib_status_;
    }

    /**
     * @brief Get collection task status message.
     */
    std::string GetCollectionTaskMessage() const {
        return calib_status_.GetMessage();
    }

private:
    /**
     * @brief create cyber readers
     */
    void CreateChassisAndLocReader();

    void ChassisCallback(const std::shared_ptr<canbus::Chassis> &msg);

    void LocalizationCallback(const std::shared_ptr<localization::LocalizationEstimate> &msg);

    void PickUpMsg(const std::shared_ptr<canbus::Chassis> &msg);

    void UpdateAndForwardProgress(const std::shared_ptr<canbus::Chassis> &msg);
    void ForwardProgress(std::string type, double progress_global, int loc_x, int loc_y, double progress);

    void Reset();

    void WriteData(
            H5::H5File *file,
            const std::string &datasetName,
            const H5::DataSpace &space,
            const H5::DataType &dataType,
            const std::vector<double> &data);

private:
    CalibStatus calib_status_;
    const vehicle_calibration::VehicleCalibConf *vehicle_calib_conf_;
    vehicle_calibration::CollectStrategy calib_conf_strategy_;
    std::shared_ptr<cyber::Node> node_ = nullptr;
    vehicle_calibration::CalibrationTableConf calib_table_conf_;
    std::unique_ptr<common::StatusCollector> status_collector_ = nullptr;

    std::shared_ptr<cyber::Reader<canbus::Chassis>> chassis_reader_ = nullptr;
    std::shared_ptr<cyber::Reader<localization::LocalizationEstimate>> loc_reader_ = nullptr;
    std::shared_ptr<localization::LocalizationEstimate> latest_loc_ = nullptr;

    ProgressCallback progress_callback_ = nullptr;

    bool is_start_ = false;
    std::string task_id_;
    std::string collection_data_dir_;
    std::mutex loc_mutex_;
    std::mutex chassis_mutex_;
    std::atomic_uint32_t total_num_{0};

    std::map<std::pair<int, int>, int> brake_total_num_;
    std::map<std::pair<int, int>, int> brake_count_mid_map_;
    std::map<std::pair<int, int>, int> brake_coverage_mid_map_done_;
    std::map<std::pair<int, int>, int> brake_coverage_mini_map_;

    std::map<std::pair<int, int>, int> throttle_total_num_;
    std::map<std::pair<int, int>, int> throttle_count_mid_map_;
    std::map<std::pair<int, int>, int> throttle_coverage_mid_map_done_;
    std::map<std::pair<int, int>, int> throttle_coverage_mini_map_;
    int brake_total_count_ = 0;
    int brake_now_count_ = 0;
    int throttle_total_count_ = 0;
    int throttle_now_count_ = 0;
    int throttle_mini_count_in_mid_area_ = 0;
    int brake_mini_count_in_mid_area_ = 0;
    float speed_visible_step_ = 0;
    float throttle_visible_step_ = 0;
    float brake_visible_step_ = 0;
    std::vector<std::vector<float>> progress_degree_matrix_ = {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.2, 0.2, 0.1}};
    std::vector<std::vector<float>> progress_done_matrix_ = {{50, 50, 50}, {50, 40, 30}, {40, 30, 20}};
    H5::H5File *brake_test_h5_file_, *brake_train_h5_file_, *throttle_test_h5_file_, *throttle_train_h5_file_;
};
}  // namespace dreamview
}  // namespace apollo
