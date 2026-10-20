#pragma once

#include "modules/sensor_calibration/lidar_to_imu/utils/eigen_utils.hpp"
#include "modules/sensor_calibration/lidar_to_imu/utils/pcl_utils.h"
#include <pcl/registration/ndt.h>
#include <pcl/io/pcd_io.h>

namespace apollo {
namespace sensor_calibration {

struct OdomData {
    double timestamp;
    Eigen::Matrix4d pose;  // cur scan to first scan
};

class LiDAROdometry {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    typedef std::shared_ptr<LiDAROdometry> Ptr;

    explicit LiDAROdometry(
            double ndtResolution = 0.5,
            double ndt_step_size = 0.2,
            int ndt_max_iter = 1000,
            double downsample_size = 0.5);

    pcl::NormalDistributionsTransform<VPoint, VPoint>::Ptr ndtInit();

    void feedScan(
            double timestamp,
            VPointCloud::Ptr cur_scan,
            Eigen::Matrix4d pose_predict = Eigen::Matrix4d::Identity(),
            const bool update_map = true);

    void clearOdomData();

    void setTargetMap(VPointCloud::Ptr map_cloud_in);

    void saveTargetMap(const std::string &path, const Eigen::Matrix4d &lidartoimu_init) const;

    const VPointCloud::Ptr getTargetMap();

    const pcl::NormalDistributionsTransform<VPoint, VPoint>::Ptr &getNDTPtr() const;

    const Eigen::aligned_vector<OdomData> &get_odom_data() const;
    std::vector<std::vector<double>> get_error_pos();
    void push_back_odom(const OdomData &odomdata);
    std::vector<std::vector<double>> evaluate_total_error_pos();

private:
    void registration(
            const VPointCloud::Ptr &cur_scan,
            const Eigen::Matrix4d &pose_predict,
            Eigen::Matrix4d &pose_out,
            VPointCloud::Ptr scan_in_target);

    void updateKeyScan(const VPointCloud::Ptr &cur_scan, const OdomData &odom_data);

    bool checkKeyScan(const OdomData &odomdata);

    // Normalize angle to be between [-180, 180]
    static inline double normalize_angle(double ang_degree) {
        if (ang_degree > 180)
            ang_degree -= 360;

        if (ang_degree < -180)
            ang_degree += 360;
        return ang_degree;
    }

private:
    VPointCloud::Ptr map_cloud_;

    pcl::NormalDistributionsTransform<VPoint, VPoint>::Ptr ndt_omp_;
    double downsample_size_;
    double ndt_resolution_;
    double ndt_step_size_;
    int ndt_max_iterations_;
    std::vector<std::vector<double>> error_pos_;

    std::vector<size_t> key_frame_index_;
    Eigen::aligned_vector<OdomData> odom_data_;
    Eigen::aligned_vector<OdomData> odom_data_referenced_;
};

}  // namespace sensor_calibration
}  // namespace apollo