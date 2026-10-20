
#ifndef LOAM_MULTISCANREGISTRATION_H
#define LOAM_MULTISCANREGISTRATION_H
#define _USE_MATH_DEFINES
#include <math.h>

#include <cmath>

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

#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/common_msgs/sensor_msgs/imu.pb.h"                       // imu msg

#include "modules/loam_velodyne_indoor/proto/loam_velodyne_indoor_conf.pb.h"
#include "modules/loam_velodyne_indoor/proto/odometry.pb.h"

#include "cyber/cyber.h"
#include "modules/common/math/quaternion.h"
#include "modules/loam_velodyne_indoor/common/basicNode.h"
#include "modules/transform/buffer.h"
#include "modules/transform/transform_broadcaster.h"
namespace loam {

using apollo::loam_velodyne_indoor::LoamVelodyneIndoorConf;
using apollo::loam_velodyne_indoor::Odometry;
using gtsam::symbol_shorthand::B;  // Bias  (ax,ay,az,gx,gy,gz)
using gtsam::symbol_shorthand::V;  // Vel   (xdot,ydot,zdot)
using gtsam::symbol_shorthand::X;  // Pose3 (x,y,z,r,p,y)

class TransformFusion : public ParamServer {
public:
    std::mutex mtx;

    std::shared_ptr<apollo::cyber::Reader<Odometry>> subImuOdometry;
    std::shared_ptr<apollo::cyber::Reader<Odometry>> subLaserOdometry;

    std::shared_ptr<apollo::cyber::Writer<Odometry>> pubImuOdometry;
    // ros::Publisher pubImuPath;

    Eigen::Affine3f lidarOdomAffine;
    Eigen::Affine3f imuOdomAffineFront;
    Eigen::Affine3f imuOdomAffineBack;

    // transform from localization to imu
    std::unique_ptr<Eigen::Quaterniond> imu_localization_quat_;

    double lidarOdomTime = -1;
    std::deque<Odometry> imuOdomQueue;

    TransformFusion();
    bool setup(std::shared_ptr<LoamVelodyneIndoorConf> conf, std::shared_ptr<apollo::cyber::Node> node);
    Eigen::Affine3f odom2affine(const Odometry& odom);
    void lidarOdometryHandler(const std::shared_ptr<Odometry>& odomMsg);
    void imuOdometryHandler(const std::shared_ptr<Odometry>& odomMsg);
    bool GetLocalizationToImuTF();

    double gnss_map_offset_[3];
};

class IMUPreintegration : public ParamServer {
public:
    std::mutex mtx;

    std::shared_ptr<apollo::cyber::Reader<apollo::drivers::gnss::Imu>> subImu;
    std::shared_ptr<apollo::cyber::Reader<Odometry>> subOdometry;
    std::shared_ptr<apollo::cyber::Writer<Odometry>> pubImuOdometry;

    bool systemInitialized = false;

    gtsam::noiseModel::Diagonal::shared_ptr priorPoseNoise;
    gtsam::noiseModel::Diagonal::shared_ptr priorVelNoise;
    gtsam::noiseModel::Diagonal::shared_ptr priorBiasNoise;
    gtsam::noiseModel::Diagonal::shared_ptr correctionNoise;
    gtsam::noiseModel::Diagonal::shared_ptr correctionNoise2;
    gtsam::Vector noiseModelBetweenBias;

    gtsam::PreintegratedImuMeasurements* imuIntegratorOpt_;
    gtsam::PreintegratedImuMeasurements* imuIntegratorImu_;

    std::deque<apollo::drivers::gnss::Imu> imuQueOpt;
    std::deque<apollo::drivers::gnss::Imu> imuQueImu;

    gtsam::Pose3 prevPose_;
    gtsam::Vector3 prevVel_;
    gtsam::NavState prevState_;
    gtsam::imuBias::ConstantBias prevBias_;

    gtsam::NavState prevStateOdom;
    gtsam::imuBias::ConstantBias prevBiasOdom;

    bool doneFirstOpt = false;
    double lastImuT_imu = -1;
    double lastImuT_opt = -1;

    gtsam::ISAM2 optimizer;
    gtsam::NonlinearFactorGraph graphFactors;
    gtsam::Values graphValues;
    std::shared_ptr<commonlib::CommonLib> common_lib_;

    const double delta_t = 0;

    int key = 1;

    // T_bl: tramsform points from lidar frame to imu frame
    gtsam::Pose3 imu2Lidar = gtsam::Pose3(gtsam::Rot3(1, 0, 0, 0), gtsam::Point3(0.0, 0.0, 0.0));
    // T_lb: tramsform points from imu frame to lidar frame
    gtsam::Pose3 lidar2Imu = gtsam::Pose3(gtsam::Rot3(1, 0, 0, 0), gtsam::Point3(0.0, 0.0, 0.0));
    IMUPreintegration();
    bool setup(std::shared_ptr<LoamVelodyneIndoorConf> conf, std::shared_ptr<apollo::cyber::Node> node);
    void resetOptimization();
    void resetParams();
    void odometryHandler(const std::shared_ptr<Odometry>& odomMsg);
    bool failureDetection(const gtsam::Vector3& velCur, const gtsam::imuBias::ConstantBias& biasCur);
    void imuHandler(const std::shared_ptr<apollo::drivers::gnss::Imu>& imu_raw);
};

}  // end namespace loam

#endif  // LOAM_MULTISCANREGISTRATION_H
