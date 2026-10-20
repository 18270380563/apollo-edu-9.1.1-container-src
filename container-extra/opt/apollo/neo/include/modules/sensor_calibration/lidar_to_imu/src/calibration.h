#pragma once

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <pcl/conversions.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/octree/octree_search.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/conditional_euclidean_clustering.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/segmentation/region_growing.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/surface/mls.h>
#include <atomic>

#include "modules/sensor_calibration/lidar_to_imu/common/Lidar_parser_base.h"
#include "modules/sensor_calibration/proto/lidar_to_imu_algorithm_config.pb.h"

namespace apollo {
namespace sensor_calibration {

class Calibrator {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    Calibrator(std::shared_ptr<LidarToIMUAlgorithmConfig> config, std::string result_path);
    ~Calibrator();

    // load data
    void LoadTimeAndPose(const std::string &odom_path, const std::string lidar_path);

    Eigen::Matrix4d GetDeltaTrans(double R[3], double t[3]);

    bool Calibration(
            Eigen::Matrix4d &refined_Tl2i,
            std::function<void(int)> progress_callback,
            std::string *error_msg,
            bool is_bp);
    bool SaveStitching(const Eigen::Matrix4d &transform, const std::string &pcd_name, std::string *error_msg);
    bool SaveResults(
            const Eigen::Matrix4d &refined_Tl2i,
            const Eigen::Matrix4d &transform,
            double time_cost[2],
            std::string *error_msg);
    void GetL2ITrans(const Eigen::Matrix4d &init_Tl2i);
    void StopCalibration();
    bool GetPCLIntensityDataType();
    std::vector<double> GetJudgeResults();

private:
    int turn_;
    int window_;
    double degree_2_radian = 0.017453293;
    double bestVal_[6] = {0};
    void ExtractPlane(
            const pcl::PointCloud<pcl::PointXYZI>::Ptr &cloud,
            pcl::PointCloud<pcl::PointXYZI>::Ptr &output,
            int index);
    std::vector<Eigen::Matrix4d, Eigen::aligned_allocator<Eigen::Matrix4d>> lidar_poses_;
    std::vector<Eigen::Matrix4d, Eigen::aligned_allocator<Eigen::Matrix4d>> lidar_poses_start_;
    std::vector<Eigen::Matrix4d, Eigen::aligned_allocator<Eigen::Matrix4d>> lidar_poses_orin_;
    std::vector<Eigen::Matrix4d, Eigen::aligned_allocator<Eigen::Matrix4d>> lidar_poses_start_orin_;
    Eigen::Matrix4d lidar2imu_extrinsic_;
    Eigen::Matrix4d deltaTrans_;
    std::shared_ptr<LidarToIMUAlgorithmConfig> config_;
    std::string result_path_;
    std::string lidar_path_;
    std::vector<std::string> lidar_files_;
    std::vector<double> judge_results_;
    std::ofstream log_;
    std::atomic<bool> stopped_{false};
    bool pcl_intensity_data_type_is_float_ = true;
};

}  // namespace sensor_calibration
}  // namespace apollo