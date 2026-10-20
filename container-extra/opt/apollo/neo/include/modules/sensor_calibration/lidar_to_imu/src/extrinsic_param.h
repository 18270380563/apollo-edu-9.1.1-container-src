#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "modules/sensor_calibration/proto/lidar_to_imu_calibration_config.pb.h"

namespace apollo {
namespace sensor_calibration {

struct LidarInfo {
    std::string name;
    std::string path;
    Eigen::Matrix4d transform;
    bool is_bp = false;
};

class LidarCalibrationLoader {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    bool Load(
            const std::shared_ptr<apollo::sensor_calibration::LidarToIMUCalibrationConfig> config,
            std::string* err_message);

    void PrintMatrix(const Eigen::Matrix4d& transform);

    Eigen::Matrix4d AddError(const Eigen::Matrix4d& transform, double value[6]);

    const std::string& GetResultPath() const;
    const std::string& GetOdometryPath() const;
    const std::vector<LidarInfo, Eigen::aligned_allocator<LidarInfo>>& GetLidarInfos() const;
    const bool GetCalibHeight() const;

private:
    bool EnsureDirectoryExists(const std::string& path, std::string* err_message);

    bool CreateLidarDirectories(std::string* err_message);
    std::string AppendSlashIfNeeded(const std::string& path);

    Eigen::Matrix4d CreateTransformationMatrix(double w, double x, double y, double z, double tx, double ty, double tz);
    std::string odometry_path_;
    std::string result_path_;
    std::vector<LidarInfo, Eigen::aligned_allocator<LidarInfo>> lidar_infos_;
    bool calib_height_ = false;
};

}  // namespace sensor_calibration
}  // namespace apollo
