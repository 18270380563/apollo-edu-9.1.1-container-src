#pragma once
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <pcl/io/pcd_io.h>
#include <pcl/octree/octree_search.h>
#include <pcl/point_cloud.h>

#include "pre_process.h"

#include "modules/sensor_calibration/lidar_to_imu/common/Lidar_parser_base.h"
#include "modules/sensor_calibration/proto/lidar_to_imu_algorithm_config.pb.h"

namespace apollo {
namespace sensor_calibration {

class Registrator {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    Registrator(std::shared_ptr<LidarToIMUAlgorithmConfig> config, const std::string &result_path);
    ~Registrator();

    size_t ComputeVoxelOccupancy(float var[6]);

    double ComputeGroundRegistrationError(float var[6]);

    // registration method
    bool RegistrationByGroundPlane(Eigen::Matrix4d &transform, std::string *error_msg);
    bool RegistrationByVoxelOccupancy(
            Eigen::Matrix4d &transform,
            std::function<void(int)> progress_callback,
            std::string *error_msg);

    // load data
    bool LoadOdometerData(
            const std::string odometer_file,
            const Eigen::Matrix4d &initial_extrinsic,
            std::string *error_msg);
    bool LoadLidarPCDs(const std::string &pcds_dir, std::string *error_msg);

    void SaveStitching(const std::string &stitching_path, double height);
    void StopCalibration();
    bool CheckIFStopped(std::string *error_msg);
    void SetPCLIntensityDataType(bool is_float);
    double OptimizeOdom();
    double CalibHeightAndSave(const std::string &stitching_path, const Eigen::Matrix4d &transform, bool save_pcd);
    pcl::PointCloud<pcl::PointXYZI>::Ptr GetCalibData(const Eigen::Matrix4d &transform);
    void GetTransformedCloud(
            const Eigen::Matrix4d &transform,
            const pcl::PointCloud<pcl::PointXYZI>::Ptr &target_cloud,
            const pcl::PointCloud<pcl::PointXYZI>::Ptr &transformed_cloud);

private:
    double getScoreFromSum(double sum);
    double baseIncrement = 0.1;
    std::map<double, double> scoreMap = {
            {0 * baseIncrement, 100.0},
            {1 * baseIncrement, 95.0},
            {2 * baseIncrement, 90.0},
            {3 * baseIncrement, 85.0},
            {5 * baseIncrement, 80.0},
            {8 * baseIncrement, 70.0},
            {10 * baseIncrement, 60.0},
            {15 * baseIncrement, 50.0},
            {20 * baseIncrement, 40.0},
            {30 * baseIncrement, 30.0},
            {40 * baseIncrement, 20.0},
    };
    pcl::PointCloud<pcl::PointXYZI>::Ptr all_cloud_;
    pcl::octree::OctreePointCloudSearch<pcl::PointXYZI>::Ptr all_octree_;
    pcl::PointCloud<pcl::PointXYZI>::Ptr lidar_to_lidar_calib_data_;

    std::vector<pcl::PointCloud<pcl::PointXYZI>> pcds_;
    std::vector<pcl::PointCloud<pcl::PointXYZI>> pcds_g_cloud_;
    std::vector<pcl::PointCloud<pcl::PointXYZI>> pcds_ng_cloud_;
    std::vector<std::string> timestamp_;
    std::vector<Eigen::Matrix4d, Eigen::aligned_allocator<Eigen::Matrix4d>> lidar_poses_;
    std::vector<Eigen::Matrix4d, Eigen::aligned_allocator<Eigen::Matrix4d>> lidar_poses_start_;

    float curr_best_extrinsic_[6] = {0};
    Eigen::Matrix4d lidar2imu_initial_;

    int intensity_threshold_;
    double lidar_height_;
    std::shared_ptr<LidarToIMUAlgorithmConfig> config_;
    std::atomic<bool> stopped_{false};
    bool pcl_intensity_data_type_is_float_;
    std::string result_path_;
};

}  // namespace sensor_calibration
}  // namespace apollo