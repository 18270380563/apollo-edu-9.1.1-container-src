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

#include <set>
#include <string>
#include <vector>

#include "cyber/common/file.h"
#include "cyber/cyber.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calib_status.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calibration_gflags.h"
#include "modules/dreamview_plus_plugins/calibration_tool/conf_manager/conf_manager.h"
#include "modules/sensor_calibration/lidar_to_camera/lidar_to_camera.h"

namespace apollo {
namespace dreamview {

class CameraCalibTask {
public:
    explicit CameraCalibTask(
            const std::string& calibration_data_path,
            const calibration::CameraItem& camera_item_conf,
            const std::string& task_id);

    virtual ~CameraCalibTask() = default;

    /**
     * @brief Init camera calibration task. Get the input file path and output file path.
     */
    bool Init();

    /**
     * @brief Process a camera-lidar pair data. After processing the data, origin_data.csv will be saved locally.
     *
     * @param subtask_id The capture subtask_id.
     */
    CalibStatus ProcessData(const std::string& subtask_id);

    /**
     * @brief Pass the final origin_data.csv into the algorithm and obtain the external parameter file, overwriting the
     * output file.
     */
    CalibStatus GetExtrinsicResult(const std::vector<std::string>& subtask_ids);

    /**
     *  @brief Load the Project image of pointcloud to image.
     */
    CalibStatus LoadProjectResult(const std::string& subtask_id);

    /**
     *  @brief Update the output extrinsic file, include frame_id and transform.
     */
    CalibStatus UpdateOutputExtrinsicFile();

    /**
     * @brief Get CameraCalibManager status.
     */
    const CalibStatus* GetStatus() const {
        return &status_;
    }

private:
    /**
     * @brief Generate the merged csv file.
     */
    CalibStatus GenerateMergedCsvFile(const std::string& csv_file, const std::vector<std::string>& subtask_ids);

    /**
     * @brief Get extrinsic file path.
     */
    std::string GetExtrinsicFilePath() const;

private:
    std::string calibration_data_path_;
    std::string collection_path_prefix_;
    calibration::CameraItem camera_item_conf_;
    std::string task_id_;
    CalibStatus status_;
    std::set<std::string> projected_png_set_;

    std::unique_ptr<sensor_calibration::LidarToCameraCalibration> calibration_proc_;
};

}  // namespace dreamview
}  // namespace apollo