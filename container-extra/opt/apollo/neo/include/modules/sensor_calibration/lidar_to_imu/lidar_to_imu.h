#pragma once

#include <future>
#include <memory>

#include "modules/sensor_calibration/lidar_to_imu/src/calibration.h"
#include "modules/sensor_calibration/lidar_to_imu/src/extrinsic_param.h"
#include "modules/sensor_calibration/lidar_to_imu/src/registration.h"
#include "modules/sensor_calibration/lidar_to_imu/src/transform_util.hpp"

namespace apollo {
namespace sensor_calibration {

struct LidarToIMUCalibrationResult {
    bool succeed;
    std::string message;
    std::string output_path;
    std::vector<std::vector<double>> judge_results;
};
using ResultFuture = std::shared_future<LidarToIMUCalibrationResult>;

/**
 * @brief 雷达到组合惯导标定类
 * 使用方法：
 *     1. 首先传入LidarToIMUCalibrationConfig配置创建类对象
 *     2. 然后调用Start()方法获取异步结果对象
 *     3. 根据异步对象判断是否完成，调用GetProgress获取处理进度
 */
class LidarToIMUCalibration {
public:
    explicit LidarToIMUCalibration(const std::shared_ptr<LidarToIMUCalibrationConfig>& conf) : conf_(conf) {};
    ~LidarToIMUCalibration();

    /**
     * @brief LidarTOIMU标定开始方法
     *
     * @return 返回一个future对象，格式为LidarToIMUCalibrationResult,里面包含output_path，在output_path下
     * 寻找对应的雷达文件夹，result.yaml和result.pcd为标定结果.对象中的judge_results包含每个雷达的打分结果，第ｉ
     * 个雷达的打分结果为judge_results[i].back()
     */
    ResultFuture Start();

    /**
     * @brief 获取标定进度
     */
    float GetProgress();
    /**
     * @brief 终止标定
     */
    void InterruptCalibration();

private:
    bool Init(std::string* err_message);
    LidarToIMUCalibrationResult Run();
    std::shared_ptr<LidarToIMUCalibrationConfig> conf_;
    std::shared_ptr<LidarToIMUAlgorithmConfig> conf_algo_;
    pcl::PointCloud<pcl::PointXYZI>::Ptr main_calib_data_;
    LidarCalibrationLoader* data_loader_ = nullptr;
    Registrator* registrator_ = nullptr;
    Calibrator* calibrator_ = nullptr;

    std::string config_path_;
    int total_literations_num_ = 0;
    std::atomic_int calibrator_literations_num_{0};
    std::atomic_int registrator_literations_num_{0};
    std::atomic_int lidar_process_num_{0};
    float progress_ = 0.0;
    double imu_to_ground_height_ = 0.0;
};

}  // namespace sensor_calibration
}  // namespace apollo