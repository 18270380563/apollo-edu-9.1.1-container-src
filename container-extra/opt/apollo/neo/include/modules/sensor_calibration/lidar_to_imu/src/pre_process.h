#pragma once
#include <vector>
#include <numeric>
#include <cmath>
#include <pcl/common/transforms.h>
#include <pcl/conversions.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/octree/octree_search.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

namespace apollo {
namespace sensor_calibration {
namespace lidar {
typedef pcl::PointXYZI PointType;
struct PlaneParam {
    PlaneParam() {}
    PlaneParam(const Eigen::Vector3d &n, double i) : normal(n), intercept(i) {}
    Eigen::Vector3d normal;
    double intercept;
};

struct PlaneParamError {
    PlaneParamError() {}
    PlaneParamError(double n, double i) : normal_error(n), intercept_error(i) {}
    double normal_error;
    double intercept_error;
};

struct PointCloudBbox {
    int min_x = 0;
    int min_y = 0;
    int min_z = 0;

    int max_x = 0;
    int max_y = 0;
    int max_z = 0;
};

void PointCloudDownSampling(
        const pcl::PointCloud<pcl::PointXYZI>::Ptr &in_cloud,
        double voxel_size,
        pcl::PointCloud<pcl::PointXYZI>::Ptr &out_cloud);
void PointCloudFilterByROI(
        const pcl::PointCloud<pcl::PointXYZI>::Ptr &in_cloud,
        const PointCloudBbox &roi,
        pcl::PointCloud<pcl::PointXYZI>::Ptr &out_cloud);

bool GroundPlaneExtraction(
        const pcl::PointCloud<pcl::PointXYZI>::Ptr &in_cloud,
        pcl::PointCloud<pcl::PointXYZI>::Ptr g_cloud,
        pcl::PointCloud<pcl::PointXYZI>::Ptr ng_cloud,
        PlaneParam &plane);

bool GroundPlaneExtraction(const pcl::PointCloud<pcl::PointXYZI>::Ptr &in_cloud, PlaneParam &plane);

double Standard_deviation(const std::queue<double> &v);

Eigen::Matrix4d LidartoLidarCalib(
        const pcl::PointCloud<pcl::PointXYZI>::Ptr &target_cloud,
        const pcl::PointCloud<pcl::PointXYZI>::Ptr &input_cloud,
        const Eigen::Matrix4d &target_to_imu,
        const Eigen::Matrix4d &input_to_imu_pred);
void SaveRGBClouds(const std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr> &clouds, const std::string &name);
void PointCloudFilterOutByROI(
        const pcl::PointCloud<pcl::PointXYZI>::Ptr &in_cloud,
        const PointCloudBbox &roi,
        pcl::PointCloud<pcl::PointXYZI>::Ptr &out_cloud);
void downsamplePointCloud(
        pcl::PointCloud<PointType>::Ptr &cloud,
        int N_SCAN,
        int downsampleRate,
        float vertical_angle_min,
        float vertical_angle_max);
template <typename PointT>
void MotionCompensation(
        const typename pcl::PointCloud<PointT>::Ptr &cloud,
        pcl::PointCloud<pcl::PointXYZI>::Ptr &cloud_compensate,
        const Eigen::Matrix<double, 4, 4> &mat_start,
        const Eigen::Matrix<double, 4, 4> &mat_end) {
    Eigen::Affine3d pose_min_time;
    pose_min_time.matrix() = mat_start;
    Eigen::Affine3d pose_max_time;
    pose_max_time.matrix() = mat_end;
    double min_timestamp = 0;
    double max_timestamp = 0;

    auto it = std::is_sorted_until(cloud->points.begin(), cloud->points.end(), [](const PointT &a, const PointT &b) {
        return a.timestamp < b.timestamp;
    });
    bool is_sorted = (it == cloud->points.end());
    if (!is_sorted) {
        auto minmax
                = std::minmax_element(cloud->points.begin(), cloud->points.end(), [](const PointT &a, const PointT &b) {
                      return a.timestamp < b.timestamp;
                  });
        min_timestamp = minmax.first->timestamp;   // 最小timestamp
        max_timestamp = minmax.second->timestamp;  // 最大timestamp
    } else {
        min_timestamp = cloud->points.front().timestamp;
        max_timestamp = cloud->points.back().timestamp;
    }

    // 预计算插值用的比例因子
    double timestamp_diff = max_timestamp - min_timestamp;
    // Convert Affine3d to Quaterniond
    Eigen::Quaterniond q_min_time(pose_min_time.rotation());
    Eigen::Quaterniond q_max_time(pose_max_time.rotation());

    // 对点云中的每一个点进行处理
    for (size_t i = 0; i < cloud->points.size(); ++i) {
        const auto &point = cloud->points[i];
        if (std::isnan(point.x)) {
            continue;
        }
        double ratio = (point.timestamp - min_timestamp) / timestamp_diff;
        // 计算当前点对应的姿态
        Eigen::Quaterniond q = q_min_time.slerp(ratio, q_max_time);
        Eigen::Affine3d pose = Eigen::Affine3d::Identity();
        pose.translate(pose_min_time.translation() * (1 - ratio) + pose_max_time.translation() * ratio);
        pose.rotate(q);

        // 将点从激光雷达坐标系变换到IMU坐标系，然后再应用IMU的姿态进行坐标变换
        Eigen::Vector3d point_in_lidar(point.x, point.y, point.z);
        Eigen::Vector3d point_compensate = pose_max_time.inverse() * pose * point_in_lidar;

        pcl::PointXYZI point_out;
        point_out.x = point_compensate.x();
        point_out.y = point_compensate.y();
        point_out.z = point_compensate.z();
        point_out.intensity = point.intensity;
        cloud_compensate->points.push_back(point_out);
        cloud_compensate->height = 1;
        cloud_compensate->width = cloud_compensate->size();
    }
}

}  // namespace lidar
}  // namespace sensor_calibration
}  // namespace apollo