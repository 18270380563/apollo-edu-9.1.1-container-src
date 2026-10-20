#pragma once

#include <future>
#include <memory>

#include "modules/sensor_calibration/proto/lidar_to_camera_calibration_config.pb.h"

#include "cyber/cyber.h"
#include "modules/sensor_calibration/lidar_to_camera/src/image_detector.h"
#include "modules/sensor_calibration/lidar_to_camera/src/lidar_pattern.h"

namespace apollo {
namespace sensor_calibration {

struct LidarToCameraCalibrationResult {
    bool succeed = false;
    std::string message = "everything is ok";
    double score = 0.0;
};

/**
 * @brief 雷达到相机标定类
 * 使用方法：
 *     1. 首先传入LidarToCaCalibrationConfig配置创建类对象
 *     2.
 *     3.
 */
class LidarToCameraCalibration {
public:
    explicit LidarToCameraCalibration(const std::shared_ptr<LidarToCameraCalibrationConfig>& conf) : conf_(conf) {};

    LidarToCameraCalibrationResult Init();

    /**
     * @brief 传入存放一张照片和至少一帧点云数据的文件夹路径，进行标定
     *
     * @return
     * 在同级目录下生result文件夹，包含图片和标定版角点在点云和图片中坐标的csv文件,csv文件为calculate.csv,图片为init.png
     *
     */
    LidarToCameraCalibrationResult ProcessSingleFolderData(std::string data_path);

    /**
     * @brief 传入带有标定版和点云坐标的csv文件
     *
     * @return 更新相机外参,数据保存到extrinsic_file中,result中的score即为计算得分
     */
    LidarToCameraCalibrationResult GetResultFromText(const std::string& csv_path, const std::string& extrinsic_file);

    /**
     * @brief 传入存放图片和点云数据的文件夹路径
     *
     * @return 更新投影结果，放入对应的result文件夹中,投影结果取名为final.png
     */
    LidarToCameraCalibrationResult ProjectPointCloudToImage(
            const std::string& extrinsic_file,
            const std::string& sub_folder);
    /**
     * @brief 传入存放上述多个文件夹路径的路径，进行标定,测试使用
     *
     * @return
     */
    LidarToCameraCalibrationResult ProcessMultiFolderData(std::string folder_path);

private:
    std::shared_ptr<LidarToCameraCalibrationConfig> conf_;
    std::shared_ptr<ImageDetector> image_detector_;
    std::shared_ptr<LidarDetector> lidar_detector_;
    std::string config_path_;
    std::shared_ptr<LidarToCameraAlgorithmConfig> conf_algo_;
};

}  // namespace sensor_calibration
}  // namespace apollo