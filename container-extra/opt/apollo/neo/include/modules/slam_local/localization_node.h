#pragma once
#define ACCEPT_USE_OF_DEPRECATED_PROJ_API_H
#include <proj_api.h>

#include <future>
#include <memory>

#include <GeographicLib/Geocentric.hpp>
#include <GeographicLib/LocalCartesian.hpp>
#include <gtsam/geometry/Pose3.h>
#include <gtsam/geometry/Rot3.h>
#include <gtsam/inference/Symbol.h>
#include <gtsam/navigation/CombinedImuFactor.h>
#include <gtsam/navigation/GPSFactor.h>
#include <gtsam/navigation/ImuFactor.h>
#include <gtsam/nonlinear/ISAM2.h>
#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>
#include <gtsam/nonlinear/Marginals.h>
#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/Values.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/slam/PriorFactor.h>

#include "absl/strings/str_cat.h"

#include "modules/common_msgs/localization_msgs/localization.pb.h"
#include "modules/common_msgs/sensor_msgs/gnss_best_pose.pb.h"
#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/slam_local/proto/cloudWithPoseInfo.pb.h"
#include "modules/slam_local/proto/loam_velodyne_conf.pb.h"
#include "modules/slam_local/proto/localization_status.pb.h"
#include "modules/slam_local/proto/odometry.pb.h"
#include "modules/slam_local/proto/slam_pose_result.pb.h"
#include "modules/slam_local/proto/slam_service.pb.h"

#include "cyber/cyber.h"
#include "cyber/profiler/profiler.h"
#include "modules/common/configs/config_gflags.h"
#include "modules/common/math/euler_angles_zxy.h"
#include "modules/common/math/quaternion.h"
#include "modules/slam_local/common/basicNode.h"
// #include "modules/slam_local/common/ikd_Tree.h"
#include "modules/slam_local/common/nanoflann_pcl.h"

// #include "Scancontext.h"
struct PointXYZIRPYT {
    PCL_ADD_POINT4D
    PCL_ADD_INTENSITY;  // preferred way of adding a XYZ+padding
    float roll;
    float pitch;
    float yaw;
    double time;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW  // make sure our new allocators are aligned
} EIGEN_ALIGN16;                     // enforce SSE padding for correct memory alignment

POINT_CLOUD_REGISTER_POINT_STRUCT(
        PointXYZIRPYT,
        (float, x, x)(float, y, y)(float, z, z)(float, intensity, intensity)(float, roll, roll)(float, pitch, pitch)(
                float,
                yaw,
                yaw)(double, time, time))

typedef PointXYZIRPYT PointTypePose;

enum class SCInputType { SINGLE_SCAN_FULL, SINGLE_SCAN_FEAT, MULTI_SCAN_FEAT };

struct UTMCoor {
    UTMCoor() : x(0.0), y(0.0), z(0.0) {}
    double x;
    double y;
    double z;
};

// proto struct
using apollo::slam_local::cloudWithPoseInfo;
using apollo::slam_local::LoamVelodyneConf;
using apollo::slam_local::LocalizationStatus;
using apollo::slam_local::Odometry;

using namespace gtsam;

using symbol_shorthand::B;  // Bias  (ax,ay,az,gx,gy,gz)
using symbol_shorthand::G;  // GPS pose
using symbol_shorthand::V;  // Vel   (xdot,ydot,zdot)
using symbol_shorthand::X;  // Pose3 (x,y,z,r,p,y)

namespace apollo {
namespace loam_velodyne {

class MapOptimization : public apollo::cyber::Component<>, public ParamServer {
public:
    using SlamRequest = apollo::dreamview::maptool::SlamRequest;
    using SlamResponse = apollo::dreamview::maptool::SlamResponse;
    using LidarSlamQuality = apollo::slam_local::LocalizationStatus_LidarSlamQuality;
    using LocalizationSource = apollo::slam_local::LocalizationStatus_LocalizationSource;

    bool Init() override;

    ~MapOptimization();

    bool loadPoseAndMap(std::string& filePath, int type);
    void allocateMemory();
    void transformAssociateToMap();
    void transformUpdate();
    void updatePointAssociateToMapSinCos();
    pcl::PointCloud<PointType>::Ptr transformPointCloud(
            pcl::PointCloud<PointType>::Ptr cloudIn,
            PointTypePose* transformIn);

    void laserOdometryHandler(const std::shared_ptr<Odometry>& laserOdometry);
    void laserCloudFullLastHandler(const std::shared_ptr<cloudWithPoseInfo>& surfPointsLessFlatMsg);
    void laserCloudOutlierLastHandler(const std::shared_ptr<apollo::drivers::PointCloud>& laserCloudOutlierLastMsg);
    void imuHandler(const std::shared_ptr<apollo::drivers::PointCloud>& imuIn);
    void correctImuHandler(const std::shared_ptr<apollo::localization::CorrectedImu>& imu_raw);
    void rtkOdometryHandler(const std::shared_ptr<Odometry>& odomMsg);
    void fullLaserCloudLastHandler(const std::shared_ptr<apollo::drivers::PointCloud>& msg);

    void publishTF();
    void publishKeyPosesAndFrames();
    void visualizeGlobalMapThread();
    void publishGlobalMap();
    void loopClosureThread();
    bool detectLoopClosure();
    void performLoopClosure();
    gtsam::Pose3 pclPointTogtsamPose3(PointTypePose thisPoint);
    Eigen::Affine3f pclPointToAffine3fCameraToLidar(PointTypePose thisPoint);
    bool extractSurroundingKeyFrames();
    void downsampleCurrentScan();
    void cornerOptimization(int iterCount);
    void surfOptimization(float const deltaR, float const deltaT);
    bool scan2MapOptimization();
    void calculateIcpScore(pcl::PointCloud<PointType>::Ptr cloudIn, pcl::PointCloud<PointType>::Ptr cloudOut);
    void saveKeyFramesAndFactor();
    void correctPoses();
    void clearCloud();
    void spin();
    void run();
    void pointAssociateToMap(PointType const* const pi, PointType* const po);
    void fullLaserCloudLastHandler(const std::shared_ptr<apollo::drivers::PointCloud>&& msg);

    void updateInitialGuess();
    bool updateInitialGuessFromPreInte();
    bool LMOptimization(int iterCount, float* const deltaR, float* const deltaT);

    bool extractNearby();
    bool extractCloud(pcl::PointCloud<PointType>::Ptr cloudToExtract);
    void updatePointAssociateToMap();
    bool saveFrame();
    void addOdomFactor();
    void addGPSFactor();
    void addLoopFactor();
    void publishOdometry();
    void publishLocalizationStatus(const LocalizationSource& type);
    Eigen::Affine3f trans2Affine3f(float transformIn[]);
    void performRSLoopClosure();
    void loopFindNearKeyframes(
            pcl::PointCloud<PointType>::Ptr& nearKeyframes,
            const int& key,
            const int& searchNum,
            const int& loop_index);
    float constraintTransformation(float value, float limit);
    void combineOptimizationCoeffs();
    Eigen::Affine3f pclPointToAffine3f(PointTypePose thisPoint);
    gtsam::Pose3 trans2gtsamPose(float transformIn[]);
    bool detectLoopClosureDistance(int* latestID, int* closestID);
    bool LatlonToUtmXY(double lon_rad, double lat_rad, UTMCoor* utm_xy);
    bool SaveCorrectPose(const std::string& pose_path);
    bool loadGnss2MapOffsetFile(std::string& filePath);
    bool getInitialPoseFromGnss();
    PointTypePose trans2PointTypePose(float transformIn[]);

    void updateTobeMapped();
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

private:
    std::shared_ptr<LoamVelodyneConf> config_;
    NonlinearFactorGraph gtSAMgraph;
    Values initialEstimate;
    Values optimizedEstimate;
    ISAM2* isam;
    Values isamCurrentEstimate;
    Eigen::MatrixXd poseCovariance;

    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubLaserCloudSurround = nullptr;
    std::shared_ptr<apollo::cyber::Writer<Odometry>> pubLaserOdometryGlobal;
    std::shared_ptr<apollo::cyber::Writer<Odometry>> pubLaserOdometryIncremental;
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubKeyPoses = nullptr;

    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubHistoryKeyFrames = nullptr;
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubIcpKeyFrames = nullptr;
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubRecentKeyFrames = nullptr;
    std::shared_ptr<apollo::cyber::Writer<apollo::drivers::PointCloud>> pubRecentKeyFrame = nullptr;

    std::shared_ptr<apollo::cyber::Writer<LocalizationStatus>> pubLocalizationStatus = nullptr;

    std::shared_ptr<apollo::cyber::Reader<cloudWithPoseInfo>> subCloud;
    std::shared_ptr<apollo::cyber::Reader<Odometry>> subRtkOdometry;

    std::deque<Odometry> gpsQueue;
    cloudWithPoseInfo cloudInfo_;

    std::vector<pcl::PointCloud<PointType>::Ptr> surfCloudKeyFrames;

    pcl::PointCloud<PointType>::Ptr cloudKeyPoses3D;
    pcl::PointCloud<PointTypePose>::Ptr cloudKeyPoses6D;
    pcl::PointCloud<PointType>::Ptr copy_cloudKeyPoses3D;
    pcl::PointCloud<PointTypePose>::Ptr copy_cloudKeyPoses6D;

    /// localization pose
    pcl::PointCloud<PointType>::Ptr local_cloudKeyPoses3D;
    pcl::PointCloud<PointTypePose>::Ptr local_cloudKeyPoses6D;
    pcl::PointCloud<PointType>::Ptr copy_local_cloudKeyPoses3D;
    pcl::PointCloud<PointTypePose>::Ptr copy_local_cloudKeyPoses6D;

    pcl::PointCloud<PointType>::Ptr laserCloudSurfLast_;   // surf feature set from odoOptimization
    pcl::PointCloud<PointType>::Ptr laserCloudSurfLastDS;  // downsampled surf feature set from
                                                           // odoOptimization

    pcl::PointCloud<PointType>::Ptr laserCloudOri;
    pcl::PointCloud<PointType>::Ptr coeffSel;

    std::vector<PointType> laserCloudOriSurfVec;  // surf point holder for parallel computation
    std::vector<PointType> coeffSelSurfVec;
    std::vector<bool> laserCloudOriSurfFlag;

    std::map<int, std::pair<pcl::PointCloud<PointType>, pcl::PointCloud<PointType>>> laserCloudMapContainer;
    pcl::PointCloud<PointType>::Ptr laserCloudSurfFromMap;
    pcl::PointCloud<PointType>::Ptr laserCloudSurfFromMapDS;
    pcl::PointCloud<PointType>::Ptr DsMap;

    nanoflann::KdTreeFLANN<PointType>::Ptr kdtreeSurfFromMap;

    pcl::KdTreeFLANN<PointType>::Ptr kdtreeSurroundingKeyPoses;
    pcl::KdTreeFLANN<PointType>::Ptr kdtreeHistoryKeyPoses;
    nanoflann::KdTreeFLANN<PointType>::Ptr kdtreeDSMap;

    pcl::VoxelGrid<PointType> downSizeFilterSurf;
    pcl::VoxelGrid<PointType> downSizeFilterLocalMapSurf;
    pcl::VoxelGrid<PointType> downSizeFilterICP;
    pcl::VoxelGrid<PointType> downSizeFilterSurroundingKeyPoses;

    double timeLaserInfoCur = -1;
    double lastBestGnssTime = -1;
    double lastPublishTime = -1;

    float transformTobeMapped[6];
    float initTransformTobeMapped[6];

    std::mutex mtx;
    std::mutex mtxLoopInfo;

    bool isDegenerate = false;
    cv::Mat matP;

    int laserCloudSurfFromMapDSNum = 0;
    int laserCloudSurfLastDSNum = 0;

    bool aLoopIsClosed = false;
    std::map<int, int> loopIndexContainer;  // from new to old
    std::vector<std::pair<int, int>> loopIndexQueue;
    std::vector<gtsam::Pose3> loopPoseQueue;
    // vector<gtsam::noiseModel::Diagonal::shared_ptr> loopNoiseQueue;
    std::vector<gtsam::SharedNoiseModel> loopNoiseQueue;
    // deque<std_msgs::Float64MultiArray> loopInfoVec;

    Eigen::Affine3f transPointAssociateToMap;
    Eigen::Affine3f incrementalOdometryAffineFront;
    Eigen::Affine3f incrementalOdometryAffineBack;

    GeographicLib::LocalCartesian gps_trans_;

    // scancontext loop closure
    // SCManager scManager;

    std::string processPath;
    std::string threeTracePath;
    std::string sixTracePath;
    std::string surfFilePath;
    std::string offsetFile;

    std::ofstream bestPoseFile;
    std::ofstream slamPoseFile;

    std::shared_ptr<commonlib::CommonLib> common_lib_;
    std::future<void> async_result_;
    bool newLaserCloudSurfLast = false;
    double gnss_map_offset[3];
    PointType gnssMapOffset;

    // SLAM service
    std::shared_ptr<apollo::cyber::Service<SlamRequest, SlamResponse>> service_ = nullptr;
    bool isInit_ = false;
    UTMCoor utmOffset_;
    bool isFirstScan = true;

    std::shared_ptr<Eigen::Vector3d> imu_gps_translation_;

    // slam status output
    int debug_lmoptimization_iterCount_ = 0;
    bool debug_icp_status_ = false;
    double debug_icp_score_ = 0.0;
    double debug_intensity_score_ = 0.0;
    int debug_icp_laserCloudSurfFromMapDS_size = 0;
    int debug_icp_laserCloudOri_size = 0;

    std::vector<double> debug_icp_distance_;
    std::vector<float> debug_intensity_value_;
    bool isRTKLocalResult_ = false;
    Odometry current_odomRTK_data_;
    // KD_TREE<PointType>::Ptr kdtree_ptr;
    // KD_TREE<PointType> ikdtree;
    PointType searchPtsLast;
    bool update_kdtree = false;
    std::vector<std::vector<int>> Nearest_Points;
    std::vector<std::vector<float>> pointSearchDis;
    std::vector<bool> point_selected;
};

CYBER_REGISTER_COMPONENT(MapOptimization)
}  // namespace loam_velodyne
}  // namespace apollo
