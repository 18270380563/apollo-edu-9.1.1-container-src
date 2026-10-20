#pragma once
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <pcl/common/transforms.h>
#include <pcl/conversions.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/octree/octree_search.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <algorithm>
#include <numeric>
#include "yaml-cpp/yaml.h"

namespace apollo {
namespace sensor_calibration {

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

struct Quaternion {
    double x, y, z, w;
};

struct Vector3 {
    double x, y, z;
};

struct Transform {
    Quaternion rotation;
    Vector3 translation;
};

void PointCloudDownSampling(
        const pcl::PointCloud<pcl::PointXYZI>::Ptr &in_cloud,
        double voxel_size,
        pcl::PointCloud<pcl::PointXYZI>::Ptr &out_cloud);
void PointCloudFilterByROI(
        const pcl::PointCloud<pcl::PointXYZ>::Ptr &in_cloud,
        const PointCloudBbox &roi,
        pcl::PointCloud<pcl::PointXYZ>::Ptr &out_cloud);

bool GroundPlaneExtraction(
        const pcl::PointCloud<pcl::PointXYZI>::Ptr &in_cloud,
        pcl::PointCloud<pcl::PointXYZI>::Ptr g_cloud,
        pcl::PointCloud<pcl::PointXYZI>::Ptr ng_cloud,
        PlaneParam &plane);

bool GroundPlaneExtraction(const pcl::PointCloud<pcl::PointXYZI>::Ptr &in_cloud, PlaneParam &plane);

Eigen::Matrix3f ComputeRotationMatrix(Eigen::Vector4f plane);

Eigen::Vector4f ComputePointCloudCenter(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);
double EuclideanDistance(const pcl::PointXYZ &p1, const pcl::PointXYZ &p2);

int GetMaxDistanceIndice(const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud, int index);

double GetMaxDistance(const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);

Eigen::Vector3f getAxisRangeDifference(
        const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud,
        double mul_thresh,
        bool is_filter);

double ComputeNormalStdDev(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);

void FilterByHeight(
        const std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters,
        std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters_out,
        double max_height,
        double min_height);

void FilterByDistance(
        const std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters,
        std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters_out,
        double max_distance,
        double min_distance,
        double multi_std_thresh);

void FilterByNormals(
        const std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters,
        std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters_out,
        double max_std_normals);

void FilterNoise(
        const std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters,
        std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters_out,
        double multi_std_thresh);

void FilterChull(
        const std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters,
        std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters_out);
void AddRemainingPointsToClusters(size_t cloud_size, std::vector<pcl::PointIndices> &eu_cluster_indices);

void ClusterPoints(
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,
        std::vector<pcl::PointIndices> &eu_cluster_indices,
        int num_clusters,
        float max_distance);
bool ParseTransform(const std::string &file_path, Transform &transform, std::string *error_msg);

bool RemoveGroundPlane(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);

}  // namespace sensor_calibration
}  // namespace apollo