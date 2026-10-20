#pragma once
#include <ctime>
#include <fstream>
#include <sstream>

#include <ceres/ceres.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <pcl/filters/extract_indices.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/search/kdtree.h>
#include <pcl/segmentation/extract_clusters.h>

#include "modules/sensor_calibration/proto/lidar_to_camera_algorithm_config.pb.h"
#include "modules/sensor_calibration/proto/lidar_to_camera_calibration_config.pb.h"
#include "modules/sensor_calibration/lidar_to_camera/src/common/pre_process.h"

namespace apollo {
namespace sensor_calibration {

class LidarDetector {
public:
    LidarDetector(std::shared_ptr<LidarToCameraAlgorithmConfig> conf) : conf_(conf) {};
    ~LidarDetector() {};

    struct SegPlanePara {
        double normal_radius_search = 0.2;
        int max_iterations = 2000;
        double distance_threshold = 0.1;
        double normal_distance_weight = 0.2;
        double eps_angle = 100;
        int min_plane_size = 0;
        bool set_negative = false;  // false获取平面，true，减去平面
    };

    struct SegPlaneInput {
        SegPlaneInput(pcl::PointCloud<pcl::PointXYZ>::Ptr plane) {
            cloud = plane;
        }
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
        SegPlanePara para;
    };

    struct SegPlaneOutput {
        SegPlaneOutput() {
            coefficients = pcl::ModelCoefficients::Ptr(new pcl::ModelCoefficients);
            cloud = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
            inliers = pcl::PointIndices::Ptr(new pcl::PointIndices);
        }
        pcl::PointIndices::Ptr inliers;
        pcl::ModelCoefficients::Ptr coefficients;
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    };
    bool ExtractRectangleCorners(
            const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud,
            pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud_out,
            float rectangle_width,
            float rectangle_height);

    bool GetCornerPos(
            const std::string &lidar_path,
            std::string *error_msg,
            pcl::PointCloud<pcl::PointXYZ>::Ptr &CornerPos);

    bool LoadFolderDataPath(
            const std::string &folder_path,
            std::vector<std::string> &sub_folder_path,
            std::string *error_msg);
    bool Init(std::shared_ptr<LidarToCameraCalibrationConfig> conf, std::string *error_msg);

    std::string GetLogPath();

private:
    bool SegmentPlane(const SegPlaneInput &seg_input, SegPlaneOutput &seg_output);
    bool SegmentPlane(
            const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud,
            pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud_plane);
    void SortPos(const pcl::PointCloud<pcl::PointXYZ>::Ptr &points, pcl::PointCloud<pcl::PointXYZ>::Ptr &points_out);
    bool ExtractPlane(
            const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud,
            pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud_plane);
    bool ExtractClusterFinal(
            const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud,
            pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud_plane);
    void SaveRGBCloudIndices(
            const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud,
            const std::vector<pcl::PointIndices> &indices,
            const std::string &name);
    void GetCloudIndices(
            const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud,
            const std::vector<pcl::PointIndices> &indices,
            pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud_out);
    void SaveRGBClouds(const std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clouds, const std::string &name);
    void SegmentPlanes(
            const std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters,
            std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> &clusters_out,
            const SegPlanePara &para);
    bool FilterByShape(
            const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud,
            double max_thickness,
            double min_longitude_distance);
    float average_x = 0.0;
    float a_final;
    float b_final;
    float c_final;
    std::string log_path_;
    double pattern_length_;
    double pattern_width_;
    double pre_rotation_angle_;
    int lidar_beam_num_;
    std::shared_ptr<LidarToCameraAlgorithmConfig> conf_;
    Transform lidar_to_imu_transform_;
};

struct RotatedRectangleCostFunctor {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    pcl::PointCloud<pcl::PointXYZ>::Ptr rotated_rectangle;
    float rectangle_width;
    float rectangle_height;
    float center_x;
    float center_y;

    RotatedRectangleCostFunctor(
            pcl::PointCloud<pcl::PointXYZ>::Ptr input_cloud,
            pcl::PointCloud<pcl::PointXYZ>::Ptr input_rotated_rectangle,
            float input_rectangle_width,
            float input_rectangle_height,
            float input_center_x,
            float input_center_y) :
            cloud(input_cloud),
            rotated_rectangle(input_rotated_rectangle),
            rectangle_width(input_rectangle_width),
            rectangle_height(input_rectangle_height),
            center_x(input_center_x),
            center_y(input_center_y) {}

    template <typename T>
    bool operator()(const T *const offset_x, const T *const offset_y, const T *const angle, T *residual) const {
        // 应用偏移和旋转
        T current_center_x = T(center_x) + *offset_x / T(1000.0);
        T current_center_y = T(center_y) + *offset_y / T(1000.0);
        T cos_angle = ceres::cos(*angle * T(M_PI) / T(180.0));
        T sin_angle = ceres::sin(*angle * T(M_PI) / T(180.0));
        T points_inside = T(0);
        T total_weight = T(0);
        T total_distance = T(0);
        for (const auto &point : cloud->points) {
            T rotated_point_x
                    = cos_angle * (T(point.y) - current_center_x) + sin_angle * (T(point.z) - current_center_y);
            T rotated_point_y
                    = -sin_angle * (T(point.y) - current_center_x) + cos_angle * (T(point.z) - current_center_y);

            if (rotated_point_x >= T(-rectangle_width) / T(2) && rotated_point_x <= T(rectangle_width) / T(2)
                && rotated_point_y >= T(-rectangle_height) / T(2) && rotated_point_y <= T(rectangle_height) / T(2)) {
                points_inside += T(1.0);
                T distance_x = std::min(
                        ceres::abs(rotated_point_x - T(-rectangle_width) / T(2)),
                        ceres::abs(rotated_point_x - T(rectangle_width) / T(2)));
                T distance_y = std::min(
                        ceres::abs(rotated_point_y - T(-rectangle_height) / T(2)),
                        ceres::abs(rotated_point_y - T(rectangle_height) / T(2)));
                T distance = std::min(distance_x, distance_y) * std::min(distance_x, distance_y);
                T weight = ceres::exp(-distance / T(rectangle_width));
                total_weight += weight;
            } else {
                // 计算点到最近边的距离
                // T distance_x = std::min(ceres::abs(rotated_point_x -
                // T(-rectangle_width) / T(2)),
                //                           ceres::abs(rotated_point_x -
                //                           T(rectangle_width) / T(2)));
                // T distance_y = std::min(ceres::abs(rotated_point_y -
                // T(-rectangle_height) / T(2)),
                //                           ceres::abs(rotated_point_y -
                //                           T(rectangle_height) / T(2)));
                // T distance = std::max(distance_x, distance_y) * std::max(distance_x,
                // distance_y);

                T distance_x = T(0);
                T distance_y = T(0);

                if (rotated_point_x < T(-rectangle_width) / T(2) || rotated_point_x > T(rectangle_width) / T(2)) {
                    distance_x = std::min(
                            ceres::abs(rotated_point_x - T(-rectangle_width) / T(2)),
                            ceres::abs(rotated_point_x - T(rectangle_width) / T(2)));
                }
                if (rotated_point_y < T(-rectangle_height) / T(2) || rotated_point_y > T(rectangle_height) / T(2)) {
                    distance_y = std::min(
                            ceres::abs(rotated_point_y - T(-rectangle_height) / T(2)),
                            ceres::abs(rotated_point_y - T(rectangle_height) / T(2)));
                }
                T distance = std::max(distance_x, distance_y) * std::max(distance_x, distance_y);
                // 累加距离
                total_distance += distance;
            }
        }

        // 将 points_inside 的负值作为残差
        *residual = T(total_distance);
        return true;
    }
};

class LoggingCallback : public ceres::IterationCallback {
public:
    LoggingCallback(std::ofstream *file, double *x, double *y, double *angle) :
            file_(file), x_(x), y_(y), angle_(angle) {}

    virtual ceres::CallbackReturnType operator()(const ceres::IterationSummary &summary) {
        // 将每次迭代的x，y，angle，loss和gradient_norm写入文件
        *file_ << *x_ << "," << *y_ << "," << *angle_ << "," << summary.cost << "," << summary.gradient_norm << "\n";

        return ceres::SOLVER_CONTINUE;
    }

private:
    std::ofstream *file_;
    double *x_;
    double *y_;
    double *angle_;
};

}  // namespace sensor_calibration
}  // namespace apollo