
#ifndef LOAM_MULTISCANREGISTRATION_H
#define LOAM_MULTISCANREGISTRATION_H
#define ACCEPT_USE_OF_DEPRECATED_PROJ_API_H

#include <proj_api.h>

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <gtsam/geometry/Pose3.h>
#include <gtsam/geometry/Rot3.h>
#include <gtsam/inference/Symbol.h>
#include <gtsam/navigation/CombinedImuFactor.h>
#include <gtsam/navigation/GPSFactor.h>
#include <gtsam/navigation/ImuFactor.h>
#include <gtsam/nonlinear/ISAM2.h>
#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>
#include <gtsam/nonlinear/Marginals.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/Values.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/slam/PriorFactor.h>
#include <gtsam_unstable/nonlinear/IncrementalFixedLagSmoother.h>

#include "absl/strings/str_cat.h"

#include "modules/common_msgs/localization_msgs/gps.pb.h"
#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/sensor_msgs/gnss_best_pose.pb.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/common_msgs/transform_msgs/transform.pb.h"
#include "modules/slam_local/proto/loam_velodyne_conf.pb.h"
#include "modules/slam_local/proto/localization_status.pb.h"
#include "modules/slam_local/proto/odometry.pb.h"

#include "cyber/cyber.h"
#include "modules/common/math/quaternion.h"
#include "modules/slam_local/common/basicNode.h"
#include "modules/slam_local/common/mean_filter.h"
#include "modules/slam_local/common/perception_gflags.h"
#include "modules/transform/buffer.h"
#include "modules/transform/transform_broadcaster.h"

struct UTMCoor {
    UTMCoor() : x(0.0), y(0.0), z(0.0) {}
    double x;
    double y;
    double z;
};
namespace apollo {
namespace loam_velodyne {

using apollo::slam_local::LoamVelodyneConf;
using apollo::slam_local::LocalizationStatus;
using apollo::slam_local::Odometry;

using gtsam::symbol_shorthand::B;  // Bias  (ax,ay,az,gx,gy,gz)
using gtsam::symbol_shorthand::V;  // Vel   (xdot,ydot,zdot)
using gtsam::symbol_shorthand::X;  // Pose3 (x,y,z,r,p,y)

class TransformFusion : public ParamServer {
public:
    std::mutex mtx;

    std::shared_ptr<apollo::cyber::Reader<Odometry>> subImuOdometry;
    std::shared_ptr<apollo::cyber::Reader<Odometry>> subLaserOdometry;
    std::shared_ptr<apollo::cyber::Reader<Odometry>> subRtkOdometry;

    // std::shared_ptr<apollo::cyber::Writer<Odometry>> pubImuOdometry;
    std::shared_ptr<apollo::cyber::Writer<apollo::localization::LocalizationEstimate>> pubImuOdometry;
    // ros::Publisher pubImuPath;

    Eigen::Affine3f lidarOdomAffine;
    Eigen::Affine3f imuOdomAffineFront;
    Eigen::Affine3f imuOdomAffineBack;
    Eigen::Affine3f rtkOdomAffine;
    apollo::localization::LocalizationEstimate localization_result_;
    int64_t localization_seq_num_ = 0;
    std::string module_name_ = "SLAM_localization";
    double map_gnss_offset[3];

    double lidarOdomTime = -1;
    double rtkOdomTime = -1;
    std::deque<Odometry> imuOdomQueue;
    std::ofstream integratePoseFile_;

    // tools
    apollo::loam_velodyne::MeanFilter x_filter_;
    apollo::loam_velodyne::MeanFilter y_filter_;

    // transform from localization to imu
    std::unique_ptr<Eigen::Quaterniond> imu_localization_quat_;
    std::unique_ptr<Eigen::Vector3d> imu_localization_translation_;
    std::unique_ptr<apollo::transform::TransformBroadcaster> tf2_broadcaster_;

    TransformFusion();
    bool setup(
            std::shared_ptr<LoamVelodyneConf> conf,
            std::shared_ptr<apollo::cyber::Node> node,
            std::string offset_file_path);
    Eigen::Affine3f odom2affine(Odometry& odom);
    void lidarOdometryHandler(const std::shared_ptr<Odometry>& odomMsg);
    void imuOdometryHandler(const std::shared_ptr<Odometry>& odomMsg);
    void rtkOdometryHandler(const std::shared_ptr<Odometry>& odomMsg);
    bool GetLocalizationToImuTF();
    void CompensateImuLocalizationExtrinsic(apollo::localization::LocalizationEstimate* localization);
    void PublishPoseBroadcastTF(const apollo::localization::LocalizationEstimate& localization);
    bool loadGnss2MapOffsetFile(std::string& filePath);
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

class IMUPreintegration : public ParamServer {
public:
    std::mutex mtx;

    std::shared_ptr<apollo::cyber::Reader<apollo::localization::CorrectedImu>> subImu;
    std::shared_ptr<apollo::cyber::Reader<Odometry>> subOdometry;
    std::shared_ptr<apollo::cyber::Reader<apollo::drivers::gnss::GnssBestPose>> subGnssBestPoseLast;
    std::shared_ptr<apollo::cyber::Reader<LocalizationStatus>> subLocalizationStatus = nullptr;
    std::shared_ptr<apollo::cyber::Reader<apollo::localization::Gps>> subGnssOdometryLast;

    std::shared_ptr<apollo::cyber::Writer<Odometry>> pubImuOdometry;
    std::shared_ptr<apollo::cyber::Writer<Odometry>> pubRTKOdometry;

    bool systemInitialized = false;

    gtsam::noiseModel::Diagonal::shared_ptr priorPoseNoise;
    gtsam::noiseModel::Diagonal::shared_ptr priorVelNoise;
    gtsam::noiseModel::Diagonal::shared_ptr priorBiasNoise;
    gtsam::noiseModel::Diagonal::shared_ptr correctionNoise;
    gtsam::noiseModel::Diagonal::shared_ptr correctionNoise2;
    gtsam::Vector noiseModelBetweenBias;

    gtsam::PreintegratedImuMeasurements* imuIntegratorOpt_;
    gtsam::PreintegratedImuMeasurements* imuIntegratorImu_;

    std::deque<apollo::localization::CorrectedImu> imuQueOpt;
    std::deque<apollo::localization::CorrectedImu> imuQueImu;

    gtsam::Pose3 prevPose_;
    gtsam::Vector3 prevVel_;
    gtsam::NavState prevState_;
    gtsam::imuBias::ConstantBias prevBias_;

    gtsam::NavState prevStateOdom;
    gtsam::imuBias::ConstantBias prevBiasOdom;

    bool doneFirstOpt_ = false;
    double lastImuT_imu = -1;
    double lastImuT_opt = -1;

    gtsam::ISAM2 optimizer;
    gtsam::NonlinearFactorGraph graphFactors;
    gtsam::Values graphValues;
    std::shared_ptr<commonlib::CommonLib> common_lib_;
    Odometry rtk_measure_data_;
    Odometry slam_measure_data_;
    Odometry rtk_odom_measure_data_;
    double lastCorrectPoseTime = -1.0;

    const double delta_t = 0.0;
    double lastSLAMTime_ = 0;
    bool isHasRTKResult_ = false;
double timeLaserInfoCur = 0;

    int key = 1;
    Odometry odometry_;
    LocalizationStatus localizationstatus_;
    apollo::localization::CorrectedImu currentImu_;
    std::shared_ptr<Eigen::Vector3d> imu_gps_translation_;
    UTMCoor utmOffset_;
    std::ofstream bestPoseFile_;
    std::ofstream incrementPoseFile_;
    std::ofstream correctPoseFile_;

    float log_rtk_heading_value_ = 0.0;

    // T_bl: tramsform points from lidar frame to imu frame
    gtsam::Pose3 imu2Lidar = gtsam::Pose3(gtsam::Rot3(1, 0, 0, 0), gtsam::Point3(0.0, 0.0, 0.0));
    // T_lb: tramsform points from imu frame to lidar frame
    gtsam::Pose3 lidar2Imu = gtsam::Pose3(gtsam::Rot3(1, 0, 0, 0), gtsam::Point3(0.0, 0.0, 0.0));
    IMUPreintegration();
    ~IMUPreintegration();
    bool setup(
            std::shared_ptr<LoamVelodyneConf> conf,
            std::shared_ptr<apollo::cyber::Node> node,
            std::string offset_file_path);
    void resetOptimization();
    void resetParams();

    void odometryHandler(const std::shared_ptr<Odometry>& odomMsg);
    void localizationStatusHandler(const std::shared_ptr<LocalizationStatus>& localization_status);
    void gnssOdometryHandler(const std::shared_ptr<apollo::localization::Gps>& gnssOdometryMsg);
    void imuHandler(const std::shared_ptr<apollo::localization::CorrectedImu>& imu_raw);
    void gnssBestPoseHandler(const std::shared_ptr<apollo::drivers::gnss::GnssBestPose>& gnssBestPoseMsg);

    bool loadGnss2MapOffsetFile(std::string& filePath);
    void correctPosesWithMeasureData(Odometry& measureData);
    bool failureDetection(const gtsam::Vector3& velCur, const gtsam::imuBias::ConstantBias& biasCur);
    bool LatlonToUtmXY(double lon_rad, double lat_rad, UTMCoor* utm_xy);
};

}  // namespace loam_velodyne
}  // namespace apollo

#endif  // LOAM_MULTISCANREGISTRATION_H
