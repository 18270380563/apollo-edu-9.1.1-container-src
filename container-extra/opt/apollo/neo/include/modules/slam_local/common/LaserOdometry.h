#ifndef LOAM_LASERODOMETRY_H
#define LOAM_LASERODOMETRY_H

#include "modules/common_msgs/transform_msgs/transform.pb.h"

#include "cyber/cyber.h"
#include "modules/transform/buffer.h"
#include "modules/transform/transform_broadcaster.h"

// #include <ros/node_handle.h>
// #include <sensor_msgs/PointCloud2.h>
// #include <nav_msgs/Odometry.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
// #include <tf/transform_datatypes.h>
// #include <tf/transform_broadcaster.h>

#include <fstream>
#include <string>
#include <vector>

#include "modules/common_msgs/localization_msgs/imu.pb.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/slam_local/proto/cloudWithPoseInfo.pb.h"
#include "modules/slam_local/proto/loam_velodyne_conf.pb.h"
#include "modules/slam_local/proto/odometry.pb.h"

#include "cyber/profiler/profiler.h"
#include "modules/slam_local/common/basicNode.h"

// #include "ros/ros.h"
// #include "tf2_ros/transform_listener.h"
// #include "tf2_ros/buffer.h"
// #include "geometry_msgs/PointStamped.h"
// #include "tf2_geometry_msgs/tf2_geometry_msgs.h"
// #include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

struct VelodynePointXYZIRT {
    PCL_ADD_POINT4D
    PCL_ADD_INTENSITY;
    uint16_t ring;
    double time;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
} EIGEN_ALIGN16;
POINT_CLOUD_REGISTER_POINT_STRUCT(
        VelodynePointXYZIRT,
        (float, x, x)(float, y, y)(float, z, z)(float, intensity, intensity)(uint16_t, ring, ring)(float, time, time))

const int queueLength = 2000;

using PointXYZIRT = VelodynePointXYZIRT;

namespace loam {

using apollo::slam_local::cloudWithPoseInfo;
using apollo::slam_local::LoamVelodyneConf;
using apollo::slam_local::Odometry;

struct cloudInfomation {
    bool imuAvailable;
    bool odomAvailable;
    float imuRollInit;
    float imuPitchInit;
    float imuYawInit;
    float initialGuessX;
    float initialGuessY;
    float initialGuessZ;
    float initialGuessRoll;
    float initialGuessPitch;
    float initialGuessYaw;
};

class ImageProjection : public ParamServer {
private:
    std::mutex imuLock;
    std::mutex odoLock;

    std::shared_ptr<apollo::cyber::Reader<apollo::drivers::PointCloud>> subLaserCloud;
    std::shared_ptr<apollo::cyber::Reader<apollo::drivers::PointCloud>> pubLaserCloud;

    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubExtractedCloud;
    std::shared_ptr<apollo::cyber::Writer<cloudWithPoseInfo>> pubLaserCloudInfo;

    std::shared_ptr<apollo::cyber::Reader<apollo::localization::CorrectedImu>> subImu;
    std::deque<apollo::localization::CorrectedImu> imuQueue;

    std::shared_ptr<apollo::cyber::Reader<Odometry>> subOdom;
    std::deque<Odometry> odomQueue;

    std::deque<apollo::drivers::PointCloud> cloudQueue;
    apollo::drivers::PointCloud currentCloudMsg;

    double *imuTime = new double[queueLength];
    double *imuRotX = new double[queueLength];
    double *imuRotY = new double[queueLength];
    double *imuRotZ = new double[queueLength];

    int imuPointerCur;
    bool firstPointFlag;
    Eigen::Affine3f transStartInverse;

    pcl::PointCloud<PointXYZIRT>::Ptr laserCloudIn;
    pcl::PointCloud<PointType>::Ptr fullCloud;

    apollo::transform::Buffer *buffer_ = apollo::transform::Buffer::Instance();

    int deskewFlag;

    bool odomDeskewFlag;
    float odomIncreX;
    float odomIncreY;
    float odomIncreZ;
    double timeScanCur;
    double timeScanEnd;
    cloudInfomation cloudInfo;
    std::shared_ptr<commonlib::CommonLib> common_lib_;

    void allocateMemory();
    void imuHandler(const std::shared_ptr<apollo::localization::CorrectedImu> &imuMsg);
    void odometryHandler(const std::shared_ptr<Odometry> &odometryMsg);
    void cloudHandler(const std::shared_ptr<apollo::drivers::PointCloud> &laserCloudMsg);
    bool cachePointCloud(const std::shared_ptr<apollo::drivers::PointCloud> &laserCloudMsg);
    bool deskewInfo();
    void imuDeskewInfo();
    void odomDeskewInfo();
    void findRotation(double pointTime, float *rotXCur, float *rotYCur, float *rotZCur);
    void findPosition(double relTime, float *posXCur, float *posYCur, float *posZCur);
    PointType deskewPoint(PointType *point, double relTime);
    void projectPointCloud();
    void resetParameters();
    void publishClouds();
    double timeLaserInfoCur = -1;

public:
    ImageProjection();
    bool setup(std::shared_ptr<LoamVelodyneConf> conf, std::shared_ptr<apollo::cyber::Node> node);
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

}  // end namespace loam

#endif  // LOAM_LASERODOMETRY_H
